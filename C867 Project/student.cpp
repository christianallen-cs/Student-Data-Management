#include "student.h"
#include <iostream>
using std::string;

Student::Student() { /* PARAMETERLESS CONSTRUCTOR TO SET DEFAULT VALUES */
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->degreeProgram = DegreeProgram::SECURITY, NETWORK, SOFTWARE;
	this->age = 0;
	for (int i = 0; i < totalDaysArraySize; i++) this->totalDaysToCompleteCourses[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int totalDaysToCompleteCourses[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->degreeProgram = degreeProgram;
	this->age = age;
	for (int i = 0; i < totalDaysArraySize; i++) this->totalDaysToCompleteCourses[i] = totalDaysToCompleteCourses[i];
}

Student::~Student() {} /* DESTRUCTOR THAT DOES NOTHING - CREATES NOTHING */

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }
int Student::getAge() { return this->age; }
int* Student::getTotalDays() { return this->totalDaysToCompleteCourses; }

void Student::setID(string id) { this->studentID = id; }
void Student::setFirstName(string first) { this->firstName = first; }
void Student::setLastName(string last) { this->lastName = last; }
void Student::setEmail(string email) { this->email = email; }
void Student::setDegreeProgram(DegreeProgram program) { this->degreeProgram = program; }
void Student::setAge(int age) { this->age = age; }
void Student::setTotalDays(int days[]) 
{
	for (int i = 0; i < totalDaysArraySize; i++) this->totalDaysToCompleteCourses[i] = days[i];
}

void Student::printHeader() /* USED TO PRINT THE HEADER */
{
	cout << "Output Format: StudentID | First | Last | Email | Age | Days To Complete Courses | Degree Program \n";
}

void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getTotalDays()[0] << ',';
	cout << this->getTotalDays()[1] << ',';
	cout << this->getTotalDays()[2] << '\t';
	cout << DegreeProgramStrings[this->getDegreeProgram()] << '\n';
}