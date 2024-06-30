#pragma once
/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "worker.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;


class Teacher: virtual public worker // virtual heritence to solve dimonde problem
{
protected:
	vector<string> subjects;
	int num_of_subjects;
public:
	Teacher() {}; // defualt ctor
	Teacher(string first, string last, float seniority, vector<string> subjects, int num_of_subjects); //ctor
	~Teacher() { }; // detor
	float return_salary(); // override virtual function from worker
	bool check_excelent();//override virtual function from worker
	void print_subjects();	// print all the techer subject
	void print_details();
};

