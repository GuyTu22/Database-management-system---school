/*
Assignment: 3
Author: Guy Tubul, ID: 204129159
Author: Yair Keinan, ID: 206903866
*/

#include "School.h"
#include "VecAnalyser.cpp"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

//initilize static pointer
School* School::The_school = 0;



//destructor, delete all pupils , workers, classes and layers 
School::~School() {
	//delete all pupils
	int num_of_pupils = this->school_pupils.size();
	int num_of_workers = this->school_workers.size();
	for (int i = 0; i < num_of_pupils; i++) {
		delete this->school_pupils[i];
	}
	//delete all workers
	for (int j = 0; j < num_of_workers; j++) {
		delete this->school_workers[j];
	}
	// delete all layers and clases
	for (int k = 0; k < num_of_layers; k++) {
		int number_of_classes = this->school_arr[k]->get_class_arr().size();
		for (int z = 0; z < number_of_classes; z++ ) {
			delete this->school_arr[k]->return_class_by_index(z);
		}
		delete this->school_arr[k];
	}
	
}


void School::menu() {
	int num;
	do {
		do {
			cout << "----------------------------------------------------------" << endl;
			cout << "~~~Welcome to Guy and Yaya school~~~" << endl;
			cout << "Please choose one of the following options:" << endl;
			cout << "==========================================================" << endl;
			cout << "1) Add pupil." << endl;
			cout << "2) Add teacher." << endl;
			cout << "3) Add tutor." << endl;
			cout << "4) Add manager." << endl;
			cout << "5) Add secretery." << endl;
			cout << "6) Print person details." << endl;
			cout << "7) Print outstanding people" << endl;
			cout << "8) Print tutor's class" << endl;
			cout << "9) Higest paid worker" << endl;
			cout << "10) Exit" << endl;
			cout << "==========================================================" << endl;
			cin >> num;
			if ((1 > num) || (num > 11)) {
				cout << "Your choise is illegal!!! Try again." << endl;
			}
		} while ((1 > num) || (num > 11));

		switch (num) {
		case 1:
			add_pupil();
			break;
		case 2:
			add_teacher();
			break;
		case 3:
			add_tutor();
			break;
		case 4:
			add_manager();
			break;
		case 5:
			add_secretery();
			break;
		case 6:
			print_person_details();
			break;
		case 7:
			print_outstanding_people();
			break;
		case 8:
			print_tutor_class();
			break;
		case 9:
			highest_paid_worker();
			break;
		case 10:
			cout << "You choose to exit, Goodbye (:" << endl;
			return;
	}

	} while (1);
}

