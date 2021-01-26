#include <iostream>
#include <math.h>
using namespace std;

double * poli_sum (double * p1, int d1, double * p2, int d2, int & dr);


double * read_poly(int &n){
  cout << "Grade of function: ";
  cin >> n;
  double * c=new double[n+1];
  for(int i=0;i<=n;i++){
    cout << "Coefficient of degree " << i << ": ";
    cin >> c[i];
  }
  return c;
}

double * read_second_poly(int &m){
  cout << "Grade of second function: ";
  cin >> m;
  double * g=new double[m+1];
  for(int i=0;i<=m;i++){
    cout << "Coefficient of degree " << i << ": ";
    cin >> g[i];
  }
  return g;
}


double * poli_sum (double * p1, int d1, double * p2, int d2, int & dr){

    dr = 0;

    if (d1 <= d2){
            cout << "You're in first, d1 = " << d1 << endl;
            cout << "d2 = " << d2 << endl <<endl;

        for (int i = 0; i <= d2; i++){
          if (i >d1) p1[i] = 0; // setting array[i] to zero when it gets outside the defined grade
          cout << (p1[i]+p2[i])<< endl;

          cout << "pi1( "<< i << "): "<< p1[i] << endl;
          cout << "pi2( "<< i << "): "<< p2[i] << endl << endl;
          dr++;
        }
    }

    else if (d1 > d2){
          cout << "You're in second, d1 = " << d1 << endl;
          cout << "d2 = " << d2 << endl <<endl;

        for (int i = 0; i <= d1; i++){
          if (i > d2) p2[i] = 0; // setting array[i] to zero when it gets outside the defined grade
          cout << (p1[i]+p2[i])<< endl;

          cout << "pi1( "<< i << "): "<< p1[i] << endl;
          cout << "pi2( "<< i << "): "<< p2[i] << endl << endl;
          dr++;
        }
    }
    cout << "dr: "<< dr << endl;

    return 0;


}

int main()
{
  double *p1;
  double *p2;
  int g1, g2, g3;

  p1=read_poly(g1);

  p2 = read_second_poly(g2);

  poli_sum(p1,g1, p2, g2, g3);

  delete[] p1;
  delete[] p2;
  return 0;
}