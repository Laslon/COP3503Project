#include "Asgn.h"
#include <iostream>
#include <limits>
// assignment class methods
// constructor
Asgn::Asgn(std::string nm, std::string tp, int pt, std::string dt, std::vector<std::string> st){ // how should students be loaded? (Passed or from file?)
	this->name = nm;
	this->type = tp;
	this->points = pt;
	this->duedate = dt;
	this->students = st;
	this->grades = getGrades();
}
// private method to get array of student grades for this assignment
std::vector<int> Asgn::getGrades(){
	// load from file
	std::vector<int> grds = * new std::vector<int>();
	grds.push_back(10);
	grds.push_back(5);
	grds.push_back(-1);
	return grds;
}
// assign grades for all students for this assignemnt
void Asgn::gradeAsgn(std::string nm){
	for(int i = 0; i < students.size(); i++){
		// display current student and grade
		std::cout << "Student: " << students[i] << ", Current Grade: ";
		if(grades[i] == -1){ // -1 indicates no existing grade
			std::cout << "None\n";
		}else{
			std::cout << grades[i] << "\n";
		}
		bool valid = false;
		int grd;
		// new grade inputed, validity checked
		while(!valid){
			std::cout << "Enter grade (-1 for no grade, -2 to exit): ";
			std::cin >> grd;
			if(grd < -2 || (grd > points && points != 0)){
				std::cout << "Invalid grade. Valid grade range for this assignment is 0 to " << points << ".\n"; 
			}else{
				valid = true;
			}
		}
		// if user does not exit, replace old grade with new one
		if(grd != -2){
			grades[i] = grd;
			std::cout << "\n";
		}else{
			i = students.size();
		}
	}
}
// change grade for a single student
void Asgn::changeGrade(std::string nm, std::string stud){
	int stud_index = -1;
	int i = 0;
	// find student in student array
	while(i < students.size() && stud_index == -1){
		if(students[i].compare(stud) == 0){
			stud_index = i;
		}
		i++;
	}
	// produce error if student not found
	if(stud_index == -1){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
		std::cout << "Student not found. Press enter to return to main menu.";
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
	}else{
		std::cout << "Student: " << students[stud_index] << ", Current Grade: ";
		if(grades[stud_index] == -1){
			std::cout << "None\n";
		}else{
			std::cout << grades[stud_index] << "\n";
		}
		bool valid = false;
		int grd;
		while(!valid){
			std::cout << "Enter grade : ";
			std::cin >> grd;
			if(grd < 0 || (grd > points && points != 0)){
				std::cout << "Invalid grade. Valid grade range for this assignment is 0 to " << points << ".\n"; 
			}else{
				valid = true;
			}
		}
		grades[stud_index] = grd;
	}
}
void Asgn::studentViewGrades(int stud_index){
	std::cout << "Assignment: " << name << ", Grade: " << grades[stud_index] << "\n";
}
void Asgn::viewGrades(void){
	std::cout << "Grades for " << name << "\n";
	for(int i = 0; i < students.size(); i++){
		std::cout << "Student: " << students[i] << ", Grade: ";
			if(grades[i] == -1){
				std::cout << "None";
			}else{
				std::cout << grades[i];
			}
			std::cout << "\n";
	}
}
std::string Asgn::getName(){
	return name;
}
