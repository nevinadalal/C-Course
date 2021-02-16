#ifndef Patient_hpp
#define Patient_hpp

#include<stdio.h>
#include<vector>
#include<iostream>
#include "practical7Blood.hpp"
#include "practical7Date.hpp"
using namespace std;
class Patient{
  protected:
  string fullname; 
  vector<Blood>listofpatients;
  public:
  Patient(string);
  void addrecord(Blood);
  void print();
  void printreport();
};
#endif