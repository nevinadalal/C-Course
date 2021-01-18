#include <iostream>
using namespace std;

long calls;
long F(long n){
  calls ++;
  if (n<=1)
    return 1;
  else
    return F(n-1) + F(n-2);
}

int main(){
  long i,c,d,num;
  cout << "enter integer:";
    cin >> num;
  for (i=0;i<=num;i++){
    calls=0;
    d=F(i);
    c=calls;
    cout<< "i=" << i << "F(i)="<< d<<"calls="<<c<<endl;
  
  }
  return 0;
}