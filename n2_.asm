.686P
.model flat, c
.code
new_pow proc a:dword
 start :
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

         ret
new_pow	endp
end