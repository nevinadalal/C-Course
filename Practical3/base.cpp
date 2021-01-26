#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

const int ms=50; // max dimensions of arrays and matrices

// function prototypes:
void read_int_vector(int a[], int n);
void simpler_random_int_vector(int v[], int s, int M);

int main()
{
  srand(time(0)); // initialisation of random number generation, see lecture notes

  int v1[ms], s;

  do{
    cout << "Vector dimension? ";
    cin >> s;
    if(s>ms)
        cout << "The maximal dimension is:  " << ms << "\n";
  }while(s>ms);

  read_int_vector(v1,s);

  cout << "The elements of the inputed array are: \n";
  for(int i=0;i<s;i++)
    cout << v1[i] << " ";
  cout << "\n";

  simpler_random_int_vector(v1,s,10);

  cout << "The elements of the randomly generated array are: \n";
  for(int i=0;i<s;i++)
    cout << v1[i] << " ";
  cout << "\n";

  return 0;
}

// Function definitions

// Function that reads in n integers and store them in the array a
void read_int_vector(int a[], int n){
  for(int i=0;i<n;i++){
    cout << i+1 << ". numero: ";
    cin >> a[i];
  }
}

// Function that create an array with s integers randomly generated in the interval [0,M]
void simpler_random_int_vector(int v[], int s, int M){
  for(int i=0;i<s;i++)
    v[i]=rand()%(M+1);
}