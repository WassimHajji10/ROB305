#include <iostream>
#include"CountDown.h"

int main()
{
    CountDown countDown(6);
    countDown.start(1000);

    while (countDown.getCount() !=0)
    {
    }
    return 0;
}

