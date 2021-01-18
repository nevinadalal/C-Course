// position of a moving body
#include<iostream>
#include<cmath>
using namespace std;

// definition of the function
double pos (double i_p, double v, double a, double n, double d_t, double t)
{ 
  return i_p + v*t + 0.5*a*pow(t,2);
}

int main()
{
  double i_p, v, a, n, d_t, t, position; // inputs from user
  t = 0;
  cout << "Enter the initial position: ";
  cin >> i_p;
  cout << "Enter the speed: ";
  cin >> v;
  cout << "Enter the acceleration: ";
  cin >> a;
  cout << "How many times would you want to display the position of the moving body? ";
  cin >> n;
  cout << "How often (in seconds) would you want to update the position of the moving object? ";
  cin >> d_t;

  cout << "---------------------------------" << endl;
  cout << "Acceleration: " << a << "  " << "Initial speed: " << v << "  " << "Initial position: " << i_p << "  " << "Number of times: " << n << "  " << "Delta t: " << d_t << endl;

  while (n>0)
  {
    position = pos(i_p, v , a, n, d_t, t);
    cout << "At time " << t << " the position is " << position << endl;
    n --;
    t += d_t;
  }
  return 0;
}