//Add pupil
void School::add_pupil() {
	string first, last;
	vector<float> grades;
	float ch;
	char layer_name;
	int class_num, i, i_layer, i_class;
	bool flag = false;
	cout << "	~~~~Add pupil:~~~~" << endl;
	do {
		//get first name
		cout << "Please enter first name of pupil: ";
		cin >> first;
		while (cin.get() != '\n')	continue;	//clean Buffer
		//get last name
		cout << "Please enter last name of pupil: ";
		cin >> last;
		while (cin.get() != '\n')	continue;	//clean Buffer
		int size_pupils = this->school_pupils.size();
		for (i = 0; i < size_pupils; i++) {
			//check if the name of pupil exsist in school
			//set flag if exsist
			flag = ((this->school_pupils[i]->get_first() == first) && (this->school_pupils[i]->get_last() == last));
		}
		if (flag)	cout << "Error! you can't add pupil twice. Try again." << endl;
	} while (flag);
	//get number of class
	do {
		cout << "Please enter class number (1 - 3): ";
		cin >> class_num;
		while (cin.get() != '\n')	continue;	//clean Buffer
		if (class_num < 1 || class_num > 3)
			cout << "Your layer is illigale! Try again." << endl;
	} while (class_num < 1 || class_num > 3);
	//get layer
	do {
		cout << "Please enter layer of pupil ('a' - 'f'): ";
		cin >> layer_name;
		while (cin.get() != '\n')	continue;	//clean Buffer
		if (layer_name < 'a' || layer_name > 'f')
			cout << "Your layer is illigale! Try again." << endl;
	} while (layer_name < 'a' || layer_name > 'f');
	//get grades of pupil
	cout << "Enter grades of pupil:" << endl;
	cout << "Please enter the amount of grades you would like to enter: ";
	cin >> i;
	cout << "Now please enter the grades one by one:" << endl;
	for (int index = 0; index < i; index++) {
		cout << index + 1 << ". ";
		cin >> ch;
		grades.push_back(ch);
	}
	//create new studet
	pupil* std = new pupil(first, last, grades, layer_name, class_num);
	//find if the layer already exsiste in school
	int size_layers = this->school_arr.size();
	for (i_layer = 0; i_layer < size_layers; i_layer++) {
		if (this->school_arr[i_layer]->get_layer_name() == layer_name)
			break;
	}
	if ((size_layers == 0) || (size_layers == i_layer)) {// if the vector school array is empty
		//create new layer
		Layer* layer1 = new Layer(layer_name);
		//create new class
		Class* class1 = new Class(layer_name, class_num);
		//add pupil to class
		class1->add_student(std);
		//add class to layer
		layer1->add_class_to_layer(class1);
		//add layer to vector's school
		this->school_arr.push_back(layer1);
		this->num_of_layers++;
		this->school_pupils.push_back(std);
	}
	else {// if the layer exsist in school
		vector<Class*> vec_class = this->school_arr[i_layer]->get_class_array();
		int size_classes = vec_class.size();
		//shearch the class of pupil
		for (i_class = 0; i_class < size_classes; i_class++) {
			if (vec_class[i_class]->return_class_number() == class_num)
				break;
		}
		if ((size_classes == 0) || (size_classes == i_class)) {//if the class not exsist.
			Class* class1 = new Class(layer_name, class_num);
			//add pupil to class
			class1->add_student(std);
			vec_class.push_back(class1);
		}
		else {//if the class exsist.
			vec_class[i_class]->add_student(std);
			this->school_pupils.push_back(std);
		}
		this->school_arr[i_layer]->set_class_array(vec_class);
	}
}







//method to add teacher
void School::add_teacher() {
	string first, last,subject;
	float seniority_teach;
	vector<string> subjects_vec;
	int num_of_subjects, workers_vec_size = this->school_workers.size();
	bool teacher_exsict;
	cin.ignore();
	do {
		teacher_exsict = false;
		cout << "please enter Teacher first name:" << endl;
		getline(cin, first);
		cout << "please enter Teacher last name:" << endl;
		getline(cin, last);
		// cheack if teacher already exsicet it workers arr
		for (int i = 0; i < workers_vec_size; i++) {
			if (this->school_workers[i]->get_first() == first && this->school_workers[i]->get_last() == last) {
				teacher_exsict = true;
				break;
			}
		}
		if (teacher_exsict) {
			cout << "teacher already in data base, please try again" << endl;
		}
	} while (teacher_exsict);
	// ask teacher seniority from user
	do {
		cout << "please enter teacher seniority, number greater then 0:" << endl;
		cin >> seniority_teach;
		if (seniority_teach < 0) {
			cout << "the number you enterd isn't valid please try again" << endl;
		}

	} while (seniority_teach < 0);
	// ask teacher subjects from user
	cout << "please enter number of subjects the teacher teaches:" << endl;
	cin >> num_of_subjects;
	cout << "please enter subjects names one by one:" << endl;
	cin.ignore();
	for (int j = 0; j < num_of_subjects; j++) {
		getline(cin, subject);
		subjects_vec.push_back(subject);
	}
	
	// create the teacher
	Teacher* new_teacher = new Teacher(first, last, seniority_teach, subjects_vec, num_of_subjects);
	//add teacher to workers data
		this->school_workers.push_back(new_teacher);
}


//add new tutor for school

