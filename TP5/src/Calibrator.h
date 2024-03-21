#pragma once
#include <vector>
#include"Looper.h"
#include "PeriodicTimer.h"


class Calibrator : public PeriodicTimer
{
public:
    Calibrator(double samplingPeriod_ms, unsigned nSamples);
    ~Calibrator();
    double nLoops(double duration_ms);

protected:
    void callback();

private:
    double a,b;
    std::vector<double> samples;
    Looper looper;
    unsigned int nSamples;
};