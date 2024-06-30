#pragma once
/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "Teacher.h"
#include "Class.h"

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

class Class;

class Tutor: public Teacher
{
private:
	Class* tutor_class = NULL; // pointer for the tutor class
public:
	//ctor
	Tutor(string first, string last, float seniority, vector<string> subjects, int num_of_subjects, Class *tutor_class);
	//dtor
	~Tutor() {};
	// get tutor class method
	//Class return_tutor_class() { return *tutor_class; };

	// return tutor salary, override the return_salary of techer
	float return_salary();

	// cheack if tutor is excelent, only if 50% of is student are excelent 
	// pay attension this method overide the teacher function
	bool check_excelent();
	//prints tutor data, pay attension this method overide the teacher function
	void print_details();
	// get class pointer
	Class* return_tutor_class() { return tutor_class; }

};

