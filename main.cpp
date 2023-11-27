#include <iostream>
#include"fraction.h"

int main() {
	rightFraction p1(1, 0);
	p1.printValues();
	rightFraction p2(0, 25);
	p2.printValues();
	rightFraction p3(1, 1);
	p3=p1 + p2;
	p3.printValues();
	p3=p1 * p2;
	p3.printValues();
	p3=p1 / p2;
	p3.printValues();





}