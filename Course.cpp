#include "Course.h"
#include <iostream>
using namespace std;
// course class methods
// constructor
Course::Course(string id, string name, int hours){
	this->course_ID = id;
	this->course_name = name;
	this->credit_hours = hours;
	this->students = getStudents();
	this->asgns = getAsgns();
}
std::vector<std::string> Course::getStudents(){
	// load from file
	std::vector<std::string> studs = * new std::vector<std::string>();
	studs.push_back("Tana");
	studs.push_back("Aubree");
	studs.push_back("Jacob");
	return studs;
}
std::vector<Asgn> Course::getAsgns(){
	// load assignments from wherever
	std::vector<Asgn> a = * new std::vector<Asgn>();
	a.push_back(* new Asgn("Test Assignment", "Test Type", 15, "12/31/2015", students));
	return a;
}
int Course::studentGrade(int student){
	// return student grade in course obtained from multi-dimensional array
	int avg = 90;
	return avg;
}
void Course::studentViewGrades(std::string stud){
	int stud_index = -1;
	int i = 0;
	while(i < students.size() && stud_index == -1){
		if(students[i].compare(stud) == 0){
			stud_index = i;
		}
		i++;
	}
	if(stud_index == -1){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
		std::cout << "Student not found. Press enter to return to main menu.";
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
	}else{
		for(int j = 0; j < asgns.size(); j++){
			asgns[j].studentViewGrades(stud_index);
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
		std::cout << "Press enter to continue.";
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
	}
}
void Course::viewGrades(void){
	for(int i = 0; i < asgns.size(); i++){
		asgns[i].viewGrades();
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
	std::cout << "Press enter to continue.";
	std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
}
void Course::enterGrades(std::string nm){
	bool found = false;
	for(int i = 0; i < asgns.size(); i++){
		if(asgns[i].getName().compare(nm) == 0){
			asgns[i].gradeAsgn(nm);
			i = asgns.size();
			found = true;
		}
	}
	if(!found){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
		std::cout << "Assignment not found. Press enter to return to main menu.";
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
	}
}
void Course::changeGrade(std::string nm, std::string stud){
	int asgn_index = -1;
	for(int i = 0; i < asgns.size(); i++){
		if(asgns[i].getName().compare(nm) ==  0){
			asgn_index = i;
			i = asgns.size();
		}
	}
	if(asgn_index != -1){
		asgns[asgn_index].changeGrade(nm, stud);
	}else{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
		std::cout << "Assignment not found. Press enter to return to main menu.";
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
	}
}
void Course::createAsgn(std::string nm, int total_points, std::string deadline, std::string type){
	asgns.push_back(Asgn(nm, type, total_points, deadline, getStudents()));
	cout << "Assignment created ";
}
void Course::deleteAsgn(std::string nm){
	cout << "Assignment deleted (not really)";
}
void Course::dataMaintenance(void){
	
}
