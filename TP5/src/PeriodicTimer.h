#pragma once
#include"Timer.h"
#include <time.h>

class PeriodicTimer:public Timer
{
public:

    void start(double duration_ms);
};
