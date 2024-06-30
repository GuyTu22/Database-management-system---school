executable_1: main.o person.o pupil.o worker.o Teacher.o AdministrationPersonal.o Manager.o Secretary.o Tutor.o Class.o Layer.o School.o VecAnalyser.o
	g++ main.o person.o pupil.o worker.o Teacher.o AdministrationPersonal.o Manager.o Secretary.o Tutor.o Class.o Layer.o School.o VecAnalyser.o


main.o: main.cpp
	g++ -c main.cpp

person.o: person.cpp
	g++ -c person.cpp
	
pupil.o: pupil.cpp
	g++ -c pupil.cpp

worker.o: worker.cpp
	g++ -c worker.cpp

Teacher.o: Teacher.cpp
	g++ -c Teacher.cpp

AdministrationPersonal.o: AdministrationPersonal.cpp
	g++ -c AdministrationPersonal.cpp
	
Manager.o: Manager.cpp
	g++ -c Manager.cpp

Secretary.o: Secretary.cpp
	g++ -c Secretary.cpp

Tutor.o: Tutor.cpp
	g++ -c Tutor.cpp

Class.o: Class.cpp
	g++ -c Class.cpp

Layer.o: Layer.cpp
	g++ -c Layer.cpp

School.o: School.cpp
	g++ -c School.cpp

VecAnalyser.o: VecAnalyser.cpp
	g++ -c VecAnalyser.cpp

clean:
	rm *.o executable_1

	
