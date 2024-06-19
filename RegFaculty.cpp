#include "RegFaculty.h"
#include <iostream>
using namespace std;
  RegFaculty::RegFaculty(unsigned int sad, string naam, persontype p,
	     vector<Course> C, unsigned int jo, unsigned int co,
	     unsigned int S[], unsigned int nadv):Faculty(sad,naam,p,C,jo,co){
            advisees = (unsigned int *) malloc(nadv*sizeof(unsigned int));
            advisees=S;
            numadv=nadv;


         }
    // Assigned respectively.
    // gradepoint field is set to 0 for Faculty's Course objects
    // and is not used.
    
  bool RegFaculty::isAdvisor(unsigned int sid){
              for(int i=0;i<NumAdvisees();i++){
                if(advisees[i]==sid)return true;
              }
              return false;
  }
  unsigned int RegFaculty:: NumAdvisees(){
    return numadv;
  }
  
  void RegFaculty:: Print(){
    cout<<GetId()<<" "<<GetName()<<" "<<GetJournals()<<" "<<GetConfs();
  } // Prints id, name, journals, conferences
                // on one line separated by a space.
