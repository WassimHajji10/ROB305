#include <iostream>
#include <unistd.h>
#include "Chrono.h"

int main() 
{

    std::cout << "Sleep for 5s" << std::endl;
    Chrono chrono;
    sleep(5);
    chrono.stop();    
    std::cout << "Measured time :" << chrono.lap() << " ms" << std::endl;
    return 0;
}