
#include <iostream>
#include <pthread.h>
#include "PosixThread.h"
#include"Thread.h"
#include"TimeSpec.h"

Thread::Thread()
{

}

Thread::~Thread()
{

}

bool Thread::start()
{
    if(!start_flag)
    {
        start_time = timespec_now();
        PosixThread::start(call_run, (void*) this);
        start_flag = true;
    }
    return start_flag;
}

void Thread::sleep_ms(double delay_ms)
{
    timespec time_wait;
    time_wait = timespec_from_ms(delay_ms);
    timespec_wait( time_wait);
}

double Thread::startTime_ms()
{
    return timespec_to_ms(start_time);
}

double Thread::stopTime_ms()
{
    return timespec_to_ms(stop_time);
}

double Thread::execTime_ms()
{
    stop_time = timespec_now();
    return timespec_to_ms(stop_time - start_time);
}

void* Thread::call_run(void* thread_v)
{
    Thread* thread = (Thread*) thread_v;
    thread->run();
    return (void*) thread;
}