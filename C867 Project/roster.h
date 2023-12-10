#pragma once
#include "student.h"

class Roster {
private:
	int lastIndex = -1;
	const static int numStudent = 5;

public:
	Student* classRosterArray[numStudent];
	void parse(string row); /* PARSE METHOD */
	void add(string studentID, /* PASSES STUDENT DATA INTO ADD METHOD WHICH CREATES THE STUDENT METHOD */
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram);
	void printAll(); /* CALLS PRINT() METHOD IN STUDENT CLASS FOR EACH STUDENT */
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();

	/* DECONSTRUCTOR */
	~Roster();
};