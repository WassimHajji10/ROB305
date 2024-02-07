

#include"TimeSpec.h"
#include<time.h>
#include <math.h>
#include <cerrno>
#include<iostream>


double timespec_to_ms(const timespec& time_ts)
{
    return time_ts.tv_sec * 1e+3 +time_ts.tv_nsec*1e-6; 
}

timespec timespec_from_ms(double time_ms)
{
    timespec time_spec;
    time_spec.tv_sec = time_ms / 1e3; 
    time_spec.tv_nsec = (time_ms- time_spec.tv_sec * 1e3) * 1e6; 
    return time_spec;
}

timespec timespec_now()
{
    struct timespec now;
    clock_gettime(CLOCK_REALTIME, &now);                            
    return now;
}


timespec timespec_negate(const timespec& time_ts)
{
    timespec time_negative;                                       
    time_negative.tv_sec = -(time_ts.tv_sec + 1);                      
    time_negative.tv_nsec = 1e9 - time_ts.tv_nsec;
    return time_negative;
}

timespec timespec_add(const timespec& time1_ts, const timespec& time2_ts)
{
    timespec time_sum;                                       
    time_sum.tv_sec = time1_ts.tv_sec + time2_ts.tv_sec;            
    if(time1_ts.tv_nsec + time2_ts.tv_nsec >= 1e9)
    {                 
        time_sum.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec - 1e9;
    }
    else
    {
        time_sum.tv_nsec = time1_ts.tv_nsec + time2_ts.tv_nsec;
    }
    return time_sum;
}

timespec timespec_subtract(const timespec& time1_ts, const timespec& time2_ts){

    timespec time_subtract;
    time_subtract.tv_sec = time1_ts.tv_sec - time2_ts.tv_sec;            
    if(time1_ts.tv_nsec - time2_ts.tv_nsec < 0)                     
    {
        time_subtract.tv_sec -= 1;
        time_subtract.tv_nsec =  1e9 - abs(time1_ts.tv_nsec - time2_ts.tv_nsec);
    }
    else
    {
        time_subtract.tv_nsec = time1_ts.tv_nsec - time2_ts.tv_nsec;
    }
    return time_subtract;
}

struct timespec timespec_wait(const struct timespec& delay_ts) 
{
    timespec time_rest;                                      
    if(nanosleep(&delay_ts, &time_rest) == -1)                      
    {
        if(errno == EINTR)
        {
            timespec_wait(time_rest);
        }
    }
    return time_rest;
}

timespec  operator- (const timespec& time_ts)                       
{
    return timespec_negate(time_ts);
}

timespec  operator+ (const timespec& time1_ts, const timespec& time2_ts)    
{
    return timespec_add(time1_ts, time2_ts);
}

timespec  operator- (const timespec& time1_ts, const timespec& time2_ts)    
{
    return timespec_subtract(time1_ts, time2_ts);
}

timespec& operator+= (timespec& time_ts, const timespec& delay_ts)          
{
    time_ts = timespec_add(time_ts, delay_ts);
    return time_ts;
}

timespec& operator-= (timespec& time_ts, const timespec& delay_ts)          
{
    time_ts = timespec_subtract(time_ts, delay_ts); 
    return time_ts;
}

bool operator== (const timespec& time1_ts, const timespec& time2_ts)        
{
    return (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec == time2_ts.tv_nsec);
}

bool operator!= (const timespec& time1_ts, const timespec& time2_ts)        
{
    return (time1_ts.tv_sec != time2_ts.tv_sec || time1_ts.tv_nsec != time2_ts.tv_nsec);
}

bool operator< (const timespec& time1_ts, const timespec& time2_ts)          
{
    return (time1_ts.tv_sec < time2_ts.tv_sec || (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec < time2_ts.tv_nsec));
}

bool operator> (const timespec& time1_ts, const timespec& time2_ts)          
{
    return (time1_ts.tv_sec > time2_ts.tv_sec || (time1_ts.tv_sec == time2_ts.tv_sec && time1_ts.tv_nsec > time2_ts.tv_nsec));
}