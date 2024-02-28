

#include <time.h>

class Chrono
{
private:
    timespec myStartTime;
    timespec myStopTime;

public:
    Chrono();
    ~Chrono();
    void stop();
    void restart();
    bool isActive();
    double startTime();
    double stopTime();
    double lap();
};