#include "Asgn.cpp"
#include <vector>
#include <string>
class Course{
	private:
		std::string course_ID;
		std::string course_name;
		int credit_hours;
		int weights[6];
		std::vector<std::string> students;
		std::vector<Asgn> asgns;
		void getInfo();
		std::vector<std::string> getStudents();
		std::vector<Asgn> getAsgns();
		int getStudentIndex(std::string stud);
		std::vector<float> studgrades;
		int endword();
		void addtobuffer(char letter);
		char str[5] = {0};
		int strsize = 0;
	public:
		Course(std::string id);
		void testPrint();
		bool checkStudent(std::string stud);
		void getGrades();
		float studentGrade(std::string stud);
		void studentViewGrades(std::string stud);
		void viewGrades(void);
		void enterGrades(std::string nm);
		void changeGrade(std::string nm, std::string stud);
		void createAsgn(std::string nm, int pts, std::string dln, std::string tp);
		void deleteAsgn(std::string nm);
		void dataMaintenance(void); // updates course grades for students and course average for teacher
		std::vector<Asgn> getVector(void);
																		// when grades are added/changed
};
