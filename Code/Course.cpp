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
	ifstream main_list("MainList.txt");
	if(!main_list.is_open()){
		std::cout << "Error: Couldn't open MainList file\n";
		return;
	}
	std::string temp;
	bool header_found = false;
	// find "Courses" header
	while(!main_list.eof() && !header_found){
		getline(main_list, temp);
		if(temp.compare("Courses") == 0){
			header_found = true;
		}
	}
	// print error and return if header not found
	if(!header_found){
		std::cout << "Error: Courses missing!\n";
		return;
	}
	header_found = false; // reset
	bool course_found = false;
	// find course id, stop looking when found, or next header is reached, or eof reached
	while(!main_list.eof() && !header_found && !course_found){
		getline(main_list, temp);
		if(temp.compare(0, 7, course_ID) == 0){
			course_found = true;
		}else if(temp.compare(0, 8, "Students") == 0){
			header_found = true;
		}
	}
	// print error and return if course id not found
	if(!course_found){
		std::cout << "Error: Course not found.\n";
		return;
	}
	// extract tokens
	temp = temp.substr(8, temp.size() - 8);
	int i = 0;
	while(temp[i] != ';'){
		i++;
	}
	course_name = temp.substr(0, i);
	temp = temp.substr(i + 1, temp.size() - i);
	i = 0;
	while(temp[i] != ';'){
		i++;
	}
	credit_hours = atoi(temp.substr(0, i).c_str());
	temp = temp.substr(i + 1, temp.size() - i);
	for(int j = 0; j < 6; j++){
		i = 0;
		while(temp[i] != ';' && i < temp.size()){
		i++;
		}
		weights[j] = atoi(temp.substr(0, i).c_str());
		if(j < 5){
			temp = temp.substr(i + 1, temp.size() - i);
		}
	}
	main_list.close();
}
// load students from MainFile
std::vector<std::string> Course::getStudents(){
	std::vector<std::string> studs = * new std::vector<std::string>();
	ifstream main_list("MainList.txt");
	if(!main_list.is_open()){
		std::cout << "Error: Couldn't open MainList file\n";
		return studs;
	}
	std::string temp;
	bool header_found = false;
	// find "Students in Courses" header
	while(!main_list.eof() && !header_found){
		getline(main_list, temp);
		if(temp.compare("Students in Courses") == 0){
			header_found = true;
		}
	}
	// print error and return if header not found
	if(!header_found){
		std::cout << "Error: Courses missing!\n";
		return studs;
	}
	header_found = false; // reset
	bool course_found = false;
	// find course id, stop looking when found, or eof reached
	while(!main_list.eof() && !header_found && !course_found){
		getline(main_list, temp);
		if(temp.compare(0, 7, course_ID) == 0){
			course_found = true;
		}
	}
	// print error and return if course id not found
	if(!course_found){
		std::cout << "Error: Course not found.\n";
		return studs;
	}
	getline(main_list, temp);
	bool is_name = true;
	while(is_name){
		getline(main_list, temp, ';');
		for(int i = 0; i < temp.size(); i++){
			if(!isalpha((int)temp[i]) && temp[i] != ' '){
				is_name = false;
			}
		}
		if(is_name){
			studs.push_back(temp);
			getline(main_list, temp);
		}
	}
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
std::vector<Asgn> Course::getVector(){
	return this->asgns;
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
		cout << "Assignment does not exist.";
	}
	else
	{
		asgns.erase(asgns.begin()+index);
		
	}
	cout << "Assignment deleted (Maybe)";
}
void Course::dataMaintenance(void){
	string t = course_name + ".txt";;
	const char* text = t.c_str();
	cout << text; 
	ofstream c_file (text, ofstream::out);
	c_file << course_name << "/n" << "size" << "/n" << students.size();
	
	//still needs to add student averages
	c_file << "Assignments";
	int asgnsWritten = 0;

	//|\__/,|   (`\
	//|_ _  |.--.) )
	//( T   )     /
	//(((^_(((/(((_>
	string cats[] = {"Projects","Homework","Tests","Quizzes","Classwork","Attendence"};
	for(int c = 0; c >= 6;c++)
	{
		
		
		while(asgns.size() == asgnsWritten)
		{
			int j = 0;
			for(j = 0; j < asgns.size(); j++)
			{
				
				if(asgns[j].getName().compare(cats[c]))
				{
					c_file<< "Category" << "/n" << cats[c];
					c_file << cats[c];
				}
			}
			for(j = 0; j < asgns.size(); j++)
			{
				if(asgns[j].getName().compare(cats[c]))
				{
					c_file << asgns[j].getName()<< ";" <<asgns[j].getPoints();
					//print grades
				}
			}
		}
	}
	c_file.close();
}
