
#include <iostream>
#include "Asgn.h"
#include <string>
#include <vector>
#include <iomanip>

int projweightage = 30; 
		
int hwweightage = 15;	

int testweightage = 20;

int quizweightage = 20;

int classworkweightage = 10;

int attenweightage = 5;  // these were sample weightages.

int outof = 100;          // important global variable.

float courseavg;

int numofstud = students.size();

float gradecalc(std::vector<assgn> & test,int studnum);

float calctype(std::vector<assgn> & test,std::string cat, int weightage, int studnum);

void Print(std::vector<assgn> & test, float studgrade[]);

float gradecalc(std::vector<assgn> & test,int studnum)				// Note this code can be expanded to take up 90 more lines. 
{
	/* Calculate grade in percentage */
	// note the types and their weightage. 
	float project = calctype(test,"Project",projweightage,studnum);

	float HW = calctype(test,"HW",hwweightage,studnum);

	float Test = calctype(test,"Test",testweightage,studnum); 			// note this Test is different from the test vector.

	float quiz = calctype(test,"Quiz",quizweightage,studnum);

	float classwork = calctype(test,"Classwork",classworkweightage,studnum);

	float atten = calctype(test,"Atten",attenweightage,studnum);

	float grade = project + HW + Test + quiz + classwork + atten;

	grade = (grade/outof)*100;
	
	outof=100;				// Reset out of so it doesn't affect next student.

	return grade;
}



float calctype(std::vector<assgn> & test,std::string cat, int weightage, int studnum)
{
	int total=0;

	int given=0;

	for (unsigned int i = 0; i < test.size(); i++)		// IMP NOTE: It has to be an unsigned int when going through a vector.
	{
		if(test[i].type==cat)
		{
			total+= test[i].points;
			given+= test[i].grades[studnum]; 
		}
	}

	if(total==0)				// no assignments of this category at all. 
	{
		outof = outof - weightage;		// account for this in % total.
		return 0;			// break out to avoid division by zero.
	}

	float per = ((float)given/total);			// you have an option to replace with decimal. 

	float result = per*weightage; 

	return result;

}

void Print(std::vector<assgn> & test, float studgrade[])
{
		std::cout << "Name" << "\t";		// row 1, cell 1

	std::cout << "Grade" << "\t";		// row 1, cell 2

	for (unsigned int i = 0; i < test.size(); i++)
	{
		std::cout << test[i].name<<"\t";
		if (i == test.size() - 1)		// Last value/run
		{
			std::cout << "\n";		// go to next line
		}
	}

	std::cout << "Assgn Due Date" << "\t";			// Column 1 row 1

	for (unsigned int i = 0; i < test.size(); i++)
	{
		std::cout << test[i].duedate<<"\t";
		if (i == test.size() - 1)		// Last value/run
		{
			std::cout << "\n";		// go to next line
		}
	}

	for (int i = 0; i < numofstud; i++)
	{
		std::cout << students[i] << "\t";			// First entry of each row is student name.
		std::cout << std::fixed << std::setprecision(2) << studgrade[i] << "\t";			// Second entry is calculated student grade.
		for (unsigned int j = 0; j <test.size();j++)
		{
			std::cout << test[j].grades[i]<<"\t";
			if (j == test.size() - 1)
			{
				std::cout << "\n";
			}

		}
	}
	std::cout << "Avg's" << "\t"; 
	std::cout << std::fixed << std::setprecision(2) <<  courseavg << "\t";				// print course average here
	
	// print assignments averages here
	for (unsigned int i = 0; i < test.size(); i++)		// IMP NOTE: It has to be an unsigned int when going through a vector.
	{
	float avg=0;
		for (int j = 0; j < numofstud; j++)
		{
			avg+= test[i].grades[j]; 
		}
	avg = avg/numofstud;
	std::cout << std::setprecision(2) << avg << "\t";
	}

}


int main()      // runs code that makes dummy assignments put them into a vector list 'test' and creates matrix from given info
{

  std::vector<std::string> studs = * new std::vector<std::string>();
	studs.push_back("Tana");
	studs.push_back("Aubree");
	studs.push_back("Jacob");
	
	assgn num1("Assgn1", "Project", 50,"11-05",studs);    

	assgn num2("Assgn2", "HW", 15,"11-05",studs);  

	/* assgn num3("Assgn3", "HW", 15,"11-05",studs);  

	assgn num4("Assgn4", "Test", 50,"11-05",studs);  

	assgn num5("Assgn5", "Test", 50,"11-05",studs);  

	assgn num6("Assgn6", "Quiz", 25,"11-05",studs);  

	assgn num7("Assgn7", "Quiz", 25,"11-05",studs);  

	assgn num8("Assgn8", "Classwork", 20,"11-05",studs);  

	assgn num9("Assgn9", "Classwork", 15,"11-05",studs);  

	assgn num10("Assgn10", "Atten", 5,"11-05",,studs);  

	assgn num11("Assgn11", "Atten", 5,"11-05",studs);   */

	std::vector<assgn> test;

	test.push_back(num1);

	test.push_back(num2);

	/* test.push_back(num3);

	test.push_back(num4);

	test.push_back(num5);

	test.push_back(num6);

	test.push_back(num7);

	test.push_back(num8);

	test.push_back(num9);

	test.push_back(num10);

	test.push_back(num11); */
	
	float studgrade[20] = {0};

	for(int i = 0; i<numofstud; i++)
	{
		studgrade[i] = gradecalc(test,i);
		courseavg+= studgrade[i];
	}

	courseavg = (courseavg/numofstud);
	
	/* Print out everything. */

	Print(test,studgrade);

	return 0;
}
