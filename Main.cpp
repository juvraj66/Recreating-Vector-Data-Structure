
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include"Vec.h"
int main(){
  Vec<int> g(4,1);
  std::cout<<g.size()<<std::endl;
  g.push_back(11);
  g.push_back(12);
  g.pop_back();
  std::cout<<g.front()<<" "<<g.back();
  return 0;
}
