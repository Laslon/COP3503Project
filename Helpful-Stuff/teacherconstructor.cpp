#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

void endline();
int endword();
void addtobuffer(char letter);

string profpass;
string profid;
string courses[3];
int courseindex=0;
char str[30] = {0};
int strsize=0;

/* 
Professors
SebastianChu;00089;PHY2048;CHM2046
AndreaCostello;00019;ENG2300;COP3530;HUM2305
WilsonPlitz;00042;MAC2313;MAC3473
Courses
*/

bool prof = false;				// GLOBAL Variables.
bool done = false;

int main()
{
	ifstream textfile("mainlist.txt");
	if (!textfile)
	{
	cout << "Error in opening file, check file name and its presence in directory";
	return 0;
	}
	string s;
	char c;
	while(getline(textfile, s)) // Read each character one at a time (to account for no spaces).
	{
		string temp = s;
  
		if(temp=="Courses")
			break;
		if(prof)
		{
			
			for(int i=0; i<s.size();i++)
			{
			 	c = s[i];
				if(c==';')
				{
					// cout << string(str) << endl;
					endword();
				}
				else 
				{
					addtobuffer(c);
				}
				if(i==(s.size()-1)) 				//last run of loop
				{
					endword();
					// Construct teacher object: Teacher i = New Teacher(profid,profpass,courses);
					courseindex=0;
				}
			}
			
			
			
		}

		if(temp=="Professors")
			prof = true;
	
	}
}

void addtobuffer(char letter)
{
	
	str [strsize] = letter;
	strsize++;	

}


int endword()
{
		bool alpha = false;
		bool numpres = false; 
		for(int i = 0; i<=strsize; i++)	
		{
			if(int(str[i])>47 && int(str[i])<58) 
			{
				numpres = true;								
			}
			if((int(str[i])>64 && int(str[i])<91) || (int(str[i])>96 && int(str[i])<123)) 		
			{
				alpha = true;
			}
			
		}
		if(alpha && !numpres)
		{
			profpass = string(str);
		 	cout << "this is the password " << profpass << endl;
			
		}
		else if(numpres && !alpha)
		{
			profid = string(str);
			cout << "this is the username " << profid << endl; 
		}
		else if(alpha && numpres)
		{
			courses[courseindex] = string(str);
			cout << "this is a course "  << courses[courseindex] ;	
			courseindex++;
			cout << " (number " << courseindex << ")" << endl;	
		}
		else
		{ 
			cout << "uncategorizable error" << endl; 
		}
		for(int i=0; i<=19; i++)				// Empty the char array.
		{
			str[i]=0;
		}
		strsize=0;				

}
