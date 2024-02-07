
#include <iostream>
#include <string>
#include <iomanip>
#include<vector>
using namespace std;

void incr(unsigned int nLoops, double* pCounter)
{
    for (unsigned  i=0;i<nLoops;i++)
    {
       *pCounter += 1.0;  
    }
}
struct Data 
{
    unsigned int nLoops;
    double counter;
};

void *call_incr(void * v_data)
{
     Data* p_data = (Data*) v_data;
     incr(p_data->nLoops,&p_data->counter);
     return v_data;
}

int main(int argc, char* argv[])
{
  unsigned int  nLoops=stoi(argv[1]);
  unsigned int nTasks=stoi(argv[2]);
 
  Data data{nLoops,0.0};
  
  std::vector<pthread_t> incrementThread(nTasks);
  for (auto& thid : incrementThread){

    pthread_create(&thid, nullptr,call_incr,&data);
 
  }
   for (auto& thid : incrementThread)
  {
    pthread_join(thid, nullptr);  
  }

  std::cout << "Counter : " <<  data.counter << std::endl;
  return 0;
}




































