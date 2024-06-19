// Roll Number:CS22B042
// Name: Pranjal Katte

#include<iostream>
#include "Course.h"
#include "Person.h"
#include "Faculty.h"
#include "RegFaculty.h"
#include "VisFaculty.h"
#include "Student.h"
using namespace std;

// Reg. Faculty: 1000 - 1999
// Vis. Faculty: 2000 - 2999
// Students: 3000 - 9999
const unsigned int PERSONS = 1000;

int main()
{
  cout<<" -------- WELCOME TO ACADEMIC ENTITY MANAGEMENT SYSTEM -------- \n";
  vector<Person *> AllPersons;

  unsigned int *S;

  char Q;

 
  cout<< " ******** ENCODING SCHEME OF SADHAR IDENTIFIERS ********\n";
  cout<<"RegFaculty: 1000 - 1999; persontype: rfa\n";
  cout<<"VisFaculty: 2000 - 2999; persontype: vfa\n";
  cout<<" Student: 3000 - 9999, persontype: cst\n";

  cout<<"--------REGFACULTY FORMAT--------\n";
  cout<<"id name N uint1 uint2 ... uintN J C A uint1 uint2 ... uintA\n";
  cout<<"sadhar, name, the N course numbers taught by the faculty number, the number of journals and conferences, the number of advisees (A), and advisees identifiers respectively";


   cout<<"--------VISFACULTY FORMAT--------\n";
   cout<<"id name N uint1 uint2 ... uintN J C hid\n";
   cout<<"sadhar, name, the N course numbers taught by the faculty number, the number of journals and conferences, and the host identifier, respectively";
   

    cout<<"--------STUDENT FORMAT--------\n";
	cout<<"id name C uint1 gp1 uint2 gp2 ... uintC gpC fid\n";
	cout<<"sadhar, name, C course numbers and grades for courses taken by the student, and the id of the faculty advisor\n";
    cout<<"PRESS -1 to finish entries\n";
	 
	 
	 cout<<" ENTER INPUT ENTRIES \n";
     int id,journals,confs,NA,N;
	 string name;
	 cin>>id;
	 while(id!=-1){
		if(id>=1000 && id<=1999){  // for Reg Faculty
			  vector<Course> Taught;
  vector<Course> Taken;
			cin>>name>>N;
			for(int i=0;i<N;i++){
				int cid;
				cin>>cid;
			
				Taught.push_back(Course(cid,0));
			}
				cin>>journals>>confs>>NA;
				S=new unsigned int[NA];
				for(int i=0;i<NA;i++)cin>>S[i];
		        // Example way to add a Reg. Faculty object pointer to AllPersons
             AllPersons.push_back((RegFaculty *) new RegFaculty(id, name, rfa, Taught,journals, confs, S, NA)); 

			}

		
		else if(id>=2000 && id<=2999){ //For Vis Faculty
			  vector<Course> Taught;
  vector<Course> Taken;
			cin>>name>>N;
			for(int i=0;i<N;i++){
				int cid;
				cin>>cid;
			
				Taught.push_back(Course(cid,0));
			}
				cin>>journals>>confs;
				int hid;
				cin>>hid;
				AllPersons.push_back((VisFaculty *) new VisFaculty(id, name, vfa, Taught,journals, confs, hid)); 


		}
	 
	 else if(id>=3000 && id<=9999){ //For Student
		  vector<Course> Taught;
  vector<Course> Taken;
           			cin>>name>>N;
					for(int i=0;i<N;i++){
						int cid,grade;
						cin>>cid>>grade;
						Taken.push_back(Course(cid,grade));
					}
						int fid;
						cin>>fid;
	AllPersons.push_back((Student *) new Student(id, name, cst, Taken,fid)); 
					}
	 
    // Example way to add a Reg. Faculty object pointer to AllPersons
    // AllPersons.push_back((RegFaculty *) new
	// 		 RegFaculty(id, name, rfa, Taught,
	// 			    journals, confs, S, NA)); 
	 cin>>id;
	 }

	 cout<<"----------- QUERIES ----------\n";

	 cout<<"– H vid: Prints the sadhar and name of the relevant host RegFaculty, as follows:\n";
cout<<"hid name \n";
cout<<"Invalid vid values or vids where there is no matching hid in the stored entries, are ignored and no output is generated\n\n";
cout<<" J: Prints the sadhar of the student with the highest CGPA; if multiple students have the same highest CGPA, then the sadhar of the first student stored in the vector is printed.\n";
cout<<" U sid \n Prints 1 if this sid is stored in the advisees list of the fid that is stored in the Student’s record; and 0, otherwise.\n\n";
cout<<"If there is no fid entry in the database for the given sid, then 0 is printed. Invalid sid values are ignored and no output is generated.\n\n";
cout<<" X: Exit the program\n";

cout<<" ***** ENTER QUERY *****\n";

    cin >> Q;
    while (Q != 'X')
      {
	unsigned int sid, fid, cid;
	int t;
	unsigned int maxcg;
	    unsigned int max_stud_id;
	switch (Q)
	  {
		
	    // Print name of host faculty given vid
	  case 'H':
	    
		cin>>t;
	    for(int i=0;i<AllPersons.size();i++){
			if(AllPersons[i]->GetId()==t){
				VisFaculty *visf = (VisFaculty *) AllPersons[i];
                int k= visf->GetHost();
				for(int j=0;j<AllPersons.size();j++){
                   if(AllPersons[j]->GetId() ==k ){
                          RegFaculty *regf = (RegFaculty *) AllPersons[j];
						  cout << k<<" "<<regf -> GetName()<<endl;
				   }
			}
		}}

	    break; 	  	// End 'H' query
	    
	  case 'J':		// Student with highest CGPA
	    

	    maxcg = 0;
	    for (unsigned int i = 0; i < AllPersons.size(); i++)
	      {
		if (AllPersons[i]->GetPType() == cst)
		  {
		    // Need to get a cast Pointer to Derived Class
		    // If there are other ways, you can use that too.
		    Student *stud = (Student *) AllPersons[i];
				//std::cout<<stud->GetCG()<<std::endl;

				if (maxcg < stud->GetCG()){
                   maxcg = stud->GetCG();
				   max_stud_id=stud->GetId();
			
			  }
                       
		  } // End If
	      }	// End For
	    cout << max_stud_id << endl;
	    break; 	  	// End 'J' query

	  case 'U':		// Change VisFac to Reg
	    cin >> sid;
		for(int i=0;i<AllPersons.size();i++){
			if(AllPersons[i]->GetId()==sid && AllPersons[i]->GetPType()==cst){
				int facad=((Student*)AllPersons[i])->GetFacad();
				bool check=false;
				
				for(int j=0;j<AllPersons.size();j++){
					if(AllPersons[j]->GetId()==facad && AllPersons[j]->GetPType()==rfa){
					if(((RegFaculty*)AllPersons[j])->isAdvisor(sid)){
						cout<<1<<endl;
						check=true;
						break;
					}
				}}
				if(check==false)cout<<0<<endl;

			}
		}

	    break; 	  	// End 'U' query

	  }
	
	cin >> Q;
	
      }	// End While
}

