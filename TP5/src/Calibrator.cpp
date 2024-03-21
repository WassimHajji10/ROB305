#include<iostream>
#include "Calibrator.h"

Calibrator::Calibrator(double samplingPeriod_ms, unsigned int nSamples)
{
    double intercept = 0.0, slope = 0.0;

    double mean_x = 0.0, mean_y = 0.0;

    double cross_product_sum = 0.0, squared_x_sum = 0.0;

    this->nSamples = nSamples;
    start(samplingPeriod_ms);
    looper.runLoop();
    stop();

    for (unsigned int i = 0; i < nSamples; i++)
    {
        std::cout << i + 1 << " sample" << std::endl;
        mean_x += (i + 1) * samplingPeriod_ms;
        mean_y += samples[i];
        cross_product_sum += (i + 1) * samplingPeriod_ms * samples[i];
        squared_x_sum += (i + 1) * (i + 1) * samplingPeriod_ms * samplingPeriod_ms;
    }
    mean_x /= nSamples;
    mean_y /= nSamples;
    slope = (cross_product_sum - nSamples * mean_x * mean_y) / (squared_x_sum - nSamples * mean_x * mean_x);
    intercept = mean_y - slope * mean_x;

    std::cout << "Slope : " << slope << std::endl;
    std::cout << "Intercept : " << intercept << std::endl;
}
Calibrator::~Calibrator() 
{

}

double Calibrator::nLoops(double duration_ms) 
{
    double l = a*duration_ms + b;
    return l;
}

void Calibrator::callback() 
{
    double samples_ = looper.getSample();
    samples.push_back(samples_);
    if(samples.size()==nSamples)
    {
        looper.stopLoop();
    }
}

