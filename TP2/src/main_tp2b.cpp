#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <pthread.h>
#include"TimeSpec.h"

using namespace std;

pthread_mutex_t mutex; 

void incr(unsigned int nLoops, double* pCounter, bool useMutex)
{ 
    for (unsigned int i = 0; i < nLoops; i++)
    {
        if (useMutex) 
        {
            pthread_mutex_lock(&mutex); 
            *pCounter += 1.0;
            pthread_mutex_unlock(&mutex);  
        } 
        else 
        {
            *pCounter += 1.0;
        }
    }
}

//We add useMutex to the Data struct to indicate to the program when we use the lock on counter
struct Data 
{
    unsigned int nLoops;
    double counter;
    bool useMutex;
};

void *call_incr(void *v_data)
{
    Data *p_data = (Data *)v_data;
    incr(p_data->nLoops, &p_data->counter,p_data->useMutex); 
    return v_data;
}

int main(int argc, char *argv[])
{
    unsigned int nLoops = stoi(argv[1]);
    unsigned int nTasks = stoi(argv[2]);
    bool useMutex = stoi(argv[3]);
   
    Data data{nLoops, 0.0,useMutex};

    if (useMutex) 
    {
        pthread_mutex_init(&mutex, nullptr);     
    }

    std::vector<pthread_t> incrementThread(nTasks);
    struct timespec start;
    start=timespec_now();

    for (auto &thid : incrementThread)
    {
        pthread_create(&thid, nullptr, call_incr, &data);
    }

    for (auto &thid : incrementThread)
    {
        pthread_join(thid, nullptr);
    }

    if (useMutex) 
    {
        pthread_mutex_destroy(&mutex); 
    }

    struct timespec end;
    end=timespec_now();
    std::cout << "Counter : " << data.counter << std::endl;
    
    std::cout << "Time in s : " << timespec_to_ms(end-start)/1000 << std::endl;
    return 0;
}