
#include"TimeSpec.h"
#include <iostream>

using namespace std;

int main()
{
    struct timespec currentTime;
    struct timespec waitTime;
    struct timespec otherTime;
    struct timespec deltaTime;  
    struct timespec verificationTime;  
    double timeInMilliseconds;

    // Verification of timespec_now() and timespec_to_ms functions
    currentTime = timespec_now();
    cout << "Current Time:s:  " << currentTime.tv_sec << ", ns :  " << currentTime.tv_nsec << "\n\n";
    cout << "Current Time in ms: " << timespec_to_ms(currentTime) << "\n\n";

    // Verification of timespec_from_ms
    otherTime.tv_sec = 5;
    otherTime.tv_nsec = 800000000;
    timeInMilliseconds = timespec_to_ms(otherTime);
    cout << "Verification of timespec_to_ms: " << timeInMilliseconds << "\n";
    otherTime = timespec_from_ms(timeInMilliseconds);
    cout << "Verification of timespec_from_ms\n s :  " << otherTime.tv_sec << ", ns :  " << otherTime.tv_nsec << "\n\n";

    // Verification of negation
    verificationTime = timespec_negate(otherTime);
    timeInMilliseconds = timespec_to_ms(verificationTime);
    cout << "Negated time in ms: " << timeInMilliseconds << "\n\n";

    otherTime.tv_sec = 5;
    otherTime.tv_nsec = 600000000;

    cout << "Time 1: s : " << otherTime.tv_sec << ", ns : " << otherTime.tv_nsec << "\n\n";
    cout << "Time 2: s : " << otherTime.tv_sec << ", ns : " << otherTime.tv_nsec << "\n\n";

    // Verification of time_add
    verificationTime = timespec_add(otherTime, otherTime);
    cout << "Verification of time_add\n s : " << verificationTime.tv_sec << ", ns :  " << verificationTime.tv_nsec << "\n\n";

    // Verification of time_subtract
    verificationTime = timespec_subtract(otherTime, otherTime);
    cout << "Verification of time_subtract\n s : " << verificationTime.tv_sec << ", ns : " << verificationTime.tv_nsec << "\n\n";

    deltaTime.tv_sec = 5;
    deltaTime.tv_nsec = 100000000;

    // Verification of timespec_wait
    waitTime = timespec_wait(deltaTime);

    // Verification of operators
    cout << "Verification of operators\n";
    cout << "Time 1: s :  " << otherTime.tv_sec << ", ns : " << otherTime.tv_nsec << "\n \n";
    cout << "Time 2: s :  " << otherTime.tv_sec << ", ns : " << otherTime.tv_nsec << "\n \n";

    // Verification of op-
    verificationTime = -otherTime;
    cout << "Verification of op-\n s :  " << verificationTime.tv_sec << ", ns :  " << verificationTime.tv_nsec << "\n \n";    

    // Verification of op+
    verificationTime = otherTime + otherTime;
    cout << "Verification of op+\n s :  " << verificationTime.tv_sec << ", ns :  " << verificationTime.tv_nsec << "\n \n";    

    // Verification of op-
    verificationTime = otherTime - otherTime;
    cout << "Verification of op-\n s :  " << verificationTime.tv_sec << ", ns : " << verificationTime.tv_nsec << "\n \n";

    // Verification of op+=
    otherTime += otherTime;
    cout << "Verification of op+=\n s :  " << otherTime.tv_sec << ", ns : " << otherTime.tv_nsec << "\n \n";

    // Verification of op-=
    otherTime -= otherTime;
    cout << "Verification of op-=\n s :  " << otherTime.tv_sec << ", ns :  " << otherTime.tv_nsec << "\n \n";

    // Verification of op==
    cout << "Verification of op==\n Value True: " << (otherTime == otherTime) << ", Value False: " << (otherTime == verificationTime) << "\n \n";

    // Verification of op!=
    otherTime.tv_sec = otherTime.tv_sec;
    otherTime.tv_nsec = otherTime.tv_nsec;
    cout << "Verification of op!=\n Value True: " << (otherTime != verificationTime) << ", Value False: " << (otherTime != otherTime) << "\n \n";

    // Verification of op>
    otherTime.tv_sec = otherTime.tv_sec + 1;
    otherTime.tv_nsec = otherTime.tv_nsec + 1;
    cout << "Verification of op>\n Value True: " << (otherTime > verificationTime) << ", Value False: " << (verificationTime > otherTime) << "\n \n";

    // Verification of op<
    otherTime.tv_sec = otherTime.tv_sec - 1;
    otherTime.tv_nsec = otherTime.tv_nsec - 1;
    cout << "Verification of op<\n Value True: " << (otherTime < verificationTime) << ", Value False: " << (verificationTime < otherTime) << "\n \n";
    
    return 0;
}