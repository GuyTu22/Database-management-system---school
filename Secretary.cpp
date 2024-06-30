/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "Secretary.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;




//Ctor

Secretary::Secretary(string first, string last, string office, float sen_admin, int num_children)
	:worker(first, last, sen_admin,0), AdministrationPersonal(first, last, sen_admin, office), num_of_children(num_children) {}
	


// pure virtual for hertience from AdministrationPersonal
float Secretary::return_salary() {
	return basis + (float)num_of_children * 200;
}

// check if the worker is excelent. ->virtual for hertience from worker
bool Secretary::check_excelent() {//return that the worker is excellent if him seniority above 10 years.
	return AdministrationPersonal::seniority_admin > 10;
}


// The method print detauls of Administration worker. ->pure virtual for hertience from AdministrationPersonal
void Secretary::print_details() {
	//print name of person
	cout << "Secretery: " << person::first_name << " " << person::last_name << endl;
	//print seniority with one number of fraction.
	cout << "seniority: ";
	printf("%.1f", AdministrationPersonal::seniority_admin);
	cout << endl;
	//print him salary
	cout << "Salary: " << return_salary() << endl;
	//print number of him office
	cout << "Office number: " << AdministrationPersonal::get_office_mun() << endl;
	//print number of children
	cout << "Number of children attending school: " << num_of_children << endl;
	if (seniority_admin > 10) {
		cout << "The worker is excelent :)" << endl;
	}
	else { cout << "The worker is not excelent." << endl; }
}
