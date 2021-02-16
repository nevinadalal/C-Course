#include <string>
#include <vector> 
#include <iostream>

#include "stack.h"
#include "exceptions.h"

using namespace std;

int main()
{
  //create two stacks one with 20 elements and one with 30
  Stack<int> stack1;

  //try removing element from an empty stack
  try 
  {
    stack1.push(3);
    stack1.push(5);
    stack1.print();
    cout << stack1.top() << endl;
    stack1.pop();
    stack1.print();
  }
  catch (exception &e) {
    cout << e.what() << endl;
  }


  // Stack of 1 to show it throws
  Stack<int> stack2(1);

  // should throw full stack exception
  try 
  {
    stack2.push(3);
    stack2.push(5);;
  }
  catch (exception &e) {
    cout << e.what() << endl;
  }
  return 0;
}