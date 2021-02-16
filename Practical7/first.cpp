#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
string name;
static vector < string > date;
static vector < int > sys;
static vector < int > dia;
class Date{
      public: 
      Date(int dd, int mm, int yyyy)
      {
          ostringstream str1, str2, str3;
          str1<<dd;
          string dds = str1.str();
          str2<<mm;
          string mms = str2.str();
          str3<<yyyy;
          string yyyys = str3.str();
          date.push_back(dds+"/"+mms+"/"+yyyys);
      }
  };
  class Blood
  {
      public:
      Blood(int s, int d, Date dt)
      {
          sys.push_back(s);
          dia.push_back(d);
      }
  };
class Patient
{
  
  public : 
      Patient(string pname)
      {
          name = pname;
      } 
      void printReport(){
        vector <int> :: iterator it1; 
        vector <int> :: iterator it2; 
        vector <string> :: iterator it3; 
        cout<<"\tPatient: "<<name<<"\n";
        for(it1 = sys.begin(), it2 = dia.begin(), it3 = date.begin(); it1 != sys.end() && it2 != dia.end() && it3 != date.end(); ++it1, ++it2, ++it3)
        {
            cout << '\t' << *it1 << '\t' << *it2 << '\t' << *it3; 
            cout << '\n'; 
      }
      }
       void addRecord(Blood bd)
       {}

};
  
   
 

int main(){
  Patient mary("Mary");
  mary.addRecord(Blood(94, 61, Date(2, 5, 2013)));
  mary.addRecord(Blood(97, 65, Date(3, 5, 2013)));
  mary.addRecord(Blood(144, 99,Date(4, 5, 2013)));
  mary.addRecord(Blood(123, 88,Date(5, 5, 2013)));
  mary.addRecord(Blood(177, 110,Date(6, 5, 2013)));
  mary.addRecord(Blood(145, 89,Date(7, 5, 2013)));
  mary.printReport();
  
  return 0;
}