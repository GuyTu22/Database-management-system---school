/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#pragma once
#include"person.h"
#include"worker.h"
#include "AdministrationPersonal.h"
#include "Teacher.h"
#include"Class.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

class Manager : public AdministrationPersonal, public Teacher
{
private:
	static Manager* ptr_manager;
	Manager(string first, string last, vector<string> subjects, int num_of_subjects, string office, float sen_admin, float sen_teach);
	Manager(string first, string last, string office, float sen_admin);

public:
	~Manager();
	void set_seniority_Admin(float val);	//update seniority worker Administration 
	void set_seniority_Teach(float val);	//update seniority worker Teacher
	float return_salary();		// pure virtual for hertience from AdministrationPersonal
	void print_details();		// pure virtual for hertience from AdministrationPersonal
	static Manager* insert_manager(string first, string last, vector<string> subjects, int num_of_subjects, string office, float sen_admin = 0, float sen_teach = 0);	// The method return manager object
	bool check_excelent();		// virtual for hertience from worker
};