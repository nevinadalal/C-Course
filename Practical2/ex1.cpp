#include <bits/stdc++.h> 
using namespace std; 
  
bool isInside(int circle_x, int circle_y, 
                   int rad, int x, int y) 
{  
    if ((x - circle_x) * (x - circle_x) + 
        (y - circle_y) * (y - circle_y) <= rad * rad) 
        return true; 
    else
        return false; 
} 
  
int main() 
{ 
    int x, y; 
    int circle_x, circle_y, rad;
    cout << "enter x coordinate:";
    cin >> x;
    cout << "enter y coordinate:";
    cin >> y;
    cout << "enter x coordinate of the circle:";
    cin >> circle_x;
    cout << "enter y coordinate of the circle:";
    cin >> circle_y;
    cout << "enter radius of the circle:";
    cin >> rad; 
    isInside(circle_x, circle_y, rad, x, y) ?  
    cout << "Point inside the circle" : cout << "Point outside the Outside"; 
} 