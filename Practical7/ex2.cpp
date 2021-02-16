#include <string>
#include <vector> 
#include <iostream>
using namespace std;

//create FullStackException
struct FullStackException : public exception
{
	const char * what () const throw ()
    {
    	return "The stack is full";
    }
};

//create EmptyStackException
struct EmptyStackException : public exception
{
	const char * what () const throw ()
    {
    	return "The stack is empty";
    }
};

//StackI interface given in the question
template <typename T>
class StackI
{
  public:
    virtual void push(T t) = 0;
    virtual void pop() = 0;
    virtual T top() =0;
    virtual bool isEmpty() =0;
    virtual void print()=0;
};


//class Stack implementing StackI interface
//has attribute nbrelements to keep track of the number of elements in the stack and vector stack to store the elements
template<typename T>
class Stack: public StackI<T>
{
  public:
    int nbrelements;
    vector<T> stack;
    
    //constructor that creates a stack with 20 elements and one with n elements
    Stack(): stack(20), nbrelements(0) {};
    Stack(int n): stack(n), nbrelements(0) {};

    void push(T t) 
    {
      //check if stack is full
      if(nbrelements == 20)
      {
        throw FullStackException();
      }
      //if not full, add to the back of the stack 
      else 
      {
        stack.at(nbrelements) = t;
        nbrelements++;
      }
    }

    void pop() 
    {
      //if stack is empty throw exception
      if(nbrelements == 0)
      {
        throw EmptyStackException();
      }
      //if the stack is not empty, remove the last element
      else
      {
        stack.pop_back();
        nbrelements--;
      }

    }


    T top() 
    {
      //if there are no element in the list throw exception
      if(nbrelements == 0)
      {
        throw EmptyStackException();
      }
      //if the stack is non empty return the first element
      return stack.at(0);
      
    }

    bool isEmpty()
    {
      if(nbrelements == 0)
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    //prints out the elements in the stack
    void print()
    {
      cout << '[';
      if(nbrelements > 0)
      {
        for(int i = 0; i < nbrelements; i++) 
        {
          cout << stack.at(i) << ' ' ;
        }
      }
      cout << ']' << endl;
    }
};

int main()
{

  //create two stacks one with 20 elements and one with 30
  Stack<int> stack1;
  Stack<int> stack2(30);

  stack2.print();

  //try removing element from an empty stack
  try 
  {
    stack2.pop();
  }
  catch (exception &e) {
    cout << e.what() << endl;
  }

  //try to push more than 20 elements 
  try 
  {
    for (int i = 0; i < 20; i++) 
    {
      stack1.push(1);
    }
    stack1.push(2);
  }
  catch (exception &e) {
    cout << e.what() << endl;
  }
  
  //check that pop works correctly by printing stack before and after popping an element
  stack1.print();
  try {
    stack1.pop();
  }
  catch (exception &e) {
    cout << e.what() << endl;
  }
  stack1.print();

  //getting the top value of a non empty stack
  try {
    int top = stack1.top();
    cout << "Top value: " << top << endl; 
  }
  catch (exception &e) {
    cout << e.what() << endl;
  }
  return 0;
}