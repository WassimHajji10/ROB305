#pragma once
#include "Looper.h"
#include "Calibrator.h"

class CpuLoop : public Looper
{
public:
    CpuLoop(Calibrator& calibrator);
    void runTime(double duration_ms);
private:
    Calibrator& calibrator;
};