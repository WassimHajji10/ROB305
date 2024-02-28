#include <iostream>
#include "PosixThread.h"
#include "Mutex.h"
#include "Chrono.h"
#include "IncThread.h"
#include <vector>

int main(int argc, char* argv[]) 
{
    unsigned int nLoops = std::stoi(argv[1]);
    unsigned int nTasks = std::stoi(argv[2]);
    Data data = {nLoops, 0.0};

    Mutex mutex;
    std::vector<IncrThreadWithMutex*> incrThreads;

    Chrono chrono;

    for (unsigned int i = 0; i < nTasks; ++i) 
    {
        incrThreads.push_back(new IncrThreadWithMutex(&data, &mutex));
    }

    for (unsigned int i = 0; i < nTasks; ++i) 
    {
        incrThreads[i]->start();
    }

    for (unsigned int i = 0; i < nTasks; ++i) 
    {
        incrThreads[i]->join();
    }

    chrono.stop();
    std::cout << "The value of the counter is : " << incrThreads[0]->data->pCounter << std::endl;
    std::cout << "The execution time in ms " << chrono.lap() << std::endl;

    

    return 0;
}