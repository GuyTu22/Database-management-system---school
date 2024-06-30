/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "pupil.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;



// ctor
pupil::pupil(string first, string last, vector<float> grades, char layer, int class_num) :person(first, last) {
	this->grades_vector = grades;
	this->layer = layer;
	this->class_num = class_num;
}


//function to return the avg grades of the pupil grades vector
float pupil::return_avg() {
	int vec_size = this->grades_vector.size();
	float sum = 0;
	for (int i = 0; i < vec_size; i++) {
		sum += this->grades_vector[i];
	}
	return sum / vec_size;
}

//return bool if student is excelent student
bool pupil::check_excelent() {
	bool  flag = 0;
	int vec_size = this->grades_vector.size();
	if (this->return_avg() <= 85) {
		return flag;
	}
	for (int i = 0; i < vec_size; i++) {
		if (this->grades_vector[i] < 65) {
			return flag;
		}
	}
	flag = 1;
	return flag;

}
// print the pupil data and if he excelent or not
void pupil::print_details() {
	int vec_size = this->grades_vector.size();
	bool flag = 0;
	cout << "pupil name: " << this->first_name << " " << this->last_name << endl;
	cout << "grades: ";
	// print grades
	for (int i = 0; i < vec_size; i++) {
		cout << this->grades_vector[i];
		if (!(i == (vec_size - 1))) {
			cout << ", ";
		}
		else {
			cout<<endl;
		}
	}
	cout << "avrage grades: " << this->return_avg() << endl;
	flag = this->check_excelent(); // cheack if student is excelent
	if (flag) {
		cout << "The student is excelent (:" << endl;
	}
	else {
		cout << "The student isn't excelent ):" << endl;
	}
	


}

