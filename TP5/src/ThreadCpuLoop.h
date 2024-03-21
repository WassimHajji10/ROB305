#include"Thread.h"
#include "Mutex.h"
#include "CpuLoop.h"
#include "Calibrator.h"

class ThreadCpuLoop: public Thread
{
private:
    Mutex& mutex;
	double duration;
	double delay;
	double beginning;
	double access_try;
	double access_free;
    
public:
    ThreadCpuLoop(Mutex& mutex, CpuLoop& cpul, double tick_duration, double tick_delay, double tick_beginning, double tick_access_try = -1, double tick_access_free = -1);
    ~ThreadCpuLoop();
    CpuLoop& cpul;
	bool start();
	bool delay_respected();
    void run();
};

