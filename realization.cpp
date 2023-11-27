#include"Student.h"
#include<string>


Student::Student(char* name, int& course, int& group, int const& card):_id(identificator) {
	int i = 0;
	while (name[i] != '\0') 
	{ this->_name[i] = name[i]; i++; }
	this->_course = course;
	this->_group = group;
	this->_сard = card;
	identificator ++;
}
Student::Student(Student* obj) :_id(obj->identificator)//добавить конструкторы копирования
{
	this->_name = obj->get_name();
	this->_course = obj->get_course();
	this->_group = obj->get_group();
	this->_сard = obj->get_card();
	
}
char* Student::get_name()
{
	char* copy = new char[20]{0};
	int i = 0;
	while (this->_name[i] != 0)
	{
		copy[i] = this->_name[i]; i++;
	}
	return copy;
}

void Student::set_name(char* name)
	{
		int i = 0;
		while (name[i] != 0)
		{
			this->_name[i] = name[i]; i++;
		}
	}
;

int Student::identificator = 0;

 std::ostream& operator<<(std::ostream& os, const Student& student) {// friend for cout info
	 os << "Info: " << std::endl
		 << "Name is "; 
	/**/ int i = 0;
	while (student._name[i] != 0)
	{
		os << student._name[i]; i++;
	}
	 
		os<< std::endl
		<< "Course is " << student._course << std::endl
		<< "Group is " << student._group << std::endl
		<< "card is " << student._сard << std::endl
		<< "identificator is " << student._id << std::endl;

	return os;
}



	after1Session::after1Session(char* nameof1, int& course1, int& groupof1, int const& cardof1) :Student(nameof1, course1, groupof1, cardof1) {// constructor of student
		initialisationGrades(grades1, 4);
	}



	double after1Session::average()  {//average in 1st course
		double result(0);
		for (int i = 0; i < sizeof grades1 / sizeof grades1[0]; i++) {
			result += grades1[i];
		}
		return result / (sizeof grades1 / sizeof grades1[0]);
	}

	void after1Session::changeGrade(int& numberOf, int& grade) {
		grades1[numberOf + 1] = grade;

	}
	
	std::ostream& operator<<(std::ostream& os, const after1Session& student) {
		os << "Grades after 1 are ";

		for (int i = 0; i < 4; i++) {
			os << student.grades1[i] << '\t';
		}

		return os;
	}

	 void after1Session::initialisationGrades(int* grad, int size) {

		 for (int i = 0; i < size; i++) {
			 grad[i] = rand() % 11;

		 }
	 }

double after1Session::averageAfter1() {

	double average(0);
	for (int i = 0; i < 4; i++) {

		average += grades1[i];
	}

	return average/4;
}


after2Session::after2Session(char* nameof2, int& course2, int& groupof2, int const& cardof2) :after1Session(nameof2, course2, groupof2, cardof2) {
	
	initialisationGrades(grades2, 5);// initialization
}

 std::ostream& operator<<(std::ostream& os, after2Session& student) {
	 os<<static_cast<Student&>(student);
	 
	 for (int i = 0; i < 4; i++) {
		 os << student.grades2[i] << '\t';

	 }
	 os << std::endl;
	student.readAllGradesAfter2();
	os << std::endl << student.average();

	return os;
}

void after2Session::readAllGradesAfter2() {
	std::cout << "Grades after 2 are ";

	for (int i = 0; i < sizeof grades2 / sizeof grades2[0]; i++) {
		std::cout << grades2[i] << '\t';

	}
}


double after2Session::average()  {

	double result(0);

	for (int i = 0; i < 4; i++) {
		result += grades1[i] + grades2[i];
	}

	result += grades2[4];
	return result / 9;

}



int counterOfEnters(0);
void enter(char* pName, int* pCourse, int* pGroup, int* pCard) {
	std::cout << "Enter name: ";
	if (counterOfEnters > 0) {
		std::cin.ignore();
	}
	std::cin.getline(pName, 20);


	std::cout << "enter course" << std::endl;
	std::cin >> *pCourse;

	std::cout << "enter group" << std::endl;
	std::cin >> *pGroup;

	std::cout << "enter card" << std::endl;
	std::cin >> *pCard;

	counterOfEnters ++ ;

}

void FuncAverageAfter2(Student* obj[], int numbOfGroup) {

	int counter(0);
	double averageAfter2(0);

	for (int i = 0; i < 3; i++) {
		Student* p = obj[i];

		if (typeid(*p).hash_code() == typeid(after2Session).hash_code() && p->get_group() == numbOfGroup) {
			std::cout << typeid(*p).name();

			counter++;

			averageAfter2 = (averageAfter2 + p->average()) / counter;

			std::cout << "current average"
				<< p->average() << std::endl
				<< averageAfter2;
		}
		std::cout << *p << std::endl;
	}
}

void FuncAverageAfter1(Student* obj[], int numbOfGroup) {

	int counter(0);
	double averageAfter1(0);

	for (int i = 0; i < 3;i++) {

		Student* p = obj[i];

		if (typeid(*p).hash_code() != typeid(Student).hash_code() && p->get_group() == numbOfGroup) {

			counter++;

			averageAfter1 = (averageAfter1 + p->averageAfter1()) / counter;

			std::cout 
				<< "current average"
				<< p->averageAfter1() << std::endl
				<< averageAfter1;
		}
		std::cout << *p << std::endl;
	}


}