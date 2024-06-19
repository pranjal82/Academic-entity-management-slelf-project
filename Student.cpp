// Roll Number:cs22b042
// Name:Pranjal Katte

#include <iostream>

#include "Student.h"
#include "Person.h"


using namespace std;

  
 
 Student:: Student(unsigned int sad, string naam,persontype p,
	  vector<Course> C, unsigned int fid): Person(sad,naam,p){
        
        this->CoursesTaken = C;
        this->facad=fid;


      }
    // Assigned respectively.
    
  vector<Course>Student::GetCourses(){
    return CoursesTaken;
  } // Returns copy of courses vector
  unsigned int Student:: GetCG(){
    int cgpa=0;
    for(auto it:CoursesTaken){
        cgpa+=it.GetGrade();

    }
    cgpa=cgpa/CoursesTaken.size();  //total cg
    return cgpa;
  }
  unsigned int Student::GetFacad(){
    return facad;
  } // Returns  copy of Facad ID of student.
  void Student::Print(){
    Person::Print();
    cout<<" "<<GetCG()<<" "<<GetFacad()<<endl;
  } // Prints sadhar, name, cpga details of student,
                // followed by facad's id and name.

