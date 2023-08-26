#include "../lib/random.hpp"
#include "../lib/debug.hpp"

#include <numeric>
#include <iostream>

using namespace akTARDIGRADE13;

int main(){
  for(int i = 0; i < 10; ++i){
    std::cout << rng() << std::endl;
  }
  
  for(int i = 0; i < 10; ++i){
    std::cout << randint(-100,101) << std::endl;
  }

  for(int i = 0; i < 10; ++i){
    std::cout << rnd() << std::endl;
  }

  std::vector<int> vec(10);
  std::iota(vec.begin(), vec.end(), 0);
  randshf(vec);
  std::cout << vec << std::endl;

  zobristHash zob(10);
  for(int i = 0; i < 10; ++i){
    std::cout << zob.get_rand(i) << std::endl;
  }
}