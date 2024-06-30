/*
Assignment: 2
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "Layer.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

//ctor
Layer::Layer(char layer_name, vector<Class*> class_arr) {
	this->layer_name = layer_name;
	this->class_arr = class_arr;
}

// return specific class by index
Class* Layer::return_class_by_index(int index){
	return(this->class_arr[index]);
}
