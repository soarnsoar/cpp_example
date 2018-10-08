#include <iostream>
using namespace std;

class sample_info {
private :
  int nhisto=0;

public:
  int N=1;
  void Set_N();
};


void sample_info::Set_N(){
  N = nhisto;
}
  
