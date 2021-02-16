#include "Patient.hpp"
#include "Blood.hpp"
Patient ::Patient( string name){
  this -> name = name;
  this -> table = vector<Blood>();
}

void Patient :: addRecord(Blood record){
  this -> table.push_back(record);
}

void Patient :: print(){
  cout << "−−−−− Patient: " << this -> name << " −−−−−−" << endl;
  for(int j=0;j<this -> table.size();j++){
    this -> table[j].print ();
  }
}

void Patient :: printReport(){
  vector<Blood> highestAbnormal =vector<Blood>();
  int max = 140;
  double avgDiastolic = 0.0;
  for(int i=0;i<this -> table.size();i++){
    avgDiastolic+=table[i].getDiastp();
    if (table [ i ]. getSysp()>max){
      highestAbnormal.clear();
      highestAbnormal.push_back(table[i]);
      max=table[i].getSysp();
    }
    else if (table [ i ]. getSysp()==max){
      highestAbnormal.push_back(table[i]);
    }
  }
  cout << "−−−− Patient " << this -> name << " report −−−− " << endl;
  if (highestAbnormal.size()==0)
    cout << "no measurement was abnormal " << endl;
  else{
    cout << "abnormal systolic pressure " << endl;
    for(int i=0;i<highestAbnormal.size();i++){
      cout << "\t";
      highestAbnormal[i].print ();
    }
  }
  cout << "average diastolic pressure: " << avgDiastolic/table.size() << endl;
  cout << "−−−−−−−−−−−−−−−−− " << endl;
}