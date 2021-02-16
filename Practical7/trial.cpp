#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
 
using namespace std;

template <class T>
class Stack { 
   private: 
      vector<T> elems;   
 
   public: 
      void push(T const&);  
      void pop();               
      T top() const;            
      bool isEmpty() const{       
         return elems.empty(); 
      } 
}; 
 
template <class T>
void Stack<T>::push (T const& elem) { 
   
   elems.push_back(elem);    
} 
 
template <class T>
void Stack<T>::pop () { 
   if (elems.empty()) { 
      throw out_of_range("Empty Stack"); 
   }
        
   elems.pop_back();         
} 
 
template <class T>
T Stack<T>::top () const { 
   if (elems.empty()) { 
      throw out_of_range("Empty stack"); 
   }
        
   return elems.back();      
} 
 
int main() { 
   try { 
      Stack<int> intStack;
 
      
      intStack.push(16); 
      cout << intStack.top() <<endl; 
 
      
   }catch (exception const& ex) { 
      cerr << "Exception: " << ex.what() <<endl; 
      return -1;
   } 
}