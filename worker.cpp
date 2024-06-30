/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "worker.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;


// initialize static 
int worker::basis = 25;

// ctor
worker::worker(string first, string last, float sen_admin, float sen_teach):person(first, last) {
	this->seniority_admin = sen_admin;
	this->seniority_teach = sen_teach;
}

//dtor 
worker::~worker() {

}