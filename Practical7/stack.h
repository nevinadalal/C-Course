#include <iostream>
#include <vector> 

#include "exceptions.h"

using namespace std;

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
    int size;
    vector<T> stack;
    
    //constructor that creates a stack with 20 elements and one with n elements
    Stack(): size(20), nbrelements(0) {};
    Stack(int n): size(n), nbrelements(0) {};

    void push(T t) 
    {
      //check if stack is full
      if (stack.size() >= size)
      {
        throw FullStackException();
      }
      //if not full, add to the back of the stack 
      stack.push_back(t);
      nbrelements++;
    }

    void pop() 
    {
      //if stack is empty throw exception
      if(isEmpty())
      {
        throw EmptyStackException();
      }
      //if the stack is not empty, remove the last element
      stack.pop_back();
      nbrelements--;
    }

    T top() 
    {
      //if there are no element in the list throw exception
      if(isEmpty())
      {
        throw EmptyStackException();
      }

      //if the stack is non empty return the first element
      return stack.at(nbrelements-1);
    }

    bool isEmpty()
    {
      return nbrelements == 0;
    }

    //prints out the elements in the stack
    void print()
    {
      cout << '[';
      for(int i = stack.size() - 1; i >= 0; i--) 
      {
        cout << stack.at(i) << ' ' ;
      }
      cout << ']' << endl;
    }
};