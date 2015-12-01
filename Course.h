#include <vector>
#include <string>
class Course{
	private:
		std::string course_ID;
		std::string course_name;
		int credit_hours;
		std::vector<std::string> students; // extract from txt
		std::vector<Asgn> asgns;
		std::vector<Asgn> getAsgns();
		std::vector<std::string> getStudents();
		int getStudentIndex(std::string stud);
		// need weightage field
	public:
		Course(std::string id, std::string nm, int hrs);
		bool checkStudent(std::string stud);
		float studentGrade(std::string stud);
		void studentViewGrades(std::string stud);
		void viewGrades(void);
		void enterGrades(std::string nm);
		void changeGrade(std::string nm, std::string stud);
		void createAsgn(std::string nm, int pts, std::string dln, std::string tp); // should deadline be type Time/Date?
		void deleteAsgn(std::string nm);
		void dataMaintenance(void); // updates course grades for students and course average for teacher
																		// when grades are added/changed
};
// create file i/o for grades: course_id, assignments, grades
