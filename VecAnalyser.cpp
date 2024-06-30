/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/

#include "VecAnalyser.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <typeinfo> // for type id to work
using namespace std;

template <typename T> 
VecAnalyser<T>::VecAnalyser(vector<T> persons_arr) {
	this->persons_arr = persons_arr;
}

// method to return person by index
template <typename T>
T VecAnalyser<T>::return_person_by_index(int index) {
	int size_of_vector = this->persons_arr.size();
	// cheack if the index user enterd got valid valuse
	if (index > size_of_vector-1 || index < 0) {
		cout << "Erorr! " << "you enterd the index " << index << ", " << "but valid index is between 0 to " << size_of_vector -1 << "." << endl;
	}
	else {
		return this->persons_arr[index];
	}
}

// method to swap between places of tow persons in the person arr
template <typename T>
void VecAnalyser<T>::swap(int first_index, int second_index) {
	int size_of_vector = this->persons_arr.size();
	T temp = NULL;
	// cheack if the first index user enterd got valid valuse
	if (first_index > size_of_vector-1 || first_index < 0) {
		cout << "Erorr! " << "you enterd the index " << first_index << ", " << "but valid index is between 0 to " << size_of_vector -1 << "." << endl;
	}
	if (second_index > size_of_vector-1 || second_index < 0) {	// cheack if the second index user enterd got valid value
		cout << "Erorr! " << "you enterd the index " << second_index << ", " << "but valid index is between 0 to " << size_of_vector -1 << "." << endl;
	}
	else {//make the swap action
		temp = this->persons_arr[second_index]; // to not loose the seconde var
		this->persons_arr[second_index] = this->persons_arr[first_index];
		this->persons_arr[first_index] = temp;
	}
}	

// method to print details of specific pesron
template <typename T>
void VecAnalyser<T>::printElement(int index) {
	int size_of_vector = this->persons_arr.size();
	// cheack if the index user enterd got valid valuse
	if (index > size_of_vector-1 || index < 0) {
		cout << "Erorr! " << "you enterd the index " << index << ", " << "butvalid index is between 0 to " << size_of_vector-1 << "." << endl;
	}
	else { // print the person details by virtual method
		this->persons_arr[index]->print_details();
	}
}

// method to print all the data in pesron arr
template <typename T>
void VecAnalyser<T>::print_all() {
	int size_of_vector = this->persons_arr.size();
	for (int i = 0; i < size_of_vector; i++) {
		this->persons_arr[i]->print_details();
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
}

//printMax method
template <typename T>
 void VecAnalyser<T>::printMax() {
	int size_of_vector = this->persons_arr.size();
	if (typeid(*this->persons_arr[0]) == typeid(pupil)) { // cheack if the person_arr if pupil kind
		cout << "Max student avarge is:" << endl;
		float max_avg = 0;
		float temp_avg = 0;
		for (int i = 0; i < size_of_vector; i++) {
			pupil* ptr_pupil = (pupil*)this->return_person_by_index(i);
			temp_avg = ptr_pupil->return_avg();
			if (temp_avg > max_avg) {
				max_avg = temp_avg;
			}
		}
		cout << max_avg << endl;
	}
	else //person arr is workers type
	{
		cout << "Max worker salary is:" << endl;
		float max_salary = 0;
		float temp_salary = 0;
		for (int j = 0; j < size_of_vector; j++) {
			worker* ptr_worker = (worker*)this->return_person_by_index(j);
			temp_salary = ptr_worker->return_salary();
			if (temp_salary > max_salary) {
				max_salary = temp_salary;
			}
		}
		cout << max_salary << endl;
		
	}


}

 // cheack if one of the objects is manger
template <typename T>
bool VecAnalyser<T>::RTTI() {
	int  size_0f_vector = this->persons_arr.size();
	for (int i = 0; i < size_0f_vector; i++) {
		if (typeid(*this->persons_arr[i]) == typeid(Manager)) {
			return true;
		}
	}
	return false;
 }