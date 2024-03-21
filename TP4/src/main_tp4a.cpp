#include <iostream>
#include "Chrono.h"
#include "PosixThread.h"
#include "IncThread.h"
#include <vector>

int main(int argc, char* argv[]) 
{
    unsigned int nLoops = std::stoi(argv[1]);
    unsigned int nTasks = std::stoi(argv[2]);

    Data data = {nLoops, 0.0};

    double execTime = 0;
    std::vector<IncrThread*> incrThreads;

    Chrono chrono;

    for (unsigned int i = 0; i < nTasks; i++) 
    {
        incrThreads.push_back(new IncrThread(&data));
    }

    for (unsigned int i = 0; i < nTasks; i++) 
    {
        incrThreads[i]->start();
        execTime += incrThreads[i]->execTime_ms();
    }

    for (unsigned int i = 0; i < nTasks; i++) 
    {
        incrThreads[i]->join();
    }

    chrono.stop();
    std::cout << "The value of the counter is : " << incrThreads[0]->data->pCounter << std::endl;
    std::cout << "The execution time in ms " << chrono.lap() << std::endl;

    
    

    return 0;
}