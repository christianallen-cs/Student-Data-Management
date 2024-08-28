# WESTERN GOVERNORS UNIVERSITY

## C867 - Scripting and Programming

## Overview

This project involves migrating a student management system to C++ from an existing platform. The goal is to manage student data including personal details, course completion days, and degree programs. The program includes two main classes: `Student` and `Roster`.

## Requirements

- **C++ Integrated Development Environment (IDE):** Visual Studio or Xcode
- **Files Required:**
  - `degree.h`: Contains the enumeration for degree programs.
  - `student.h` and `student.cpp`: Define and implement the `Student` class.
  - `roster.h` and `roster.cpp`: Define and implement the `Roster` class.
  - `main.cpp`: Contains the `main()` function and demonstrates the program functionality.

## Functionality

The program performs the following tasks:

1. **Print Course Information:**
   - Displays the course title, programming language used, WGU student ID, and name.

2. **Student Management:**
   - Adds students to the roster.
   - Prints all student data.
   - Prints invalid email addresses.
   - Calculates and prints the average days in courses for each student.
   - Prints student information by degree program.
   - Removes students from the roster by ID.

3. **Error Handling:**
   - Handles invalid email formats.
   - Manages attempts to remove non-existing students.

## Code Description

### `degree.h`

Defines the enumerated type `DegreeProgram` for degree programs: SECURITY, NETWORK, SOFTWARE.

### `student.h` and `student.cpp`

Defines the `Student` class with attributes such as student ID, first name, last name, email, age, days in course, and degree program. Includes methods for accessing and modifying these attributes, as well as a print method to display student information.

### `roster.h` and `roster.cpp`

Defines the `Roster` class with an array of student pointers. Includes methods to add, remove, and print student data. Also includes methods to print average days in course, invalid email addresses, and students by degree program.

### `main.cpp`

Contains the `main()` function, demonstrating the program’s functionality by creating an instance of the `Roster` class and performing various operations such as adding students, printing data, and removing students.
