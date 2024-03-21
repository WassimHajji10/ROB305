#include <iostream>
#include "Looper.h"

Looper::Looper() 
{
    doStop = false;
    iLoop = 0;
}
Looper::~Looper() 
{

}

void Looper::runLoop(double nLoops) 
{
    while(iLoop<nLoops && doStop== false)
    {
        iLoop+=1;
    }
}

double Looper::getSample() 
{
    return iLoop;
}

double Looper::stopLoop() 
{
    doStop = true;
    return getSample();
}