; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_char:function
; LABEL
$_char:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 4
; DIV
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	eax
; IMM
	push	dword 4
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; ADD
	pop	eax
	add	dword [esp], eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 4
; MOD
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	edx
; IMM
	push	dword 8
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; SHTRS
	pop	ecx
	sar	dword [esp], cl
; IMM
	push	dword 255
; AND
	pop	eax
	and	dword [esp], eax
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; LEAVE
	leave
; RET
	ret
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_strcmp:function
; LABEL
$_strcmp:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; TRASH
	add	esp, 4
; LABEL
$_i1:
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_char
; TRASH
	add	esp, 8
; PUSH
	push	eax
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_char
; TRASH
	add	esp, 8
; PUSH
	push	eax
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_char
; TRASH
	add	esp, 8
; PUSH
	push	eax
; IMM
	push	dword 0
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; AND
	pop	eax
	and	dword [esp], eax
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i2
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; INCR
	pop	eax
	add	dword [eax], 1
; JMP
	jmp	dword $_i1
; LABEL
$_i2:
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_char
; TRASH
	add	esp, 8
; PUSH
	push	eax
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+8]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$_char
; TRASH
	add	esp, 8
; PUSH
	push	eax
; SUB
	pop	eax
	sub	dword [esp], eax
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; LEAVE
	leave
; RET
	ret
