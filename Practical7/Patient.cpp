#include "Patient.hpp"
#include "Blood.hpp"

Patient::Patient(string fullname){
  this->fullname=fullname;
  this->listofpatients=vector<Blood>();
}
void Patient::addrecord(Blood record){
  this->listofpatients.push_back(record);
}
void Patient::print(){
  cout<<"----Patient:"<<this->fullname<<"----"<<endl;
  for(int j=0;j<this->listofpatients.size();j++){
    this->listofpatients[j].print();
  }
}
void Patient::printreport(){
  vector<Blood>highestabnormal=vector<Blood>();
  int max=140;
  double averagediastolic=0.0;
  for(int i=0;i<this->listofpatients.size();i++){
    averagediastolic+=listofpatients[i].getdiastolic();
    if (listofpatients[i].getsystolic()>max){
      highestabnormal.clear();
      highestabnormal.push_back(listofpatients[i]);
      max=listofpatients[i].getsystolic();
    }
    else if(listofpatients[i].getsystolic()==max){
      highestabnormal.push_back(listofpatients[i]);
    }
  }
  cout<<"----Patient"<<this->fullname<<"report---"<<endl;
  if (highestabnormal.size()==0){
    cout<<"no measurement was abnormal"<<endl;
  }
  else{
    cout<<"abnormal systolic pressure"<<endl;
    for(int i=0;i<highestabnormal.size();i++){
      cout<<"\t";
      highestabnormal[i].print();
    }
  }
  cout <<"average diastolic pressure:"<<averagediastolic/listofpatients.size()<<endl;
  cout <<"----"<<endl;
}
