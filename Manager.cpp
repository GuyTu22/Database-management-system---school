/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "Manager.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

// initialize static pointer
Manager* Manager::ptr_manager = 0;

//Ctor Manager he is admin and teacher
Manager::Manager(string first, string last, vector<string> subjects, int num_of_subjects, string office, float sen_admin, float sen_teach)
	: worker::worker(first, last, sen_admin, sen_teach), AdministrationPersonal::AdministrationPersonal(first, last, sen_admin, office), Teacher(first, last, sen_teach, subjects, num_of_subjects) {}


//Ctor Manager he is just admin
Manager::Manager(string first, string last, string office, float sen_admin)
	: worker::worker(first, last, sen_admin, 0), AdministrationPersonal::AdministrationPersonal(first, last, sen_admin, office) {}

Manager* Manager::insert_manager(string first, string last, vector<string> subjects, int num_of_subjects, string office, float sen_admin, float sen_teach)
{
	if (ptr_manager == 0) {
		if (sen_teach) {//allocation memory for object Manager.
			ptr_manager = new Manager(first, last, subjects, num_of_subjects, office, sen_admin, sen_teach);
		}
		else {
			ptr_manager = new Manager(first, last, office, sen_admin);
		}
	}
	else { cout << "Already exsiste manager!!!" << endl; }
	return ptr_manager;
}

//Dtor
Manager::~Manager() {}
//clear the switch "exsist manager" to not exsist.


//update seniority worker Administration
void Manager::set_seniority_Admin(float val) {
	AdministrationPersonal::seniority_admin = val;
}
//update seniority worker Teacher
void Manager::set_seniority_Teach(float val) {
	Teacher::seniority_teach = val;
}

//return summary salary of Manager
float Manager::return_salary() {
	float salary_admin = (worker::basis * 2) + (AdministrationPersonal::seniority_admin * 500);
	//occur that the manager in addition teacher 
	if (this->num_of_subjects) {
		return Teacher::return_salary() + salary_admin;
	}

	return salary_admin;
}


void Manager::print_details() {
	cout << "The Manager: " << person::first_name << " " << person::last_name << endl;
	cout << "Administration seniority: ";
	printf("%.1f", AdministrationPersonal::seniority_admin);
	cout << endl;
	//print when to manager exsist teach seniority. 
	if (Teacher::seniority_teach) {
		cout << "Teach seniority: ";
		printf("%.1f", Teacher::seniority_teach);
		cout << endl;
	}
	//print him salary
	cout << "Salary: " << return_salary() << endl;
	//print number of him office
	cout << "Office number: " << AdministrationPersonal::get_office_mun() << endl;
	if (check_excelent()) {
		cout << "The Manager is excelent!!!" << endl;
	}
	else {
		cout << "The Manager is not excelent." << endl;
	}
	//print the information about class's manager 
	if (Teacher::num_of_subjects) {
		cout << "Teachs " << Teacher::num_of_subjects << " subjects: " << endl;
		for (int i = 0; i < num_of_subjects; i++) {
			cout << i + 1 << ". " << Teacher::subjects[i] << endl;
		}
		//this->Teacher::print_subjects();
	}
}


//Check if the Manager is excelent
bool Manager::check_excelent() {
	return AdministrationPersonal::seniority_admin > 3;
}
