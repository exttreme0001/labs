#pragma once
#include<iostream>
#include<string>
#include <cstring>

class Student {
public:
	Student( char* name, int& course, int& group, int const& card);
	Student(Student* obj);

	char* get_name();
	int get_course() { return _course; }
	int get_group() { return _group; }
	int get_card() { return _ñard; }
	int get_identificator() { return _id; }
	void set_name(char* name);
	int set_group(int& group) { this->_group = group; }
	int set_course(int& course) { this->_course = course; }
	virtual double average() { return 0; }
	virtual double averageAfter1() { return 0; }



	
	 friend std::ostream& operator<<(std::ostream& os, const Student& student);

protected:
	char* _name = new char[20] {0};
	int _course;
	int _group;
	static int identificator;
	int _ñard;
	const int _id;

private:
	
	static int nextId;

	Student() = delete;// blocked default
};



class after1Session :public Student {

public:
	after1Session(char* nameof1, int& course1, int& groupof1, int const& cardof1);

	double average() override;


	void changeGrade(int& numberOf, int& grade);

	int readGrade(int& numberOf) {// not tried return 
		return grades1[numberOf];
	}

	 friend std::ostream& operator<<(std::ostream& os,const after1Session& student);

	double averageAfter1();

protected:

	void initialisationGrades(int* grad, int size);
	int grades1[4];

private:

	after1Session() = delete;

};



class after2Session :public after1Session {

public:

	after2Session(char* nameof2, int& course2, int& groupof2, int const& cardof2);

	void readAllGradesAfter2();

	double average() override;


	

friend std::ostream&  operator<<(std::ostream& os, after2Session& student);

private:

	int grades2[5];

	after2Session() = delete;

	};
void enter(char* pName, int* pCourse, int* pGroup, int* pCard);

void FuncAverageAfter1(Student*[], int);
void FuncAverageAfter2(Student*[], int);