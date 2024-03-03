#include <iostream>


int main() {
    ////////////////////////// N1
    /*int  a;
    std::cin >> a;

    _asm {
        mov ebx, a

        xor eax, eax
        add eax, a

        imul ebx, ebx
        imul ebx, ebx

        mov ecx, ebx

        imul ebx, ebx
        add eax, ebx

        imul ebx, ecx
        add eax, ebx

        mov a, eax

    }
    std::cout << a << '\n';*/

///////////////////////////////////// N2
    int a(0), b(0),counter(0);
    int A1[60]{ 0 };
    _asm {
        mov ecx,counter
start:  
        mov eax, a
        mov ebx, b
        imul eax, 2
        cmp eax,50
        jg end
        imul ebx, 3


        add eax, ebx

        cmp eax, 50
        jne iterate
        mov eax,a
        mov ebx,b
        mov A1[8 * ecx],eax
        mov A1[ecx * 8 + 4], ebx
        add ecx,1
        add b,1

        jmp start
iterate:
        add b,1
        cmp eax,50
        jg nextA
        jmp start

nextA:
        add a,1
        mov b,0
        jmp start
end:    
        mov counter,ecx
    }

    for (int i(0); i < counter; i++) {
        std::cout << A1[i * 2] << "  " << A1[i * 2 + 1]<<'\n';
    }


    ///////////////////////////////// N3
//    int A[50]{0};
//    A[1] = 1, A[0] = 0;
//    _asm {
//        xor esi, esi
//        mov eax, A[esi + 4]
//        mov ebx, A[esi]
//        mov ecx, A[esi + 4]
//
//        start :
//
//            add eax, ebx
//            jo enough
//            mov ebx, ecx
//            mov ecx, eax
//            add esi, 4
//            mov A[esi], eax
//            jmp start
//    }
//
//enough:
//    int i = 1, counter = 1;
//    while (A[i - 1] < A[i]) {
//        std::cout << A[i] << "\n";
//        i++; counter++;
//    }
//    std::cout << '\n' << "number is: " << counter;
//}

    ////////////////////////////////////////////// N4
//Дробь задается  целым числителем и натуральным знаменателем, сократить
//    int nom(0), denom(0);
//    std::cout << '\t';
//    std::cin >> nom;
//    std::cout << '\t' << "--"<<std::endl << '\t';
//    std::cin >> denom;
//    _asm {
//    mov eax,nom
//    mov ebx,denom
//    mov ecx,0
//    
//    cmp eax,0
//    // eax - числ
//    // ebx - знам
//    // ecx - -1
//    // edx для остатка
//    // edi Для цифры на сокращение
//    // esi сохранение ebx
//
//    jg cycle
//    jl less
//    jmp ending
//   
//     less:
//    imul eax, -1
//    
//        
//
//        cycle :
//        cmp ebx, 0
//        je outing
//
//        
//        mov esi,ebx//сохр б
//        cdq
//        idiv ebx
//        mov ebx,edx
//        mov eax, esi        
//        jmp cycle
//
//
//
//            outing:
//            mov edi,eax//выведет а, элемент на который сокращать
//            mov eax,nom
//            mov ebx,denom
//            mov edx,0
//            mov esi,0
//                jmp sokr
//     sokr:
//           cmp eax,0
//            jg continuing
//            
//                imul eax,-1// if nom <0
//                mov ecx,1// set flag 1
//
//  continuing:
//            idiv edi //eax:edi
//         cmp ecx,0
//         je finall
//         imul eax,-1
//
//  finall:   mov nom, eax
//            mov eax,ebx
//            idiv edi
//            mov denom,eax
//    }
//ending:
//    if (nom == 0) { std::cout << 0; }
//    else
//    {
//        std::cout << std::endl<<'\t' << nom << std::endl <<'\t' << "--" << std::endl << '\t' << denom << std::endl;
//    }
   }