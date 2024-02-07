#include "CountDown.h"
#include <iostream>


CountDown::CountDown(int number)
{
     counter = number;
}

int CountDown::getCount()
{
    return counter;
}

void CountDown::callback()
{
    --counter;
    std::cout << "Counter value= " << counter<<"\n";

    if(counter == 0)
    {
        std::cout << "End Counting \n";
        CountDown::stop();
    }
}