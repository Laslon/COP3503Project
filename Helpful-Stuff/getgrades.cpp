#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int endword();
void addtobuffer(char letter);
float getCourseAvg();

char str[5] = {0};
int strsize=0;
vector<float> studgrades;

void addtobuffer(char letter)
{
	
	str [strsize] = letter;
	strsize++;	

}


int endword()
{
	
			float x = atof(string(str).c_str());
			studgrades.push_back(x);

	for(int i=0; i<5; i++)
	{
		str[i]=0;
	}
		strsize=0;				

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
					endword();
				}
				else 
				{
					addtobuffer(c);
				}
			}

		}
  
	
	}
	getCourseAvg();
	// studentGrade("Harry Potts");
	
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
	
}

/* Commented out because I don't have these methods on my laptop
float studentGrade(string stud)
{
	int si = getStudentIndex(stud);
	float avg = studgrades[si];
	cout << avg << endl;
	return avg;
}
*/
