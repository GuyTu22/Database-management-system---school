/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "Teacher.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//ctor
Teacher::Teacher(string first, string last, float seniority, vector<string> subjects, int num_of_subjects) : worker(first, last,0, seniority) {
	this->subjects = subjects;
	this->num_of_subjects = num_of_subjects;
}

//return the techer salary (float number)
float Teacher::return_salary() {
	float x = this->num_of_subjects; // holds the number of teacher subjects
	float y = this->seniority_teach; // holds the number of the teacher seniority
	return (basis * (1 + (x / 10))) + 300 * y; // by the formula given
}

// return bool if teacher is excelent (tech more then 5 subjects)
bool Teacher::check_excelent() {
	if (this->num_of_subjects > 5) {
		return true;
	}
	return false;
}

// print techer sucjects
void Teacher::print_subjects() {
	int num_of_subjects = this->num_of_subjects;
	for (int i = 0 ; i < num_of_subjects; i++) {
		cout << this->subjects[i];
		if (!(i == (num_of_subjects - 1))) {
			cout << ", ";
		}
		else {
			cout << endl;
		}
	}
}

// print teacher data
void Teacher::print_details() {
	bool flag = 0;
	cout << "Teacher name: " << this->first_name << " " << this->last_name << endl;
	cout << "Teacher study subjects: ";
	this->print_subjects();
	cout << "Teacher seniority: " << this->seniority_teach << endl;
	cout << "Teacher salary: " << this->return_salary() << endl;
	flag = this->check_excelent();
	if (flag)
	{
		cout << "Teacher is excelent (:" <<endl;
	}
	else {
		cout << "Teacher isn't excelent ):" << endl;
	}
}