void School::add_tutor() {
	string first, last, subject;
	float seniority_teach;
	vector<string> subjects_vec;
	int num_of_subjects, workers_vec_size = this->school_workers.size(), size_layers,i_layer,i_class;
	char layer;
	int class_num;
	bool tutor_exsict;
	cin.ignore();
	do {
		tutor_exsict = false;
		cout << "please enter Tutor first name:" << endl;
		getline(cin, first);
		cout << "please enter Tutor last name:" << endl;
		getline(cin, last);
		// cheack if tutor already exsicet it workers arr
		for (int i = 0; i < workers_vec_size; i++) {
			if (this->school_workers[i]->get_first() == first && this->school_workers[i]->get_last() == last) {
				tutor_exsict = true;
				break;
			}
		}
		if (tutor_exsict) {
			cout << "tutor already in data base, please try again" << endl;
		}
	} while (tutor_exsict);
	// ask teacher seniority from user
	do {
		cout << "please enter Tutor seniority, number greater then 0:" << endl;
		cin >> seniority_teach;
		if (seniority_teach < 0) {
			cout << "the number you enterd isn't valid please try again" << endl;
		}

	} while (seniority_teach < 0);
	// ask teacher subjects from user
	cout << "please enter number of subjects the tutor teaches:" << endl;
	cin >> num_of_subjects;
	cout << "please enter subjects names one by one:" << endl;
	cin.ignore();
	for (int j = 0; j < num_of_subjects; j++) {
		getline(cin, subject);
		subjects_vec.push_back(subject);
	}
	// enter layer number
	do {
		cout << "please enter tutor layer, char bwtween 'a' - 'f'." << endl;
		cin >> layer;
		// ceack ascii values
		if (layer < 97 || layer > 102) {
			cout << "the char you enterd isn't valid, please try again." << endl;
		}
	} while (layer < 97 || layer > 102);
	
	// enter class number
	do {
		cout << "please enter tutor class, number between 1-3"<<endl;
		cin >> class_num;
		if (class_num < 0 || class_num >3) {
			cout << "the number you entered isn't valid, please try again." << endl;
		}

	} while (class_num < 0 || class_num >3);

	//find if the layer already exsiste in school
	size_layers = this->school_arr.size();
	for (i_layer = 0; i_layer < size_layers; i_layer++) {
		if (this->school_arr[i_layer]->get_layer_name() == layer)
			break;
	}
	if ((size_layers == 0) || (size_layers == i_layer)) {// if the vector school array is empty
		//create new layer
		Layer* layer1 = new Layer(layer);
		//create new class
		Class* class1 = new Class(layer, class_num);
		//create new tutor
		Tutor* new_tutor = new Tutor(first, last, seniority_teach, subjects_vec, num_of_subjects, class1);
		//set the class with the new tutor
		class1->set_tutor(new_tutor);
		//enter the tutor to workers arr
		this->school_workers.push_back(new_tutor);
		//add class to layer
		layer1->add_class_to_layer(class1);
		//add layer to vector's school
		this->school_arr.push_back(layer1);
		this->num_of_layers++;
	}
	else {// if the layer exsist in school
		// polling the vector class from layer
		vector<Class*> vec_class = this->school_arr[i_layer]->get_class_array();
		int size_classes = vec_class.size();
		//shearch the class of pupil
		for (i_class = 0; i_class < size_classes; i_class++) {
			if (vec_class[i_class]->return_class_number() == class_num)
				break;
		}
		if ((size_classes == 0) || (size_classes == i_class)) {//if the class not exsist.
			Class* class1 = new Class(layer, class_num);
			//create new tutor
			Tutor* new_tutor = new Tutor(first, last, seniority_teach, subjects_vec, num_of_subjects, class1);
			//set the class with the new tutor
			class1->set_tutor(new_tutor);
			//enter the tutor to workers arr
			this->school_workers.push_back(new_tutor);
			vec_class.push_back(class1);
		}
		else {//if the class exsist.
			//create new tutor
			Tutor* new_tutor = new Tutor(first, last, seniority_teach, subjects_vec, num_of_subjects,vec_class[i_class]);
			//set the class with the new tutor
			vec_class[i_class]->set_tutor(new_tutor);
			//enter the tutor to workers arr
			this->school_workers.push_back(new_tutor);
		}
		// update the layer with the new class
		this->school_arr[i_layer]->set_class_array(vec_class);
	}
	
	
}

