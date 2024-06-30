/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#pragma once
#include "person.h"
#include "pupil.h"
#include "worker.h"
#include "Teacher.h"
#include "Tutor.h"
#include "AdministrationPersonal.h"
#include "Manager.h"
#include "Secretary.h"
#include "Class.h"
#include "Layer.h"
#include "School.h"
#include "VecAnalyser.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <typeinfo> // for type id to work

using namespace std;



int main() {
	School* school = School::get_School(); // create new school , only one can make
	school->menu(); 
	school->~School(); // call destructor to release all dynamic memory of school
}



