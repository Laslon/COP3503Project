#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include "Course.cpp"

using namespace std;

void teacher()
{
    cout << "____Teacher Menu____" << endl;
    cout << "1) View Grades" << endl;
    cout << "2) Create Assignment" << endl;
    cout << "3) Delete Assignment" << endl;
    cout << "4) Grade Assignment" << endl;
    cout << "5) Change Grade" << endl;
    cout << "6) Exit" << endl;
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
        string word_teacher;
        string t_username;
        string ttemp_username;
        string t_password;
        string ttemp_password;

        cout <<"____Teacher Login____" <<endl;
        cout <"Username: ";
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
        ttemp_username.clear();
    }//end of successful login
    else
    {
        cout << "Unsuccessful Login!" <<endl;
        menu();
    }//end of unsuccessful login

    }//end of choice2
}//endofmenu

int main()
{
   menu();
    return 0;
}
