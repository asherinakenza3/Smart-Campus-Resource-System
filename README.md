# Smart Campus Student Resource Management System

## Project Description

The Smart Campus Student Resource Management System is a console-based C++ application developed for the CC105 Data Structures Terminal Assessment.

The system manages student records and campus resources while demonstrating the use of data structures and algorithms covered in Weeks 1–5.

## Features

- Add student records
- Display student records
- Search students using Linear Search
- Update student information
- Delete student records
- Prevent duplicate Student IDs
- Validate user input
- Manage campus resources
- Update resource capacity
- Display a 2D resource utilization matrix
- Calculate row and column utilization totals
- Generate a summary report

## Data Structures and Concepts Used

- Abstract Data Types (ADT)
- Structures
- Static Arrays
- Array Traversal
- Linear Search
- Pointers
- Dynamic Memory Allocation
- 2D Arrays
- Modular Functions
- Input Validation
- Big-O Analysis

## Compilation

Compile the program using:

g++ src/main.cpp -o smartcampus

## Run

On Windows PowerShell:

./smartcampus

## Main Menu

1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Manage Campus Resources
7. Display Resource Matrix
8. Analyze Resource Utilization
9. Generate Report
10. Exit

## Resource Utilization Matrix

The system uses a 4x4 matrix representing resource utilization across four departments and four campus resources.

The program calculates both row totals and column totals.

## Memory Management

Campus resources are dynamically allocated using `new[]` and released using `delete[]` before the program terminates to prevent memory leaks.

## Authors

BSIT Students  
National Teachers College