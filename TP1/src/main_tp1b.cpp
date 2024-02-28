#include <time.h>
#include <signal.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

void myHandler(int, siginfo_t* si, void*);

int main()
{
    volatile int counter = 0;

    
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;  
    sa.sa_sigaction = myHandler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, NULL);

    
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    sev.sigev_value.sival_ptr = (void*) &counter;

    timer_t tid;
    timer_create(CLOCK_REALTIME, &sev, &tid);

  
    struct itimerspec its;
    its.it_value.tv_sec = 0; 
    its.it_value.tv_nsec = 5e8;
    its.it_interval.tv_sec = 0;  
    its.it_interval.tv_nsec = 5e8;

    timer_settime(tid, 0, &its, NULL);

    while(counter < 15)
        continue;

   
    timer_delete(tid);
    return 0;
}


void myHandler(int, siginfo_t* si, void*)
{
    int* p_counter = (int*)si->si_value.sival_ptr;
    *p_counter += 1;
    std::cout <<*p_counter << std::endl;
}