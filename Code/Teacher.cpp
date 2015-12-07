#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Professor
{
public:
    string professorpass;
    string professorid;
    string courseone;
    string coursetwo;
    string coursethree;

    Professor(string x, string y, string a, string b, string c){
    this->professorid = x;
    this->professorpass = y;
    this->courseone = a;
    this->coursetwo = b;
    this->coursethree = c;
    }//endofconstructor

    Professor(string x, string y, string a, string b){
    this->professorid = x;
    this->professorpass = y;
    this->courseone = a;
    this->coursetwo = b;
    cout << "Test" << endl;
    }//endofconstructor

};

void endline();
int endword();
void addtobuffer(char letter);
vector<string> courselist;
string profpass;
string profid;
string courses[3] = "ab";
int courseindex=0;
char str[30] = {0};
int strsize=0;

void addtobuffer(char letter)
{

	str [strsize] = letter;
	strsize++;

}

int endword()
{

    ifstream textfile("mainlist.txt");
	if (!textfile)
	{
	cout << "Error in opening file, check file name and its presence in directory";
	return 0;
	}
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

void test()
{
     ifstream textfile("mainlist.txt");
	if (!textfile)
	{
	cout << "Error in opening file, check file name and its presence in directory";
	}


}

void menu();

void teacher()
{


bool prof = false;				// GLOBAL Variables.
bool done = false;

     ifstream slist;
    slist.open("StudentList.txt");
    if(slist.fail())
    {
        cerr << "Error opening file." <<endl;
        exit(1);
    }//endoflistfail

    string word_teacher;
        string t_username;
        string ttemp_username;
        string t_password;
        string ttemp_password;

        cout <<"____Teacher Login____" <<endl;
        cout <<"Username: ";
        cin >> t_username;
        cout <<"Password: ";
        cin >>t_password;

        while(!slist.eof())
        {
            slist >> word_teacher;
            if(word_teacher == t_password)
            {
                ttemp_password = word_teacher;
                slist >> word_teacher;
                slist >> word_teacher;
                ttemp_username = word_teacher;
            }//end of password check
        }//end of while2
    if(ttemp_password==t_password && ttemp_username==t_username)
    {
        cout << "Successful Login!" << endl;
        ttemp_password.clear();
        // ttemp_username.clear();

    }//end of successful login
    else
    {
        cout << "Unsuccessful Login!" <<endl;
        menu();
    }//end of unsuccessful login



    	ifstream textfile("mainlist.txt");
	if (!textfile)
	{
	cout << "Error in opening file, check file name and its presence in directory";

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

					courseindex=0;
					//cout << profpass.getID() <<endl;
				}
			}

            if(profid==ttemp_username)
                    break;

		}

		if(temp=="Professors")
			prof = true;

	}
        bool created = false;

    string course1 = courses[0];
    string course2 = courses[1];
    string course3 = courses[2];

    cout << courses[0] << endl;
    cout << courses[1] << endl;
    cout << courses[2] << endl;


        if(courses[2]=="ab")
        {

            Professor Shrek = *new Professor(profid,profpass,course1,course2);
            created = true;
        }

    if(!created)
    Professor Shrek = *new Professor(profid,profpass,course1,course2,course3);


    cout << courses[0] << endl;
    cout << courses[1] << endl;
    cout << courses[2] << endl;


int choice1;
string chosencourse;
bool prohibit3 = false;
while(1>0)
{
    cout << "____Courses____" << endl;
    if (course3=="ab")
    {
        prohibit3 = true;
        cout << "0)" << "Go back to login" << endl;
        cout << "1)" << course1 << endl;
        cout << "2)" << course2 << endl;
        cin >> choice1;

        // course_menu=false;
    }//end of if
    else
    {
        cout << "0)" << "Go back to login" << endl;
        cout << "1)" << course1 << endl;
        cout << "2)" << course2 << endl;
        cout << "3)" << course3 << endl;
        cin >> choice1;
        // course_menu=false;
    }//end of else
    if(choice1==0)
    {
        break;
    }
    if(choice1==1)
    {
        chosencourse = course1;
    }
    if(choice1==2)
    {
        chosencourse = course2;
    }
    if(choice1==3 && !prohibit3)
    {
        chosencourse = course3;
    }
    if(choice1==1 || choice1==2 || (choice1==3 && !prohibit3))
        {
            while(1>0)
{
    cout << "____Teacher Menu____" << endl;
    cout << "1) View Grades" << endl;
    cout << "2) Create Assignment" << endl;
    cout << "3) Delete Assignment" << endl;
    cout << "4) Grade Assignment" << endl;
    cout << "5) Change Grade" << endl;
    cout << "6) Go back to course menu" << endl;
    cout << "Enter choice: ";
    cin >> choice1;
    if(choice1==1)
    {
        //viewGrades();
    }
if(choice1==2)
    {
        //createAsgn();
    }
if(choice1==3)
    {
        //deleteAsgn();
    }
if(choice1==4)
    {
        //gradeAsgn();
    }
if(choice1==5)
    {
        //changeGrade();
    }
if(choice1==6)
    {
        cout << "Going back to course menu!" << endl;
        //choice.clear();
       // dataMaintenance(); UNCOMMENT THIS
        break;
    }
    else
    {
        cout << "Invalid input!" <<endl;
    }

    // teach_menu=false;
}//end of while menu
        }
}//end of course while

        menu();

}//end of teacher

void menu()
{
    int choice;
    cout << "____Login Menu____" << endl;
    cout << "Enter 1) for Student Login" << endl;
    cout << "Enter 2) for Teacher Login" << endl;
    cin >> choice;

    ifstream slist;
    slist.open("StudentList.txt");
    if(slist.fail())
    {
        cerr << "Error opening file." <<endl;
        exit(1);
    }//endoflistfail

    if(choice==1)
    {
        string word_student;
        string s_username;
        string stemp_username;
        string s_password;
        string stemp_password;

        cout <<"____Student Login____" <<endl;
        cout <<"Username: ";
        cin >> s_username;
        cout <<"Password: ";
        cin >>s_password;

        while(!slist.eof())
        {
            slist >> word_student;
            if(word_student == s_password)
            {
                stemp_password = word_student;
                slist >> word_student;
                slist >> word_student;
                stemp_username = word_student;
            }//endofpasswordcheck
        }//endofwhile
    if(stemp_password == s_password && stemp_username == s_username)
    {
        cout << "Successful Login!" <<endl;
        stemp_password.clear();
        stemp_username.clear();
    }//end of successful login
    else
    {
        cout <<"Unsuccessful Login!" << endl;
        menu();
    }//end of unsuccessful login

    }//endofchoice1

    if(choice==2)
    {
       teacher();

    }//end of choice2
}//endofmenu

int main()
{
    endword();
   menu();
    return 0;
}
