/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#pragma once
#include "person.h"
#include <vector>
#include <string>
using namespace std;
class pupil: public person
{
protected:
	vector<float> grades_vector; // vector of student grades
	char layer;
	int class_num;

public:
	pupil(string first, string last, vector<float> grades, char layer, int class_num); //ctor for pupile also call person 
	~pupil() {};//detor for the pupil	
	vector<float> get_vector_grades() { return grades_vector; }
	char get_layer() { return layer; }
	int get_class_num(){ return class_num; }
	float return_avg(); //function to return the avg grades of the pupil grades vector
	void print_details() ; // overide the function from person
	bool check_excelent() ;//  overide the function from person

};

