#include <iostream>
#include <vector>
#include "Date.hpp"
#include "Blood.hpp"
#include "Patient.hpp"

int main(int argc, const char * argv []) {

  Patient mary = Patient("Mary");
  Patient john = Patient("John");

  mary.addRecord(Blood(94,61, Date(2,5,2013)));
  mary.addRecord(Blood(97,65, Date(3,5,2013)));
  mary.addRecord(Blood(144,99, Date(4,5,2013)));
  mary.addRecord(Blood(123,88, Date(5,5,2013)));
  mary.addRecord(Blood(177,110, Date(6,5,2013)));
  mary.addRecord(Blood(145,89, Date(7,5,2013)));

  john.addRecord(Blood(88,57, Date(15,5,2013)));
  john.addRecord(Blood(95,61, Date(16,5,2013)));
  john.addRecord(Blood(114,80, Date(17,5,2013)));
  john.addRecord(Blood(151,96, Date(18,5,2013)));
  john.addRecord(Blood(176,104, Date(19,5,2013)));
  john.addRecord(Blood(176,110, Date(20,5,2013)));

  mary.printReport();
  john.printReport();
  return 0;
}