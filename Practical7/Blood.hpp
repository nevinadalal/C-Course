#ifndef BloodPressure_hpp
#define BloodPressure_hpp
#include <stdio.h>
#include "Date.hpp"

class Blood{
protected:
  int sysp;
  int diastp;
  Date date;
public:
  Blood(const int, const int , const Date);
  int getSysp();
  int getDiastp();
  Date getDate();
  void print ();
};
#endif /* BloodPressure_hpp */