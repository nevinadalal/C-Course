#include<iostream>
#include<cmath>
using namespace std;
int npc=0;
float np(float a,unsigned int n){
  npc++;
  if(n==0){
    return 1;
  }
  else{
    return a*np(a,n-1);
  }
}
int npc2=0;
float np2(float a, unsigned int n){
  npc2++;
  if(n==0){
    return 1;
  }
  else if(n%2==0){
    return pow(np2(a,n/2),2);
  }
  else{
    return a*pow(np2(a,n/2),2);
  }
}
int main(){
  int a;
    unsigned int n;
    cout<<"Enter a:"<<endl;
    cin>>a;
    cout<<"Enter n: "<<endl;
    cin>>n;
    cout<<"1st Recursion method : "<<np(a,n)<<"   "<<npc<<endl;
    cout<<"2nd Recursion method : "<<np2(a,n)<<"   "<<npc2<<endl;
    //First Recursion number of func calls is n+1
    //2nd Recursionn number of func calls is floor(log(n)) +2
}