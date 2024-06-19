#https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC = g++
CFLAGS = -g
DEPS = MainDriver.o Course.o Person.o Faculty.o Student.o \
	RegFaculty.o VisFaculty.o

L4Q1: $(DEPS)
	$(CC) $(CFLAGS) -o $@ $(DEPS)

MainDriver.o: CS22B042-Lab3-Q1.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

#General rule for all other files with header to generate 
Course.o: Course.cpp Course.h
Student.o: Student.cpp Student.h
Faculty.o: Faculty.cpp Faculty.h
Person.o: Person.cpp Person.h
RegFaculty.o: RegFaculty.cpp RegFaculty.h
VisFaculty.o: VisFaculty.cpp VisFaculty.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf *.o L4Q1
