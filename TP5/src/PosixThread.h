#pragma once
#include <pthread.h>
#include <exception>

using namespace std;
class PosixThread
{
public:

    PosixThread();
    PosixThread(pthread_t posixId);
    ~PosixThread();

    void start(void*(*threadFunc)(void*), void* threadArg);
    void join();
    bool join(double timeout_ms);
    bool setScheduling(int schedPolicy, int priority);
    bool getScheduling(int* pSchedPolicy, int* pPriority);
    class Exception;

private:
    pthread_t posixId;
    pthread_attr_t posixAttr;

protected:
    bool isActive = false;
};

class PosixThread::Exception : public exception
{
public:
    const char* launchingException() const noexcept;
};