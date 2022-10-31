; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_factorial:function
; LABEL
$_factorial:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; IMM
	push	dword 1
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; LOCV
	push	dword [ebp+8]
; LOCA
	pop	eax
	mov	[ebp+0], eax
; LABEL
$_L1:
; LOCV
	push	dword [ebp+0]
; IMM
	push	dword 2
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_L2
; LOCV
	push	dword [ebp+-4]
; LOCV
	push	dword [ebp+0]
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; LABEL
$_L3:
; LOCV
	push	dword [ebp+0]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; LOCA
	pop	eax
	mov	[ebp+0], eax
; JMP
	jmp	dword $_L1
; LABEL
$_L2:
; LOCV
	push	dword [ebp+-4]
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; EXTRN
extern	$_prints
; EXTRN
extern	$_println
; EXTRN
extern	$_printi
; EXTRN
extern	$_readi
; EXTRN
extern	$_argv
; EXTRN
extern	$_argc
; EXTRN
extern	$_power
; EXTRN
extern	$_atoi
; EXTRN
extern	$_strcmp
