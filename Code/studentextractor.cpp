#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void endline();
int endword();
void addtobuffer(char letter);

string studpass;
string studid;
string courses[4];
int credithours;
float studavg;
int courseindex=0;
char str[30] = {0};
int strsize=0;

string desiredstud = "Kylie Rose"; // SAMPLE


/* 
Students
Weiss Adams;45033;MAC2313;HUM2305;COP3530;MAC3473;56;83.01
Emile Airn;34215;PHY2048;CHM2046;MAC3473;ENG2300;48;76.64
Christine Alpine;34151;PHY2048;CHM2046;COP3530;MAC3473;52;84.21
Professors
*/

bool stud = false;				// GLOBAL Variables.
bool usernamedone = false;
bool credithrdone = false;
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
  
		if(temp=="Professors")
			break;
		if(stud)
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
				if(i==(s.size()-1)) 				//last run of loop
				{
					endword();
					courseindex=0;
				}
			}
			if(studpass==desiredstud)
				break;
			
			
		}

		if(temp=="Students")
			stud= true;
	
	}

	cout << "end results: " << studid << " " << studpass << " " << "their four courses " << courses[0] << " " << courses[1] << " " << courses[2] << " " << courses[3] << " " << credithours << " " << studavg << endl;

	// CREATE YOUR STUDENT OBJECT HERE NOW.
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
			studpass = string(str);
		 //	cout << "this is the password " << studpass << endl;
			
		}
		else if(numpres && !alpha)
		{
			if(!usernamedone && !credithrdone)
			{
				studid = string(str);
			//	cout << "this is the username " << studid << endl;
				usernamedone = true;
			}
			else if(usernamedone && !credithrdone)
			{
				credithours = atoi(string(str).c_str());
			//	cout << "this is the credit hour number " << credithours << endl;
				credithrdone = true;
			}
			else if(usernamedone && credithrdone)
			{
				studavg = atof(string(str).c_str());
			//	cout << "this is the student's average " << studavg << endl; 
				usernamedone = false;
				credithrdone = false;
			}
		}
		else if(alpha && numpres)
		{
			courses[courseindex] = string(str);
			// cout << "this is a course "  << courses[courseindex] ;	
			courseindex++;
			// cout << " (number " << courseindex << ")" << endl;	
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
