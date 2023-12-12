#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
using std::string;

/* PARSES EACH ROW ONE BY ONE */
void Roster::parse(string studentData)
{
	std::vector<string> tokens;
	DegreeProgram degreeprogram;
	for (int i = 0; i < numStudent; ++i) {
		std::stringstream ss(studentData);

		while (ss.good()) {
			string subStr;
			std::getline(ss, subStr, ',');
			tokens.push_back(subStr);
		}

		if (tokens[8] == "SECURITY") {
			degreeprogram = DegreeProgram::SECURITY;
		}
		if (tokens[8] == "NETWORK") {
			degreeprogram = DegreeProgram::NETWORK;
		}
		if (tokens[8] == "SOFTWARE") {
			degreeprogram = DegreeProgram::SOFTWARE;
		}
	}
	Roster::add(tokens.at(0), tokens.at(1), tokens.at(2), tokens.at(3), stoi(tokens.at(4)), stoi(tokens.at(5)),
		stoi(tokens.at(6)), stoi(tokens.at(7)), degreeprogram);
}

/* RECEIVES STUDENT RECORD FROM PARSE, AND CREATES A NEW STUDENT OBJECT */
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	int numberOfDays[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, numberOfDays, degreeprogram);
}

/* REMOVES STUDENT RECORD WITH ID INPUT */
void Roster::remove(string studentID)
{
	std::cout << "Removing student record with student ID: " << studentID << "..." << std::flush;
	for (int x = 0; x < numStudent; ++x) {
		if (classRosterArray[x] == nullptr) {
		std::cout << "Record does not exist" << std::endl;
		break;
		}
		else if (studentID == classRosterArray[x]->Student::getID()) {
			classRosterArray[x] = nullptr;
			std::cout << "Student record removed" << std::endl;
		}
	}
}


/* DISPLAYS ALL STUDENTS USING TAB SEPERATED OUTPUT */
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i < numStudent; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Student::print();
		}
	}
}

/* PRINTS AVERAGE DAYS STUDENT TAKES TO COMPLETE COURSE */
void Roster::printAverageDaysInCourse(string studentID) {
	for (int w = 0; w < numStudent; ++w) {
		if (studentID == classRosterArray[w]->Student::getID()) {
			int* day = classRosterArray[w]->getTotalDays();
			std::cout << studentID << "'s Average Days In Course: ";
			int avg = (day[0] + day[1] + day[2]) / 3;
			std::cout << avg << std::endl;
		}
	}
}

/* PRINTS INVALID EMAILS IF EMAIL DOES NOT CONTAIN "@" / "." OR HAS A SPACE */
void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string emails = (classRosterArray[i]->getEmail());
		if (emails.find("@") == string::npos || emails.find(".") == string::npos || emails.find(" ") != string::npos) {
			any = true;
			cout << emails << ": " << "Invalid Email Format" << std::endl; /* IF INVALID EMAIL IS FOUND WILL PRINT TO USER */
		}
	}
	if (!any) cout << "None" << std::endl; /* WILL PRINT IF NO INVALID EMAILS ARE FOUND */
}

/* RETURNS EACH RECORD WITH SELECT DEGREE PROGRAM */
void Roster::printByDegreeProgram(DegreeProgram degree) {
	std::cout << std::endl << "Printing by degree" << std::endl;
	for (int i = 0; i < numStudent; ++i) {
		if (classRosterArray[i] != nullptr) {
			if (degree == classRosterArray[i]->Student::getDegreeProgram()) {
				classRosterArray[i]->Student::print();
			}
		}
	}
	std::cout << std::endl;
}

/* DESTRUCTOR */
Roster::~Roster() {}