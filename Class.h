#pragma once
/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "pupil.h"
#include "Tutor.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

class Tutor;

class Class
{
private:
	char layer_name;
	int class_num;
	vector<pupil*> pupils_arr;
	int number_of_pupils = 0;
	Tutor* class_tutor_pointer = NULL;

public:
	//ctor
	Class(char layer_name, int class_num, vector<pupil*> pupil_arr,Tutor* class_tutor_pointer);
	Class(char layer_name, int class_num);
	//dtor
	~Class();
	//add student method
	void add_student( pupil* pupil_pointer); // add student to class, use copy ctor to pupil
	// return student by index method
	pupil* return_pupil_by_index(int index);
	//return layer
	char return_layer_name() { return layer_name; }
	//return class number
	int return_class_number() { return class_num; }
	//return number of pupilst in class
	int return_number_of_pupils() { return number_of_pupils; }
	// set method for the class tutor
	void set_tutor(Tutor* tutor_ptr){this->class_tutor_pointer = tutor_ptr;}
	// return the pupils arr
	vector<pupil*> return_pupil_arr() { return pupils_arr; }
};

