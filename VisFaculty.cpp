#include "VisFaculty.h"
#include <iostream>
using namespace std;



  VisFaculty :: VisFaculty(unsigned int sad, string naam, persontype p,
	     vector<Course> C, unsigned int jo, unsigned int co,
	     unsigned int h):Faculty(sad,naam,p,C,jo,co){
               host=h;
         }   
    // Assigned respectively.
    // gradepoint field is set to 0 for Faculty's Course objects
    // and is not used.

  unsigned int VisFaculty :: GetHost(){
    return host;
  }
  void VisFaculty :: SetHost(unsigned int h){
    host=h;
  }
    
  void VisFaculty ::  Print(){
    cout<<GetId()<<" "<<GetName()<<" "<<GetJournals()<<" "<<GetConfs()<<" "<<GetHost();
  } // Prints id, name, journals, conferences, host
                // on one line separated by a space.