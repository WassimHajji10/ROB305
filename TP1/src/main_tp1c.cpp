#include <iostream>
#include"Signature.h"
#include <string>
#include <iomanip> 
using namespace std;


int main(int argc, char* argv[])
{

  unsigned int  nLoops=stoi(argv[1]);
  double a=0;
  double *counter=&a;
  
  std::cout<<"Initial counter value= "<<*counter<<"\n";
  incr(nLoops,counter);
  std::cout<<"Final counter value= "<<*counter<<"\n";

    return 0;
}