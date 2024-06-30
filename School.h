#pragma once
/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
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
using namespace std;

class worker;
class pupil;

class School
{
private:
	static School* The_school;
	// private constructor
	School() {
	
	};
	// vector for school layers
	vector<Layer*> school_arr;
	int num_of_layers = 0;
	//vetor for all pupils ins school
	vector<pupil*> school_pupils;
	// vector for all workers in school
	vector<worker*> school_workers;



public:
	// static method to create only one school
	static School* get_School() {
		if (!The_school) {
			The_school = new School; // dinamic allocate new School
			return The_school;
		}
 	}
	//detor
	~School();
	// print method as required
	void menu();
	//method to add pupil
	void add_pupil();
	//method to add teacher
	void add_teacher();
	//method to add tutor
	void add_tutor();
	//method to add manger
	void add_manager();
	//method to add secertry to school
	void add_secretery();
	// print all the persons in the school
	void print_person_details();
	// print outstanding people 
	void print_outstanding_people();
	// print class by tutor
	void print_tutor_class();
	//print the worker with max salary
	void highest_paid_worker();
	
};

