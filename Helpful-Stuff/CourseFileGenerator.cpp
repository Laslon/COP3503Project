#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int main(){
	ofstream c_file ("GeneratedCourseFile.txt", ofstream::out);
	string courses[] = {"PHY2048", "CHM2046", "MAC2313", "HUM2305",
											"COP3530", "MAC3473", "ENG2300"};
	int weights[][6] = { {30, 30, 20, 10, 5, 5}, {0, 25, 50, 10, 0, 15}, {0, 20, 40, 20, 10, 10},
											{30, 5, 30, 0, 15, 20}, {40, 20, 40, 0, 0, 0},
											{0, 20, 60, 20, 0, 0}, {50, 5, 20, 5, 10, 10}};
	int sizes[] = {33, 27, 23, 30, 33, 27, 27};
	int asgn_nums[][6] = {{0, 9, 1, 4, 2, 9}, {0, 9, 2, 4, 0, 9}, {0, 9, 2, 4, 3, 9},
												{2, 2, 1, 0, 4, 9}, {2, 4, 2, 0, 0, 0},
												{0, 4, 2, 4, 0, 0}, {3, 1, 1, 2, 2, 3}};
	srand (time(NULL));
	for(int i = 0; i < 7; i++){
		c_file << "Course\n" << courses[i] << "\n";
		int project_grades[asgn_nums[i][0]][sizes[i]];
		int homework_grades[asgn_nums[i][1]][sizes[i]];
		int test_grades[asgn_nums[i][2]][sizes[i]];
		int quiz_grades[asgn_nums[i][3]][sizes[i]];
		int classwork_grades[asgn_nums[i][4]][sizes[i]];
		int attendence_grades[asgn_nums[i][5]][sizes[i]];
		float averages[sizes[i]];
		for(int j = 0; j < sizes[i]; j++){
			int center = rand() % 36 + 62;
			float weighted_total = 0;
			float weighted_given = 0;
			float temp_total = 0;
			float temp_given = 0;
			if(asgn_nums[i][0] > 0){
				weighted_total += weights[i][0];
				for(int k = 0; k < asgn_nums[i][0]; k++){
					int temp_grade = (int)(50 * (center + rand() % 21 - 10) / (float)100);
					if (temp_grade > 100){
						temp_grade = 100;
					}
					project_grades[k][j] = temp_grade;
					temp_total += 50;
					temp_given += temp_grade;
				}
				weighted_given += weights[i][0] * (temp_given / temp_total);
				temp_total = 0;
				temp_given = 0;
			}
			if(asgn_nums[i][1] > 0){
				weighted_total += weights[i][1];
				for(int k = 0; k < asgn_nums[i][1]; k++){
					int temp_grade = (int)(20 * (center + rand() % 21 - 10) / (float)100);
					if (temp_grade > 100){
						temp_grade = 100;
					}
					homework_grades[k][j] = temp_grade;
					temp_total += 20;
					temp_given += temp_grade;
				}
				weighted_given += weights[i][1] * (temp_given / temp_total);
				temp_total = 0;
				temp_given = 0;
			}
			if(asgn_nums[i][2] > 0){
				weighted_total += weights[i][2];
				for(int k = 0; k < asgn_nums[i][2]; k++){
					int temp_grade = (int)(100 * (center + rand() % 21 - 10) / (float)100);
					if (temp_grade > 100){
						temp_grade = 100;
					}
					test_grades[k][j] = temp_grade;
					temp_total += 100;
					temp_given += temp_grade;
				}
				weighted_given += weights[i][2] * (temp_given / temp_total);
				temp_total = 0;
				temp_given = 0;
			}
			if(asgn_nums[i][3] > 0){
				weighted_total += weights[i][3];
				for(int k = 0; k < asgn_nums[i][3]; k++){
					int temp_grade = (int)(30 * (center + rand() % 21 - 10) / (float)100);
					if (temp_grade > 100){
						temp_grade = 100;
					}
					quiz_grades[k][j] = temp_grade;
					temp_total += 30;
					temp_given += temp_grade;
				}
				weighted_given += weights[i][3] * (temp_given / temp_total);
				temp_total = 0;
				temp_given = 0;
			}
			if(asgn_nums[i][4] > 0){
				weighted_total += weights[i][4];
				for(int k = 0; k < asgn_nums[i][4]; k++){
					int temp_grade = (int)(15 * (center + rand() % 21 - 10) / (float)100);
					if (temp_grade > 100){
						temp_grade = 100;
					}
					classwork_grades[k][j] = temp_grade;
					temp_total += 15;
					temp_given += temp_grade;
				}
				weighted_given += weights[i][4] * (temp_given / temp_total);
				temp_total = 0;
				temp_given = 0;
			}
			if(asgn_nums[i][5] > 0){
				weighted_total += weights[i][5];
				for(int k = 0; k < asgn_nums[i][5]; k++){
					int temp_grade = (int)(10 * (center + rand() % 21 - 10) / (float)100);
					if (temp_grade > 100){
						temp_grade = 100;
					}
					attendence_grades[k][j] = temp_grade;
					temp_total += 10;
					temp_given += temp_grade;
				}
				weighted_given += weights[i][5] * (temp_given / temp_total);
				temp_total = 0;
				temp_given = 0;
			}
			float weighted_average = 100 * weighted_given / weighted_total;
			c_file << fixed << setprecision(2) << weighted_average;
			if(j < sizes[i] -1){
				c_file << ";";
			}
		}
		c_file << "\nAssignments\n";
		if(asgn_nums[i][0] > 0){
			c_file << "Catagory\nProjects\n";
			for(int j = 0; j < asgn_nums[i][0]; j++){
				int day = (int)(63 / asgn_nums[i][0]) * (j + 0.5) + 15;
				int month = day / 30 + 8;
				day = day % 30 + 1;
				c_file << "Project " << (j + 1) << ";" << 50 << ";" << month << "/" << day << "\n";
				for(int k = 0; k < sizes[i]; k++){
					c_file << project_grades[j][k];
					if(k < sizes[i] - 1){
						c_file << ";";
					}
				}
				c_file << "\n";
			}
		}
		if(asgn_nums[i][1] > 0){
			c_file << "Catagory\nHomework\n";
			for(int j = 0; j < asgn_nums[i][1]; j++){
				int day = (int)(63 / asgn_nums[i][1]) * (j + 0.5) + 15;
				int month = day / 30 + 8;
				day = day % 30 + 1;
				c_file << "Homework " << (j + 1) << ";" << 20 << ";" << month << "/" << day << "\n";
				for(int k = 0; k < sizes[i]; k++){
					c_file << homework_grades[j][k];
					if(k < sizes[i] - 1){
						c_file << ";";
					}
				}
				c_file << "\n";
			}
		}
		if(asgn_nums[i][2] > 0){
			c_file << "Catagory\nTests\n";
			for(int j = 0; j < asgn_nums[i][2]; j++){
				int day = (int)(63 / asgn_nums[i][2]) * (j + 0.5) + 15;
				int month = day / 30 + 8;
				day = day % 30 + 1;
				c_file << "Test " << (j + 1) << ";" << 100 << ";" << month << "/" << day << "\n";
				for(int k = 0; k < sizes[i]; k++){
					c_file << test_grades[j][k];
					if(k < sizes[i] - 1){
						c_file << ";";
					}
				}
				c_file << "\n";
			}
		}
		if(asgn_nums[i][3] > 0){
			c_file << "Catagory\nQuizes\n";
			for(int j = 0; j < asgn_nums[i][3]; j++){
				int day = (int)(63 / asgn_nums[i][3]) * (j + 0.5) + 15;
				int month = day / 30 + 8;
				day = day % 30 + 1;
				c_file << "Quiz " << (j + 1) << ";" << 30 << ";" << month << "/" << day << "\n";
				for(int k = 0; k < sizes[i]; k++){
					c_file << quiz_grades[j][k];
					if(k < sizes[i] - 1){
						c_file << ";";
					}
				}
				c_file << "\n";
			}
		}
		if(asgn_nums[i][4] > 0){
			c_file << "Catagory\nClasswork\n";
			for(int j = 0; j < asgn_nums[i][4]; j++){
				int day = (int)(63 / asgn_nums[i][4]) * (j + 0.5) + 15;
				int month = day / 30 + 8;
				day = day % 30 + 1;
				c_file << "Classwork " << (j + 1) << ";" << 15 << ";" << month << "/" << day << "\n";
				for(int k = 0; k < sizes[i]; k++){
					c_file << classwork_grades[j][k];
					if(k < sizes[i] - 1){
						c_file << ";";
					}
				}
				c_file << "\n";
			}
		}
		if(asgn_nums[i][5] > 0){
			c_file << "Catagory\nAttendance\n";
			for(int j = 0; j < asgn_nums[i][5]; j++){
				int day = (63 / asgn_nums[i][5]) * j + 15;
				int month = day / 30 + 8;
				day = day % 30 + 1;
				c_file << "Attendance " << (j + 1) << ";" << 10 << ";" << month << "/" << day << "\n";
				for(int k = 0; k < sizes[i]; k++){
					c_file << attendence_grades[j][k];
					if(k < sizes[i] - 1){
						c_file << ";";
					}
				}
				c_file << "\n";
			}
		}
	}
	c_file.close();
	return 0;
}