//
//Add Manager
void School::add_manager() {
	VecAnalyser<worker*> workers_vec(this->school_workers);
	if (workers_vec.RTTI()) {
		cout << "Manager is already in Data Base !" << endl;
		return;
	}
	string first, last, office, subject;
	vector<string> subjects;

	int num_of_subjects = 0;
	float sen_admin = 0, sen_teach = 0;
	char ch;
	bool flag = false;

	cout << "	~~~~Add Manager:~~~~" << endl;
	//get first name{
	cout << "Please enter first name of the manager: ";
	cin >> first;
	while (cin.get() != '\n')	continue;	//clean Buffer
	//get last name
	cout << "Please enter last name of the manager: ";
	cin >> last;
	while (cin.get() != '\n')	continue;	//clean Buffer
	//Does the manager teach at the school?
	do {
		cout << "Does the manager teach at the school? (Y/N)" << endl;
		cin >> ch;
		while (cin.get() != '\n')	continue;	//clean Buffer
		if (!(ch == 'Y' || ch == 'N'))
			cout << "Your answer no match. Try again!" << endl;
	} while (!(ch == 'Y' || ch == 'N'));
	cout << endl;
	//The manager is not teach in school.
	if (ch == 'Y') {
		cout << "~~~Subjects that manager teach~~~" << endl;
		cout << "Please enter the amount of subjects you would like to enter: ";
		cin >> num_of_subjects;
		cout << "Now please enter the subjects one by one:" << endl;
		//get the subjects from user.
		for (int index = 0; index < num_of_subjects; index++) {
			cout << index + 1 << ". ";
			cin >> subject;
			while (cin.get() != '\n')	continue;	//clean Buffer
			subjects.push_back(subject);
		}
		do {
			cout << "Enter senority teach manager: (up to 50) " << endl;
			cin >> sen_teach;
			if (sen_teach < 0 || sen_teach>50)
				cout << "The senority illigale, try again." << endl;

		} while (sen_teach < 0 || sen_teach>50);
	}
	do {
		cout << "Enter seniority administration manager (up to 50): " << endl;
		cin >> sen_admin;
		if (sen_admin < 0 || sen_admin>50)
			cout << "The senority illigale, try again." << endl;
	} while (sen_admin < 0 || sen_admin>50);
	cout << "Please enter number office of manager: " << endl;
	cin >> office;
	while (cin.get() != '\n')	continue;	//clean Buffer
	//create the manager worker and addition to worker vector.
	Manager* manager = manager->insert_manager(first, last, subjects, num_of_subjects, office, sen_admin, sen_teach);
	this->school_workers.push_back(manager);
}


// method for add secretery
void School::add_secretery() {
	string first, last,office;
	float seniority_admin;
	int workers_vec_size = this->school_workers.size(),childrens;
	bool secretry_exsict;
	cin.ignore();
	do {
		secretry_exsict = false;
		cout << "please enter secretry first name:" << endl;
		getline(cin, first);
		cout << "please enter secretry last name:" << endl;
		getline(cin, last);
		// cheack if secretry already exsicet it workers arr
		for (int i = 0; i < workers_vec_size; i++) {
			if (this->school_workers[i]->get_first() == first && this->school_workers[i]->get_last() == last) {
				secretry_exsict = true;
				break;
			}
		}
		if (secretry_exsict) {
			cout << "secretry already in data base, please try again" << endl;
		}
	} while (secretry_exsict);
	// ask teacher seniority from user
	do {
		cout << "please enter secretry seniority, number greater then 0:" << endl;
		cin >> seniority_admin;
		cin.ignore();
		if (seniority_admin < 0) {
			cout << "the number you enterd isn't valid please try again" << endl;
		}

	} while (seniority_admin < 0);

	// ask for secretery office
	cout << "please enter secretery office number:" << endl;
	getline(cin, office);
	//ask for secretery num of childeren
	cout << "please enter the number of secretery childrens:" << endl;
	cin >> childrens;

	// create new secretry
	Secretary* new_secretary = new Secretary(first, last, office, seniority_admin, childrens);
	// add the new Secretary to workers arr
	this->school_workers.push_back(new_secretary);
}



