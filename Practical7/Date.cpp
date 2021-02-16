#include "Date.hpp"
int Date::getDay(){
  return this -> day;
}

int Date::getMonth(){
  return this -> month;
}

int Date::getYear(){
  return this -> year;
}

Date::Date(const int day,const int month,const int year){
  this -> day=day;
  this -> month=month;
  this -> year=year;
}
void Date::print(){
  cout << day << "/" << month << "/" << year;
}