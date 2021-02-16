#include <string>
#include <vector> 
#include <iostream>
using namespace std;

//class date with day, month and year attributes
class Date
{
  public:
    int day, month, year;
    //constructor
    Date(int day, int month, int year): day(day), month(month), year(year)
    {}
};

//class blood with systosli, diastolic and date attributes
class Blood
{
  
  public:
    int systolic, diastolic;
    Date date;
    //constructor
    Blood(int systolic, int diastolic, Date date): systolic(systolic), diastolic(diastolic), date(date)
    {}

};

//class Patient with name attribute
//also conatains addRecord and printRecord funtions
class Patient
{
  
  public:
    string name;
    //constructor
    Patient(string name) {
      this->name = name;
    }
    
    //the vector will be used to store all the records of a patient
    vector<Blood> bloodList;

    //add a record to the back of the list
    void addRecord(Blood blood)
    {
      bloodList.push_back(blood);
    }

    //printing the report of the patient
    void printReport()
    {
      cout << "The report of the patient " << name << "." << endl;

      Blood highest = bloodList.at(0);
      vector<Blood> list_highest;
      list_highest.push_back(highest);
      float average = 0.0f;

      //iterate through the blood record to get the highest systolic values and to calculate the average diastolic value.
      for(int i=0; i < bloodList.size(); i++)
      {
        Blood temp = bloodList.at(i);
        
        average += temp.diastolic; 

        //check if the current systolic value is over 140 and if it's higher than the current highest value
        if(temp.systolic > 140 && temp.systolic >= highest.systolic)
        {
          //if the value is the same as the current highest, then store it in the list
          if(highest.systolic == temp.systolic) 
          {
            list_highest.push_back(temp);
          }
          //if it's larger, then remove the current values in the list and add the highest value
          else 
          {
            highest = temp;
            while(list_highest.size() != 0)
            {
              list_highest.pop_back();
            }
            list_highest.push_back(temp);
          }
        }        
      }
      
      //printing the values that we've found
      if(highest.systolic < 140) 
      {
        cout << "No measurement was too high" << endl;
      }
      else 
      {
        cout << "The highest abnormal systolic value was " << highest.systolic << endl;
        cout << "The corresponding diastolic value is " << highest.diastolic << endl;
        cout << "It was taken on " << highest.date.day << "/" << highest.date.month << "/" << highest.date.year << endl;
        cout << "The list of  highest abnormal systolic value is " << endl;
        for (int i = 0; i < list_highest.size(); i++)
        {
          cout << list_highest.at(i).systolic << endl;
        }
      }


      average = average/bloodList.size();

      cout << "Average Diastolic value is " << average << endl;

    }

};

int main() {

//create patient Mary with blood record
Patient mary("Mary");
mary.addRecord(Blood(94,61, Date(2,5,2013)));
mary.addRecord(Blood(97,65, Date(3,5,2013)));
mary.addRecord(Blood(144,99, Date(4,5,2013)));
mary.addRecord(Blood(123,88, Date(5,5,2013)));
mary.addRecord(Blood(177,110, Date(6,5,2013)));
mary.addRecord(Blood(145,89, Date(7,5,2013)));
mary.printReport();

//create patient John with blood record
Patient john("John");
john.addRecord(Blood(88,57, Date(15,5,2013)));
john.addRecord(Blood(95,61, Date(16,5,2013)));
john.addRecord(Blood(144,80, Date(17,5,2013)));
john.addRecord(Blood(151,96, Date(18,5,2013)));
john.addRecord(Blood(176,104, Date(19,5,2013)));
john.addRecord(Blood(176,110, Date(20,5,2013)));
john.printReport();

return 0;
}