
#include "CpuLoop.h"
#include<iostream>

CpuLoop::CpuLoop(Calibrator& calibrator) : calibrator(calibrator)
{
    
}

void CpuLoop::runTime(double duration_ms) 
{
    runLoop(calibrator.nLoops(duration_ms));
}