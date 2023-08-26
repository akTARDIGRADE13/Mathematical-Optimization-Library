#include "../lib/timer.hpp"

#include <iostream>

int main(){
  akTARDIGRADE13::Timer timer(3000);

  int cnt = 0;
  while(!timer.isTimeOver()){
    timer.setNowTime();
    if(cnt%100000 == 0){
      std::cout << timer.getNowTime() << std::endl;
    }
    ++cnt;
  }
}