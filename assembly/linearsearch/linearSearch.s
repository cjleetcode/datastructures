

	global linearSearch

	section .text

linearSearch:
	push rbx
	xor rbx, rbx
	xor r10, r10
	mov rax, -1
reset:
	cmp 	r10, rsi
	je 	end
	jmp	loop
loop:
	mov	rbx, [rdi + 4*r10]
	cmp	[rdi + 4*r10], edx
	je 	found
	inc	r10
	jmp	reset
found:
	mov rax, r10
	inc r10
	jmp reset
end:
	pop rbx
	ret
