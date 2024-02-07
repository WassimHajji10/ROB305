#pragma once
#include<time.h>
#include<signal.h>

class Timer
{
protected:
    timer_t timer_id;
public:
    Timer();
    virtual ~Timer();

    virtual void start(double duration_ms);

    void stop();


protected:
    virtual void callback()=0;


private:
    static void call_callback(int,siginfo_t* si,void*);
};

