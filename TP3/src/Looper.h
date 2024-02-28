#pragma once
#include "Timer.h"


class Looper {
public:
    Looper();
    ~Looper();
    void runLoop(double nLoops = __DBL_MAX__);
    double getSample();
    double stopLoop();
private:
    bool doStop;
    double iLoop;
};



