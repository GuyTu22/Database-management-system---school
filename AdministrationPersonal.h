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


class AdministrationPersonal : virtual public worker
{
protected:
	string office_num;

public:
	//ctor
	AdministrationPersonal(string first, string last, float sen_admin, string office);
	//detor
	~AdministrationPersonal() {};
	string get_office_mun() { return office_num; }


	float return_salary() = 0;	// pure virtual for hertience from worker
	void print_details() = 0;			// pure virtual for hertience from worker
	bool check_excelent() = 0;			// virtual for hertience from worker
};



