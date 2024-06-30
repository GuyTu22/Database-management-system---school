#pragma once
/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "person.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class worker: public person
{
protected:
	float seniority_admin;
	float seniority_teach;
	static int basis;

public:
	//defualt ctor
	worker() {};
	//ctor
	worker(string first, string last, float sen_admin, float sen_teach);
	//detor
	~worker();
	float get_seniority_admin() { return seniority_admin; }
	float get_seniority_teach() { return seniority_teach; }
	virtual float return_salary() = 0; // pure virtual for hertience
	virtual void print_details() = 0;
	virtual bool check_excelent() = 0;//virtual function from person


};

