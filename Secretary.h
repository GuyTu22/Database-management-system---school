/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#pragma once
#include "AdministrationPersonal.h"
#include"worker.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

class Secretary : public AdministrationPersonal
{
	int num_of_children;	// number of children's person administration which study in school.

public:
	//Defualt Ctor
	//Secretary() {};
	//Ctor
	Secretary(string first, string last, string office, float sen_admin, int num_children);
	//Dtor
	~Secretary() {};

	float return_salary();		// pure virtual for hertience from AdministrationPersonal
	void print_details();		// pure virtual for hertience from AdministrationPersonal
	bool check_excelent();		// virtual for hertience from worker

};
