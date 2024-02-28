#include <iostream>
#include "SemaPhore.h"
#include <vector>

int main(int argc, char* argv[]) 
{
    unsigned int nProd = std::stoi(argv[1]);
    unsigned int nCons = std::stoi(argv[2]);
    unsigned int maxCount = 10000;
    unsigned int Tokens = 0;

    Semaphore semaphore;
    std::vector<SemaphoreProducer*> semaphoreProducers;
    std::vector<SemaphoreConsumer*> semaphoreConsumers;

    for(unsigned int i=0; i < nProd; ++i) 
    {
        semaphoreProducers.push_back(new SemaphoreProducer(&semaphore, maxCount));
    }

    for(unsigned int i=0; i < nProd; ++i) 
    {
        semaphoreProducers[i]->start();
    }

    for(unsigned int i=0; i < nProd; ++i) 
    {
        semaphoreProducers[i]->join();
        Tokens += semaphoreProducers[i]->getCounter();
    }

    std::cout<<"Semaphore Producer tokens: "<<Tokens<<std::endl;

    for(unsigned int i=0; i < nCons; ++i) 
    {
        semaphoreConsumers.push_back(new SemaphoreConsumer(&semaphore, maxCount));
    }

    for(unsigned int i=0; i < nCons; ++i) 
    {
        semaphoreConsumers[i]->start();
    }

    for(unsigned int i=0; i < nCons; ++i) 
    {
        semaphoreConsumers[i]->join();
        Tokens -= semaphoreConsumers[i]->getCounter();
    }

    std::cout<<"Semaphore Consumer tokens: "<<Tokens<<std::endl;

    return 0;
}