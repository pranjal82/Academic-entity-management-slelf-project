// Roll Number:cs22b042
// Name:Pranjal Katte

#include <iostream>
#include "Person.h"
using namespace std;


Person::Person(unsigned int sad, std::string naam,persontype p){
    this->sadhar=sad;
    this->name=naam;
    this->ptype=p;
} // assigned respectively

string Person ::GetName(){
    return name;
  }

 unsigned int  Person:: GetId(){
    return sadhar;
  }
  
 void Person:: Print(){
    cout<<sadhar<<" "<<name;
 }

 persontype Person::GetPType(){
  return ptype;
 }

 void Person::SetPType(persontype p){
     this->ptype=p;
 }

 void  Person::SetId(unsigned int sad){
  sadhar=sad;
 }

 
