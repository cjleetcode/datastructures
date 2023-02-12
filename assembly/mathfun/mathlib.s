
	global product
	global power

	section .text

product:
	; take input of two numbers defined in c++ file and find their product
	xor	rax, rax
	xor	r10, r10
	push 	rbx
	xor	rbx, rbx
	;reset rax and r10 to 0, where rax = return and r10 = counter = i
start:
	cmp	r10, rsi	;if(i >= n2) return rax, else{ i++, rax += n1)
	je	done
	add	rbx, rdi
	inc	r10
	jmp	start
done:
	mov	rax, rbx	;clear rbx, set rax to value to be returned, terminate
	pop	rbx
	ret
	
power:
	mov	rax, 1
check:				;checking if base is greater, smaller, or equal to the power, and sending it to its appropriate loop
	cmp	rdi, rsi
	jb	rdiLesser
	ja	rdiGreater
	je	equalLoop
rdiLesser:
	cmp	rsi, 0
	je	end
	dec	rsi
	call	power
	mov	rsi, rax
	call	product
	jmp	end
rdiGreater:
	cmp	rsi, 0
	je	end
	dec 	rsi
	call	power
	mov	rsi, rax
	call	product
	jmp	end
equalLoop:
	cmp	rsi, 1
	je	equalEnd
	dec	rsi
	call	power
	mov	rsi, rax
	call	product
	jmp	end
equalEnd:			;if both are 1, return 1
	mov	rax, 1
	ret
end:
	ret

	
