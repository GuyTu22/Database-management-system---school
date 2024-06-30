#pragma once
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

class Layer
{
private:
	char layer_name;
	vector<Class*> class_arr; // conatin max 3 class

public:
	//ctor
	Layer(char layer_name, vector<Class*> class_arr);
	Layer(char layer) { layer_name = layer; }
	//another
	//dtor
	~Layer(){};
	// return specific class by index
	Class* return_class_by_index(int index);
	//add class to class arr
	void add_class_layer(Class* class1) { this->class_arr.push_back(class1); }
	//return layer name
	char get_layer_name() { return this->layer_name; }
	// method to return the class* vector
	vector<Class*> get_class_arr() { return class_arr; }
	//methid to add class to layer
	//add class to class array
	void add_class_to_layer(Class* class1) { this->class_arr.push_back(class1); };
	vector<Class*> get_class_array() { return this->class_arr; };
	void set_class_array(vector<Class*> array) { this->class_arr = array; };
};



