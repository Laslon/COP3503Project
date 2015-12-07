#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "Course.cpp"

using namespace std;

int makefloat();
void addtothebuffer(char letter);
float getCourseAvg();
void getGrades(string id);
float studentGrade(string stud);

char str[5] = {0};
int strsize_g=0;
vector<float> studgrades;

void addtothebuffer(char letter)
{
	str [strsize_g] = letter;
	strsize_g++;	
}



int makefloat()
{
	
			float x = atof(string(str).c_str());
			studgrades.push_back(x);

	for(int i=0; i<5; i++)
	{
		str[i]=0;
	}
		strsize_g=0;				

}

int numofstud;

float courseavg;

int main()
{
	getGrades("PHY2048"); // replace with course_ID
}

void getGrades(string id)
{	

id = id.append(".txt");

ifstream textfile(id.c_str());
	if (!textfile)
	{
	cout << "Error in opening file, check file name and its presence in directory";
	}
	else
{
	int linenum = 0;
	string s;
	char c;
	while(getline(textfile, s)) // Read each character one at a time (to account for no spaces).
	{
		string temp = s;
		linenum++;
		if(linenum==3)
		numofstud = atoi(temp.c_str());
		if(linenum==7)
		{
			for(int i=0; i<s.size();i++)
			{
			 	c = s[i];
				if(c==';')
				{
					makefloat();
				}
				else 
				{
					addtothebuffer(c);
				}
				if(i==(s.size()-1)) 				//last run of loop
				{
					makefloat();
				}
			}

		}
  
	
	}
	for (unsigned int i = 0; i < studgrades.size(); i++)		// IMP NOTE: It has to be an unsigned int when going through a vector.
	{
		cout << studgrades[i] << "/t";
	}
}

}

float getCourseAvg()
{
	for (unsigned int i = 0; i < studgrades.size(); i++)
	{
		courseavg+=studgrades[i];
	}

	courseavg = (courseavg/numofstud);

	cout << courseavg << endl;
	
	return courseavg;
	
}


float studentGrade(string stud)
{
	int si = getStudentIndex(stud);
	float avg = studgrades[si];
	cout << avg << endl;
	return avg;
}

