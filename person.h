/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;
class person
{

protected:
	string first_name;
	string last_name;
public:
	person() {}; // defualt ctor 
	person(string first, string last); // ctor
	virtual ~person() = 0; //dtor ****
	string get_first() { return first_name; } // get method for recive first name
	string get_last() { return last_name; } // get method for recive last name
	virtual void print_details() = 0; // pure virtual for hertience
	virtual bool check_excelent() = 0;// // pure virtual for hertience
	
};

