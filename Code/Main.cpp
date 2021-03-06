#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <stdlib.h>
#include "Student.cpp"
#include "Teacher.cpp"

using namespace std;

int validation(int last)
{
	int n; std::cin >> n;
	bool valid = false;
	while (!valid)
	{
		if (n<=last && n>=1)
		{
			valid = true;
		}
		else
		{
			if (!std::cin) //prevents char from breaking code
			{
				std::cin.clear();
				std::cin.ignore();
				/*With multiple char the err message repeats
				But will still run code*/
			}
			std::cout << "\n Please input a valid option: ";
			std::cin >> n;
		}
	}
	return n;
}
int main()
{
	while(true)
	{
	  int choice;
	    cout << "____Login Menu____" << endl;
	    cout << "Enter 1) for Student Login" << endl;
      		cout << "Enter 2) for Teacher Login" << endl;
		 cout << "Enter 3) Exit out of program." << endl;
	    choice = validation(3);

	    ifstream slist;
	    slist.open("StudentList.txt");
    	if(slist.fail())
	  {
        	cerr << "Error opening file." <<endl;
	        return 1;
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
	        student(stemp_username, stemp_password);
	        stemp_password.clear();
	        stemp_username.clear();
	    }//end of successful login
	    else
	    {
	        cout <<"Unsuccessful Login!" << endl;
	 continue;
	    }//end of unsuccessful login

	    }//endofchoice1

	    if(choice==2)
	 {
	 teacher();

	    }//end of choice2
	    if(choice==3)
	    {
    		break;
	     }
	}
	return 0;
	     
}//endofmenu

