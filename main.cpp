#include<iostream>
#include<string>
#include <cstring>
#include"Student.h"



int main() {
	
	const int maxLength = 20;
	char* nameIS = new char[maxLength];


	int course(0), group(0), card(0);
	double averageAfter1(0);
	double averageAfter2(0);
	int numbOfGroup(0);
	/*enter(&name, &course, &group, &card);
    after2 Victor(name,course,group,card);
	std::cout << Victor;*/
	Student* obj[3]{0};

	enter(nameIS, &course, &group, &card);
	obj[0] = new after2Session(nameIS, course, group, card);

	enter(nameIS, &course, &group, &card);
	obj[1] = new after1Session(nameIS, course, group, card);

	enter(nameIS, &course, &group, &card);
	obj[2] = new after2Session(nameIS, course, group, card);

	std::cout << "enter number of group";
	std::cin >> numbOfGroup;

	FuncAverageAfter1(obj, numbOfGroup);
	FuncAverageAfter2(obj, numbOfGroup);
}
