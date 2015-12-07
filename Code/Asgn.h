#include <string>
#include <vector>
class Asgn{
	private:
		std::vector<std::string> students; // students in course
		std::vector<int> grades; // indices match students; = -1 if no grade
		std::string name;
		std::string type;
		int points;
		std::string duedate;
	public:
		Asgn(std::string nm, std::string typ, int pt, std::string dt, std::vector<std::string> st);
		// create other constructors for when not creating snew assignment?
		void gradeAsgn(std::string nm); // enter grade for all students
		void changeGrade(std::string nm, std::string stud); // enter grade for 1 student
		void studentViewGrades(int stud_index);
		void viewGrades();
		std::string getName();
		void pushGrade(double grade);
		
}; 
