
#include"Timer.h"
#include"TimeSpec.h"
#include<time.h>

Timer::Timer()
{
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = call_callback;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, nullptr);
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = this;
    timer_create(CLOCK_REALTIME, &sev, &timer_id);
}

Timer::~Timer()
{
    timer_delete(timer_id);
}

void Timer::start(double duration_ms)
{
    itimerspec its;
    its.it_value=timespec_from_ms(duration_ms);
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;
    timer_settime(timer_id, 0, &its, nullptr);
}

void Timer::stop()
{
    itimerspec its;
    its.it_value.tv_sec=0;
    its.it_value.tv_nsec=0;
    its.it_interval.tv_sec = 0;
    its.it_interval.tv_nsec = 0;
    timer_settime(timer_id, 0, &its, nullptr);
}

void Timer::call_callback(int ,siginfo_t*si,void*)
{
    Timer* timer = (Timer*) si->si_value.sival_ptr;
    timer->callback();
}