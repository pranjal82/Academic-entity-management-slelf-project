// Roll Number:CS22B042
// Name: Pranjal Katte

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Course.h"
using namespace std;


Course :: Course (){
    cid=0;
    gradepoint=0;
}

  // assigned respectively
  // if id is not between 100 and 999 (both inclusive), cid is set to 0
  // if grade is not between 4 and 10 (both inclusive),
  // gradepoint is set to 0
  Course ::Course(unsigned int id, unsigned int grade){
    if(id>=100 && id<=999)cid=id;
    else cid=0;
    
    if(grade>=4 &&  grade<=10)gradepoint=grade;
    else  gradepoint=0;
  }

  unsigned int Course :: GetCid(){
    return cid;
  } // returns cid

 unsigned int Course :: GetGrade(){
    return  gradepoint;
  } // returns gradepoint

  // if grade is not between 4 and 10 (both inclusive),
  // gradepoint is set to 0

  void Course ::SetGrade(int g){
    gradepoint=g;
    }// sets gradepoint to g

 void Course :: Print(){
    cout<<cid<<" "<<gradepoint<<endl;
  } // Prints cid and gradepoint separated by a blank space on
  // one line.