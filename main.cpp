//(2 * x – 1)* (2 * x + 1)* (x + 3) / (2 * x)
#include<iostream>
int main() {
	//n1
	// 
	//int a(0);
	//std::cin >> a;
	//long b(a);
	//_asm {
	//cmp a,0
	//je end
	//mov eax,a
	//imul eax,2
	//sbb eax,1

	//xor ebx, ebx
	//add ebx,eax
	//adc ebx,2

	//xor edx, edx
	//mov edx,a
	//adc edx,3

	//xor ecx,ecx
	//add ecx,eax
	//adc ecx,1

	//imul eax,ebx
	//imul eax,edx
	//cdq
	//idiv ecx

	//mov a,eax
	//
	//}
	//end:
	//std::cout << a<<"\n";

	//if (b == 0) { std::cout << 0; }
	//else
	//{
	//	b = ((b * 2) - 1) * ((b * 2) + 1) * (b + 3) / (b * 2);
	//	std::cout << b;
	//}

		//n2.
   int a;
   std::cin >> a;
   int counter(0);

   _asm
   {
	find:
		cmp a, 0
		je end
			mov eax, a
			and eax, 1
			add counter, eax
			shr a, 1
		jmp find
	end:
	
   }

 std::cout << counter;


}
