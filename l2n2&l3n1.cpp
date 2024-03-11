#include <iostream>
//extern "C" int find1InBin();
extern "C" int new_pow(long);

/*int main() {
int a;
std::cin >> a;
int counter(0);
_asm
{
	mov ecx, a
	mov edx, counter
	call find1InBin
	mov counter, edx
}
std::cout << counter;


}
*/
int main() {
	long  a;
	std::cin >> a;
	a = new_pow(a);

	std::cout << a << '\n';
}