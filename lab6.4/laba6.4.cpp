// laba6.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    set <string> student_set;
    set <string> student_rep;
    string name;
    cout << "Enter your login: ";
    cin >> name;

    
    while (name != ".") { // make a set from the login
        if (student_set.find(name) != student_set.end()) {
            student_rep.insert(name);// the set that repet here
        }else
        student_set.insert(name);// all the login here

        cout << "Enter your login: ";// the loop finish whene we enter "."
        cin >> name;
    }

    for (auto i : student_rep) // the student that repeted a login 
        student_set.erase(i);// we delete the login with the same name and we let just the first login

    
    cout << "\nAnswer:\n"; // show all the student
    for (auto i : student_set)
        cout << "one login: " << i << endl ;

    for (auto i : student_rep) // the setudent who repeted the login
        cout << "a lot of login: " << i << endl;

}