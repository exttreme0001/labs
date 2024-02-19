#include<iostream>
#include<string>
#include <iomanip>


int main() 
{
	 long long a=0;
	 short	A1 = 333, A2 = 444, A3 = 222, B1 = 333, B2 = 444, B3 = 222, C1 = 0;
	 short C2 = 0, C3 = 0;
	
	 _asm 
	 {
		mov ax,A1
		mov bx,A2
		mov cx,A3


		add ax,B1
		adc bx,B2
		adc cx,B3

		mov C1, ax
		mov C2, bx
		mov C3, cx

	 }
	 std::cout << "C1: " << std::hex << C1 << std::endl;
	 std::cout << "C1: " << C2 << std::endl;
	 std::cout << "C1: " << C3 << std::endl;
	
	 a += static_cast<long long>(C1) + (static_cast<long long>(C2) << 16) + (static_cast<long long>(C3) << 32);
	std::cout <<"\n" << std::dec << a;

}