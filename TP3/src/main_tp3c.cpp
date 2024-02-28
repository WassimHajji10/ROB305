#include "Looper.h"
#include <iostream>
#include"Calibrator.h"
#include"CpuLoop.h"

int main()
{
    Calibrator calibrator = Calibrator(1000, 10);
    CpuLoop cpuLoop = CpuLoop(calibrator);
    cpuLoop.runTime(2000);
    std::cout<< "Loop value :"<<cpuLoop.getSample()<<std::endl;
    std::cout<< "Estimated value :"<<calibrator.nLoops(2000)<<std::endl;
    return 0;
}