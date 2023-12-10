// C867 Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

int main()
{
	cout << "Scripting and Programming - Applications - C867" << std::endl;
	cout << "Programming Language: C++" << std::endl;
	cout << "Student ID: 011234151" << std::endl;
	cout << "Christian Allen" << std::endl;

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Christian,Allen,call730@wgu.edu,23,7,7,14,SOFTWARE"
	};

	const int numStudent = 5;
	Roster classRoster;

	for (int i = 0; i < numStudent; i++) classRoster.parse(studentData[i]);
	cout << "Displaying All Students: " << std::endl;
	classRoster.printAll();
	cout << std::endl;

	cout << "List Of Invalid Emails: " << std::endl;
	classRoster.printInvalidEmails();

	cout << "Average Days In Course, Per Student: " << std::endl;
	for (int i = 0; i < numStudent; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->Student::getID());
	}

	/* PSUEDO CODE CONVERTED */
	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");
	cout << std::endl;
	classRoster.printAll();
	cout << std::endl;
	classRoster.remove("A3");
	cout << std::endl;

	/* DESTRUCTOR TO RELEASE MEMORY IN ROSTER */
	classRoster.~Roster();

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file