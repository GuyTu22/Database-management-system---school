/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/
#include "AdministrationPersonal.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

//ctor
AdministrationPersonal::AdministrationPersonal(string first, string last, float sen_admin, string office)
	:worker(first, last, sen_admin, 0), office_num(office) {}
