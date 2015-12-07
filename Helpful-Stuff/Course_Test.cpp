#include <limits>
#include <iostream>
#include "Course.cpp"
int main(){
	Course * tst_crs = new Course(std::string("TST0000"), std::string("Testing 101"), 1);
	bool exit = false;
	while(!exit){
		std::cout << "\n\tMain Menu\n";
		std::cout << "1) View Student Course Grade\n";
		std::cout << "2) View Student Assignment Grades\n";
		std::cout << "3) View All Student Assignment Grades\n";
		std::cout << "4) Enter Grades\n";
		std::cout << "5) Change Grade\n";
		std::cout << "6) Create Assignment\n";
		std::cout << "7) Delete Assignment\n";
		std::cout << "8) Maintain Data\n";
		std::cout << "10) Exit\n";
		std::cout << "Enter an option number: ";
		int main_option;
		std::cin >> main_option;
		switch(main_option){
			case 1:{
				std::cout << "\nViewing Student Course Grade\n";
				bool valid = false;
				std::string stud;
				while(!valid){
					std::cout << "Enter student name or \"cancel\": ";
					std::cin >> stud;
					if(stud.compare("cancel") == 0){
						valid = true; // just to exit loop
					}else{
						valid = tst_crs->checkStudent(stud);
					}
				}
				if(!stud.compare("cancel") == 0){
					std::cout << "Grade: " << tst_crs->studentGrade(stud) << "\n";
					std::cin.clear();
					std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
					std::cout << "Press enter to continue.";
					std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
				}
				break;
			}
			case 2:{
				std::cout << "\nViewing Student Assignment Grades\n";
				bool valid = false;
				std::string stud;
				while(!valid){
					std::cout << "Enter student name or \"cancel\": ";
					std::cin >> stud;
					if(stud.compare("cancel") == 0){
						valid = true; // just to exit loop
					}else{
						valid = tst_crs->checkStudent(stud);
					}
				}
				if(!stud.compare("cancel") == 0){
					std::cout << "\n";
					tst_crs->studentViewGrades(stud);
					std::cin.clear();
					std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
					std::cout << "Press enter to continue.";
					std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
				}
				break;
			}
			case 3:
				std::cout << "\nViewing All Student Assignment Grades\n";
				break;
			case 4:
				std::cout << "\nEntering Grades\n";
				break;
			case 5:
				std::cout << "\nChanging Grades\n";
				break;
			case 6:
				std::cout << "\nCreating Assignment\n";
				break;
			case 7:
				std::cout << "\nDeleting Assignment\n";
				break;
			case 8:
				std::cout << "\nMaintaining Data\n";
				break;
			case 10:
				exit = true;
				break;
			default:
				std::cin.clear();
				std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
				std::cout << "Invalid input. Press enter to continue.";
				std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );
				break;
		}
	}
	return 0;
} 
