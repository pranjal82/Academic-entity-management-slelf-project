// Roll Number:cs22b042
// Name:Pranjal Katte

#include <iostream>
#include "Faculty.h"

using namespace std;

  
 
 Faculty:: Faculty(unsigned int sad, string naam,persontype p,
	  vector<Course> C, unsigned int jo, unsigned int co) : Person(sad,naam,p){
             
             this->CoursesTaught=C;
             journals=jo;
             confs=co;

      }
    // Assigned respectively.
    // gradepoint field is set to 0 for Faculty's Course objects
    // and is not used.
    
  unsigned int Faculty:: GetJournals(){
    return journals;
  } // Returns journals value
  unsigned int Faculty:: GetConfs(){
   return confs;
  } // Returns confs value
  vector<Course>Faculty::  GetCourses(){
    return CoursesTaught;
  } // Returns ref. to courses vector
  
  void Faculty::  Print(){
             cout<<GetId()<<" "<<GetName()<<" "<<GetJournals()<<" "<<GetConfs()<<endl;
    }// Prints id, name, journals, conferences
                // on one line separated by a space.


