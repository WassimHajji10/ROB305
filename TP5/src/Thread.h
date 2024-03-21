#include <pthread.h>
#include <exception>
#include "PosixThread.h"



class Thread : public PosixThread
{
public:
    Thread();
    ~Thread();

    bool start();
    void sleep_ms(double delay_ms);
    double startTime_ms();
    double stopTime_ms();
    double execTime_ms();

protected:
    virtual void run() = 0;

private:
    static void * call_run(void* thread_v);
    bool start_flag = false;
    timespec start_time,stop_time;
};
