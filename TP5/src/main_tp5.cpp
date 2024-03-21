#include <sched.h>
#include "Mutex.h"
#include <time.h>
#include "TimeSpec.h"
#include <signal.h>
#include <pthread.h>
#include "Calibrator.h"
#include "CpuLoop.h"
#include "ThreadCpuLoop.h"
#include <iostream>
using namespace std;


int main()
{   
	cpu_set_t  cpuset;
	CPU_ZERO(&cpuset);
	CPU_SET(0, &cpuset);
	sched_setaffinity(0, sizeof(cpu_set_t), &cpuset);

	Calibrator calib = Calibrator(100.0, 4);
	CpuLoop cpulA = CpuLoop(calib);
	CpuLoop cpulB = CpuLoop(calib);
	CpuLoop cpulC = CpuLoop(calib);

	Mutex mutex = Mutex(true);
	ThreadCpuLoop A = ThreadCpuLoop(mutex, cpulA, 40, 60, 30, 10, 10);
	ThreadCpuLoop B = ThreadCpuLoop(mutex, cpulB, 10, 70, 30);
	ThreadCpuLoop C = ThreadCpuLoop(mutex, cpulC, 50, 110, 0, 20, 20);

    //main has the max priority
	struct sched_param schedParam;
	schedParam.sched_priority = sched_get_priority_max(SCHED_RR);
	pthread_setschedparam(pthread_self(), SCHED_RR, &schedParam);
	
    
	A.setScheduling(SCHED_RR, 5);
	B.setScheduling(SCHED_RR, 4);
	C.setScheduling(SCHED_RR, 3);

	A.start();
	B.start();
	C.start();

	A.join();
	B.join();
	C.join();

	cout << "Clock ticks for A =  : " << A.execTime_ms() * CLOCKS_PER_SEC * 1e-3 << endl;
	cout << "Clock ticks for B =  : " << B.execTime_ms() * CLOCKS_PER_SEC * 1e-3 << endl;
	cout << "Clock ticks for C =  : " << C.execTime_ms() * CLOCKS_PER_SEC * 1e-3 << endl;


	return 0;
}