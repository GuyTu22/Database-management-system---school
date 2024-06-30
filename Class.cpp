/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "Class.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;


//ctor
Class::Class(char layer_name, int class_num, vector<pupil*> pupil_arr, Tutor* class_tutor_pointer) {
	this->layer_name = layer_name;
	this->class_num = class_num;
	this->pupils_arr = pupil_arr;
	this->class_tutor_pointer = class_tutor_pointer;
}

//ctor
Class::Class(char layer_name, int class_num) {
	this->layer_name = layer_name;
	this->class_num = class_num;
}

//detor
Class::~Class() {

}

//method for add student to class
void Class::add_student(pupil* pupil_pointer) {
	this->pupils_arr.push_back(pupil_pointer);
	this->number_of_pupils += 1;

}

// method to return pupil by index
pupil* Class::return_pupil_by_index(int index) {
	return(this->pupils_arr[index]);
}
