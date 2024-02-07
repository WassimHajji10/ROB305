
#include <iostream>
#include"TimeSpec.h"


//Benchmark cpu
void incr(unsigned int nLoops, double* pCounter)
{     
   double counterValue=0;
   struct timespec start;
   struct timespec end;
   start=timespec_now();

   for (int i=0;i<nLoops;i++)
   {  
      counterValue++;
   }
   
   *pCounter=counterValue;
   end=timespec_now(); 
   std::cout<<"Time in s = " <<timespec_to_ms(end-start) /1000<<"\n"; 
}