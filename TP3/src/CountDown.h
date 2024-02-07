#pragma once
#include"PeriodicTimer.h"

class CountDown:public PeriodicTimer
{
private:
    int counter;
public:
    CountDown(int number);

    int getCount();

protected:
    void callback();
    
};


