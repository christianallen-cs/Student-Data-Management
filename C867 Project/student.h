#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student {

public:
	const static int totalDaysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	DegreeProgram degreeProgram;
	int age;
	int totalDaysToCompleteCourses[totalDaysArraySize];

public:
	Student(); /* PARAMATERLESS CONSTRUCTOR - SETS DEFAULT VALUES */
	Student(string studentID, string firstName, string lastName, string email, int age, int totalDaysToCompleteCourses[], DegreeProgram degreeProgram); /* FULL CONSTRUCTOR LIST FOR STUDENT DATA */
	~Student(); /* DESTRUCTOR */

	/* GETTERS / ACCESSORS */
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	DegreeProgram getDegreeProgram();
	int getAge();
	int* getTotalDays();

	/* SETTERS / MUTATORS */
	void setID(string id);
	void setFirstName(string first);
	void setLastName(string last);
	void setEmail(string email);
	void setDegreeProgram(DegreeProgram program);
	void setAge(int age);
	void setTotalDays(int days[]);

	static void printHeader(); /* FORMATS HEADER FOR READABILITY */

	void print(); /* DISPLAYS SPECIFIC STUDENT DATA */
};