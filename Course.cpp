#include "Course.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
// course class methods
// constructor
Course::Course(string id){
	this->course_ID = id;
	this->course_name = "";
	this->credit_hours = 0;
	for(int i = 0; i < 6; i++){
		this->weights[i] = 0;
	}
	getInfo();
	this->students = getStudents();
	this->asgns = getAsgns();
}
// load course_name, credit_hours, and weights from file
void Course::getInfo(){
	std::cout << "Getting info\n";
	ifstream main_list("MainList.txt");
	if(!main_list.is_open()){
		std::cout << "Error: Couldn't open MainList file\n";
		return;
	}
	std::string temp;
	bool header_found = false;
	// find "Courses" header
	std::cout << "Searching for Courses header\n";
	int c = 0;
	while(!main_list.eof() && !header_found){
		getline(main_list, temp);
		if(temp.compare(0, 7, "Courses") == 0){
			header_found = true;
			std::cout << "Header found\n";
		}
		//std::cout << temp << "\n";
	}
	// print error and return if header not found
	if(!header_found){
		std::cout << "Error: Courses missing!\n";
		return;
	}
	header_found = false; // reset
	bool course_found = false;
	// find course id, stop looking when found, or next header is reached, or eof reached
	std::cout << "Searching for course ID\n";
	while(!main_list.eof() && !header_found && !course_found){
		getline(main_list, temp, ';');
		if(temp.compare(0, 7, course_ID) == 0){
			course_found = true;
			std::cout << "Course ID found\n";
		}else if(temp.compare(0, 8, "Students")){
			header_found = true;
		}
	}
	// print error and return if course id not found
	if(!course_found){
		std::cout << "Error: Course not found.\n";
		return;
	}
	std::cout << "Setting info\n";
	getline(main_list, temp, ';');
	course_name = temp;
	getline(main_list, temp, ';');
	credit_hours = atoi(temp.c_str());
	for(int i = 0; i < 6; i++){
		getline(main_list, temp, ';');
		weights[i] = atoi(temp.c_str());
	}
	std::cout << "Closing file\n";
	main_list.close();
}
// load students from MainFile
std::vector<std::string> Course::getStudents(){
	std::vector<std::string> studs = * new std::vector<std::string>();
	/*ifstream main_list("MainList.txt");
	char temp_c[128];
	// find "Students" header
	bool header_found = false;
	while(!main_list.eof() && !header_found){
		main_list.getline(temp_c, 128);
		std::string temp_s(temp_c);
		if(temp_s.compare("Students") == 0){
			header_found = true;
		}
	}
	// print error and return empty vector if "Students" header not found
	if(!header_found){
		std::cout << "Error: Students missing!\n";
		return studs;
	}
	header_found = false; // reset
	while(!main_list.eof() && !header_found){
		
	}*/
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
void Course::testPrint(){
	std::cout << "Loaded course info: \n";
	std::cout << "ID: " << course_ID << "\n";
	std::cout << "Name: " << course_name << "\n";
	std::cout << "Credits: " << credit_hours << "\n";
	std::cout << "Weights:\n";
	std::cout << "\tProjects: " << weights[0] << "%\n";
	std::cout << "\tHomework: " << weights[1] << "%\n";
	std::cout << "\tTests: " << weights[2] << "%\n";
	std::cout << "\tQuizes: " << weights[3] << "%\n";
	std::cout << "\tClasswork: " << weights[4] << "%\n";
	std::cout << "\tAttendance: " << weights[0] << "%\n";
	std::cout << "Students: " << "Unimplemnted" << "\n";
	std::cout << "Assignments: " << "Unimplemnted" << "\n";
}
// get the index of a student in this course's student array
// returns -1 if student not found
int Course::getStudentIndex(std::string stud){
	int stud_index = -1;
	int i = 0;
	while(i < students.size() && stud_index == -1){
		if(students[i].compare(stud) == 0){
			stud_index = i;
		}
		i++;
	}
	return stud_index;
}
// check to see if inputed student name is found in this course's student array
bool Course::checkStudent(std::string stud){
	int stud_index = getStudentIndex(stud);
	if(stud_index == -1){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
		std::cout << "Student not found. Press enter to continue.";
		std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
		return false;
	}else{
		return true;
	}
}
// return a specific students course average
float Course::studentGrade(std::string stud){
	float avg = 90; // to do: get averages from file
	return avg;
}
// display all of this course's assignment grades for a specific student
void Course::studentViewGrades(std::string stud){
	int stud_index = getStudentIndex(stud);
	std::cout << "Course Average: " << studentGrade(stud) << "\n";
	for(int j = 0; j < asgns.size(); j++){
		asgns[j].studentViewGrades(stud_index);
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
	int index = -1;
	for(int i =0; asgns.size()-1 <= index; i++)
	{
		if(asgns[i].getName()== nm)
		{
			index = i;
		}
	}
	if(index == -1)
	{
		
	}
	else
	{
		asgns.erase(asgns.begin()+index);
		
	}
	cout << "Assignment deleted (Maybe)";
}
void Course::dataMaintenance(void){
	
}