// method to print both workers and pupils in the school
void School::print_person_details() {
	VecAnalyser<pupil*> pupil_vec(this->school_pupils);
	VecAnalyser<worker*> workers_vec(this->school_workers);
	cout << "~~~~~~~~~~ pupils in school ~~~~~~~~~~" << endl;
	if (pupil_vec.return_persons_number() == 0 ) {
		cout << "There are currently no students at the school." << endl;
	}
	else{
		pupil_vec.print_all();
	}
	cout << "~~~~~~~~~~ workers in school ~~~~~~~~~~" << endl;
	if (workers_vec.return_persons_number() == 0) {
		cout << "There are currently no workers at the school." << endl;
	}
	else {
		workers_vec.print_all();
	}
}


//print_outstanding_people

void School::print_outstanding_people() {
	VecAnalyser<pupil*> pupil_vec(this->school_pupils);
	VecAnalyser<worker*> workers_vec(this->school_workers);
	int pupil_vec_size = this->school_pupils.size();
	int workers_vec_size = this->school_workers.size();
	bool pupil_flag = true, worker_flag = true;
	cout << "~~~~~~~~~~ outstanding pupils ~~~~~~~~~~" << endl;
	for (int i = 0; i < pupil_vec_size; i++) {
		pupil* ptr_pupil = (pupil*)pupil_vec.return_person_by_index(i);
		if (ptr_pupil->check_excelent()) {
			ptr_pupil->print_details();
			pupil_flag = false;
		}
	}
	// in case no outstanding people
	if (pupil_flag) {
		cout << "No outstanding students in school!"<<endl;
	}
	cout << "~~~~~~~~~~ outstanding workers ~~~~~~~~~~" << endl;
	for (int k = 0; k < workers_vec_size; k++) {
		worker* ptr_worker = (worker*)workers_vec.return_person_by_index(k);
		if (ptr_worker->check_excelent()) {
			ptr_worker->print_details();
			worker_flag = false;
		}
	}
	if (worker_flag) {
		cout << "No outstanding workers in school!" << endl;
	}

}


//print class by tutor

void School::print_tutor_class() {
	cin.ignore();
	string first, last;
	int workers_vec_size = this->school_workers.size();
	bool tutor_exsict = true;
	cout << "please enter first name of tutor:" << endl;
	getline(cin, first);
	cout << "please enter last name of tutor:" << endl;
	getline(cin, last);
	for (int i = 0; i < workers_vec_size; i++) {
		// cheack if tutor in wokrkers arr
		if (this->school_workers[i]->get_first() == first && this->school_workers[i]->get_last() == last) {
			if (typeid(*this->school_workers[i]) == typeid(Tutor*)) {
				tutor_exsict = false;
				// dinamic cast to Tutor, to enable operation of is methods
				Class* class_ptr = dynamic_cast<Tutor*>(this->school_workers[i])->return_tutor_class();
				cout << "~~~~~~~~ class details ~~~~~~~~" << endl;
				cout << "class layer: " << class_ptr->return_layer_name() << endl;
				cout << "class number: " << class_ptr->return_class_number() << endl;
				cout << "pupils in class" << endl;
				vector<pupil*> class_pupil_arr = class_ptr->return_pupil_arr();
				// print the pupils details
				int num_of_pupils = class_pupil_arr.size();
				for (int k = 0; k < num_of_pupils; k++) {
					class_pupil_arr[k]->print_details();
				}
			}
		}
	}
	if (tutor_exsict) {
		cout << "tutor isn't exsict in data base!" << endl;
	}

}




//mehthod to print the worker with max salary
void School::highest_paid_worker(){
	float max_salary = 0;
	int workers_vec_size = this->school_workers.size(), index_of_highest_paid_worker = 0;
	//if there are no workers in school
	if (workers_vec_size == 0) {
		cout << "Currently, there are no workers at the school." << endl;
	}
	else {
		VecAnalyser<worker*> workers_vec(this->school_workers);
		for (int i = 0; i < workers_vec_size; i++) {
			if (workers_vec.return_person_by_index(i)->return_salary() > max_salary) {
				max_salary = workers_vec.return_person_by_index(i)->return_salary();
				//update the index for currenly max salary workr
				index_of_highest_paid_worker = i;
			}
		}
		cout << "$$$ The details of the worker who earns the most are: $$$" << endl;
		workers_vec.return_person_by_index(index_of_highest_paid_worker)->print_details();
	}
}