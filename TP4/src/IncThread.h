
#include"Thread.h"
#include"Mutex.h"
struct Data 
{
    unsigned int nLoops;
    double pCounter;
};

class IncrThread : public Thread 
{
public:
    IncrThread(Data* data) : Thread(), data(data) {
        this->data->nLoops = data->nLoops;
        this->data->pCounter = data->pCounter;
    }

    ~IncrThread() 
    {

    }

    void run() override 
    {
        for (unsigned int i = 0; i < data->nLoops; i++) 
        {
            data->pCounter += 1.0;
        }
    }

public:
    Data* data;
};


class IncrThreadWithMutex: public IncrThread
{
public:
    Mutex* mutex;
    IncrThreadWithMutex(Data* data,Mutex* m): IncrThread(data),mutex(m)
    {
        this->data->nLoops = data->nLoops;
        this->data->pCounter = data->pCounter;
        this->mutex = m;
    }
    ~IncrThreadWithMutex()
    {

    }
    
    void run() override
    {
        for(unsigned int i=0; i < data->nLoops; i++)
        {

        Mutex::Lock lock = Mutex::Lock(*mutex);
        data->pCounter += 1.0;
        lock.~Lock();
        }
    }   
};
