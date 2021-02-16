#include "Blood.hpp"

Blood::Blood(const int sysp, const int diastp, const Date date):
date(date){
  this -> sysp = sysp;
  this -> diastp = diastp;
}

int Blood::getSysp(){
  return this -> sysp;
}
int Blood::getDiastp(){
  return this -> diastp;
}
Date Blood::getDate(){
  return this -> date;
}
void Blood::print(){
  cout << "systp: " << sysp << " diastp: " << diastp << " " << date.getDay()
  << "/" << date.getMonth() << "/" << date.getYear() << endl;
}