/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "person.h"
#include <string>
#include <iostream>
using namespace std;

// ctor
person::person(string first, string last) {
	this->first_name = first;
	this->last_name = last;
}
//detor

person::~person() {

}

