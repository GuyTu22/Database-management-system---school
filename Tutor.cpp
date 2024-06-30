/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "Tutor.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>


//ctor
Tutor::Tutor(string first, string last, float seniority, vector<string> subjects, int num_of_subjects, Class* tutor_class) : worker(first,last,0,seniority),Teacher(first,last,seniority,subjects, num_of_subjects) {
	this->tutor_class = tutor_class;

}

// return tutor salary, override the return_salary of techer
float Tutor::return_salary() {
	return(1000 + this->Teacher::return_salary());
}


// cheack if tutor is excelent, only if 50% of is student are excelent 
bool Tutor::check_excelent() {
	int num_of_excelent_students = 0;
	int class_size = this->tutor_class->return_number_of_pupils();
	int excelent_counter = 0;
	// run over the tutor class and count the excelents pupils
	for (int i = 0; i < class_size; i++) {
		if (this->tutor_class->return_pupil_by_index(i)->check_excelent()) {
			excelent_counter++;
		}
	}
	if ((excelent_counter > class_size / 2) && class_size > 0) {
		return true;
	}
	else
	{
		return false;
	}
}

// print tutor details

void Tutor::print_details() {
	int class_size = this->tutor_class->return_number_of_pupils();
	bool flag = 0;
	cout << "Tutor name: " << this->first_name << " " << this->last_name << endl;
	cout << "Tutor study subjects: ";
	this->print_subjects();
	cout << "Tutor seniority: " << this->seniority_teach << endl;
	cout << "Tutor salary: " << this->return_salary() << endl;
	// details about tutor class
	cout << "Tutor layer: " << this->tutor_class->return_layer_name() << endl;
	cout << "Tutor class number: " << this->tutor_class->return_class_number() << endl;
	cout << "Number of students in tuotr class are: " << this->tutor_class->return_number_of_pupils() << endl;
	cout << "~~~  Students in the class  ~~~" << endl;
	// run over class students to print their data
	for (int i = 0; i < class_size; i++) {
		this->tutor_class->return_pupil_by_index(i)->print_details();
		if (!(i == (class_size - 1))) {
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cout << endl;
		}
	}
	
	flag = this->check_excelent();
	if (flag )
	{
		cout << "more the 50% of " << this->first_name << " " << this->last_name << " students are excelent students" << endl;
		cout << this->first_name << " " << this->last_name << " is excelent tutor (:" << endl;
	}
	else {
		cout << "less then 50% of " << this->first_name << " " << this->last_name << " are excelent students." << endl;
		cout << this->first_name << " " << this->last_name <<" isn't excelent tutor ):" << endl;
	}

}