#include <iostream>
#include<math.h>

using namespace std;

double * read_poly(int &n){
  cout << "il grado: ";
  cin >> n;
  double * c=new double[n+1];
  for(int i=0;i<=n;i++){
    cout << "coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}

void print_poly(double *c, int n){
  int i;
  cout << c[0];
  if(n>0)
    cout << " + ";
  for(i=1;i<n;i++)
    cout << c[i] << "*x^" << i << " + ";
  if(n>0)
    cout << c[n] << "*x^" << i;
  cout << endl;
}
double calc_poly(int n,double *c){
  int i,x;
  double sum = 0;
  cout<<"\n\n Enter the value of x for evaluation: ";
  cin>>x;
  sum=0;
  for (i=0;i<=n;i++)
    sum = sum + c[i]*pow(x, c[i]);
    cout << sum;
  return (sum);
  
}






int main()
{
  double *p1;
  int g1;

  p1=read_poly(g1);
  print_poly(p1,g1);
  calc_poly(g1,p1);

  delete[] p1;
  return 0;
}