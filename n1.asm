.386
.model flat,c
.code
find1InBin proc  
find:
		cmp ecx, 0
		je endof
			mov eax, ecx
			and eax, 1
			add edx, eax
			shr ecx, 1
		jmp find
	endof:
ret
find1InBin endp
end


