#include <iostream>
template <typename T>
class Stack {
public:
	Stack( )

	{	
		this->size = 0;
		this->capacity = 2;
		this->stack = new T [capacity];
		
	}
	~Stack() {
		if(stack!=nullptr)
		delete[] stack;
	}

	void push(T data);
	T pop();
	T top();
//	Stack& operator<<(T data);
	std::istream& operator>>(std::istream& is);
	Stack& operator= (Stack& newStack);
	bool operator< (Stack& newStack);
	bool operator== (Stack& newStack);
	T operator[](int a);

public:
int size;

private:
	
	T* stack;
	int capacity;
};
template <typename T>
void Stack<T>::push(T data)
{
	
	
	if ( capacity>size) {
		stack[size] = data;
		size++;
	}
	else

		if (capacity <= size) {
			capacity *= 2;
			T* newStack = new T[capacity];
						
			for (int i = 0; i < size; i++) {// check -1
				newStack[i] = stack[i];
			}
			newStack[size] = data;

			delete[] stack;

			stack = newStack;
			size++;
			newStack = nullptr;
		}
}

template <typename T>
T Stack<T>::pop()
{
	if (size > 0) {
		return stack[size--];// уменьшился ли CAиз?
	}
	else {
		throw std::runtime_error("Stack is empty");
	}
}

template<typename T>
T Stack<T>::top()
{
	return stack[size-1];
}

//template <typename T>
//Stack<T>& Stack<T>::operator<<(T data)
//{
//	push(data);
//	return *this;
//}
template <typename T>
std::istream& Stack<T>::operator>>(std::istream& is)// check
{
	if (size > 0) {
		is >> stack[size-1];
		pop();
	}
	return is;
}
template <typename T>
Stack<T>& Stack<T>::operator= (Stack& newStack)
{
	if (this != &newStack) {
		size = newStack.size;
		capacity = newStack.capacity;
		delete[] stack;

		for (int i = 0; i < size-1; i++) {
			stack[i] = newStack[i];
		}
	}
	return *this;
}

template <typename T>
bool Stack<T>::operator<(Stack& newStack)
{
	double average1(0), average2(0);
	for (int i = 0; i < size; i++) 
	{
		average1 += stack[i];
	}
	average1 /= size;
	for (int i = 0; i < newStack.size; i++) 
	{
		average2 += newStack[i];
	}
	average2 /= newStack.size;
	return average1 < average2;
}

template <typename T>
bool Stack<T>::operator==(Stack& newStack)
{
	if (size == newStack.size) {
		for (int i = 0; i < size-1; i++) 
		{
			if (stack[i] != newStack[i])
			{return false; break;}
		}
		return true;
	}
	else
		return false ;
}

template <typename T>
T Stack<T>::operator[](int a)
{
	return stack[a];
}

struct Element {
	Element() {
		type = 0;
		value = 0;
	}
	char type;
	double value;
};

int priority(char symbol){
	if (symbol == '+' || symbol == '-') {
		return 1;
	}

	if (symbol == '*' || symbol == '/') {
		return 2;
	}
	return -1;
}

bool calculating(Stack <Element>& stOfNumb, Stack <Element>& stOfChars, Element item) {

	if (stOfNumb.size + stOfChars.size < 3) { std::cerr << "insufficient data" << std::endl; return false; }
	double a, b, c;

	b = stOfNumb.top().value;
	stOfNumb.pop();

	//if (stOfChars.top().type == '(') { std::cin.ignore(); }
	switch (stOfChars.top().type) {
	case '+': {
		a = stOfNumb.top().value;
		stOfNumb.pop();
		c = a + b;
		item.value = c;
		item.type = 1;
		stOfNumb.push(item);
		stOfChars.pop();
		break;
	}
	case '-': {
		a = stOfNumb.top().value;
		stOfNumb.pop();
		c = a - b;
		item.value = c;
		item.type = 1;
		stOfNumb.push(item);
		stOfChars.pop();
		break;
	}
	case '*': {
		a = stOfNumb.top().value;
		stOfNumb.pop();
		c = a * b;
		item.value = c;
		item.type = 1;
		stOfNumb.push(item);
		stOfChars.pop();
		break;
	}
	case '/': {
		a = stOfNumb.top().value;
		stOfNumb.pop();
		if (b == 0) { std::cout << "delenie na 0" << std::endl; return false; }
		c = a / b;
		item.value = c;
		item.type = 1;
		stOfNumb.push(item);
		stOfChars.pop();
		break;
	}
	default: {
		std::cerr << "no operation or incorrect expression  =(";
		return false; }

	}
	return true;
}

bool divideSymbols(Stack <Element>& stOfNumb, Stack <Element>&stOfChars, Element item) {
	
	std::cout << "Enter your Math" << std::endl;

	int flagForMinus(1);

	while (true) {
		double value(-111);
		char symbol = std::cin.peek();

		if (symbol == '\n') { return true; }
		if (symbol == ' ') { std::cin.ignore(); continue; }
		if (symbol >= '0' && symbol <= '9'|| symbol == '-' && flagForMinus==1)
		{
			flagForMinus = 0;
			std::cin >> value;
			item.value = value;
			item.type = 1;
			stOfNumb.push(item);
			continue;

		}
		else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
		{

			if (stOfChars.size == 0 || stOfChars.size != 0 && (priority(symbol) > priority(stOfChars.top().type))) {
				item.value = 0;
				item.type = symbol;
				stOfChars.push(item);
				std::cin.ignore();
				continue;
			}
			 if (stOfChars.size != 0 && (priority(symbol) <= priority(stOfChars.top().type))) {
				calculating(stOfNumb, stOfChars, item);
			
			}


		}
		else if (symbol == '(') {
			item.value = 0;
			item.type = symbol;
			stOfChars.push(item);
			std::cin.ignore();
			continue;
		}
		else if (symbol == ')') {
			std::cin.ignore();
			while (stOfChars.top().type != '(') {
				calculating(stOfNumb, stOfChars, item);
			}
			stOfChars.pop();
		}

		else return false;
	}
}
void answer(Stack <Element>& stOfNumb) {
	std::cout << "Answer is : " << stOfNumb.top().value;

};
void start() {
	int choose(0);
	while (choose != 2) {

		std::cout<<std::endl;
		std::cout << "Enter 1 to calculate next" << std::endl;
		std::cout << "Enter 2 for stop calculator" <<std::endl;
		std::cout << std::endl;
		std::cin >> choose;
		std::cin.ignore();

		if (choose == 1) {
			Stack <Element> stOfNumb = Stack<Element>();
			Stack <Element>stOfChars = Stack<Element>();
			Element item = Element();

			if (divideSymbols(stOfNumb, stOfChars, item))//if true
			{
				int counter = stOfChars.size;
				while (stOfChars.size != 0) {
					counter--;
					if (calculating(stOfNumb, stOfChars, item) == false) {
						system("pause");
						break;
					}
				}
				if(!counter)answer(stOfNumb);
			}
		}
		else break;
	}
}

int main() {
	start();
}