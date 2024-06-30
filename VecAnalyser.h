#pragma once
/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/

#include "pupil.h"
#include "worker.h"
#include "Manager.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

template <typename T>
 class VecAnalyser
{
private:
	vector<T> persons_arr;

public:
	//ctor
	VecAnalyser() {};
	VecAnalyser(vector<T> persons_arr);
	//dtor
	~VecAnalyser() {};
	//method to return specific pesron by index
	T return_person_by_index(int index);
	// method to sweap between two pesrons inside pesron_arr
	void swap(int first_index, int second_index);
	// method to print pesron by index
	void printElement(int index);
	//print all the data in person_arr
	void print_all();
	// print max value, for pupils max average, for workers higest salary
	void printMax();
	// cheack if one of the elements is pesron arr is Manger
	bool RTTI();
	//return number of people in vector
	int return_persons_number() { return this->persons_arr.size(); }
	
};

