#include "Chrono.h"
#include "TimeSpec.h"

Chrono::Chrono()
{
    myStartTime = timespec_now();
}
Chrono::~Chrono() {}
void Chrono::stop()
{
    myStopTime = timespec_now();
}

void Chrono::restart()
{
    myStartTime = timespec_now();
    myStopTime = timespec_now();
}

bool Chrono::isActive()
{
    return myStartTime == myStopTime;
}

double Chrono::startTime()
{
    return timespec_to_ms(myStartTime);
}

double Chrono::stopTime()
{
    return timespec_to_ms(myStopTime);
}

double Chrono::lap()
{
    double lasting = 0.0;
    if (isActive())
    {
        lasting = timespec_to_ms(timespec_now())-startTime();
    }
    else lasting = stopTime() - startTime();
    return lasting;
}