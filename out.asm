; DATA
segment	.data
; LABEL
$_L0:
; INTEGER
	dd	1
; INTEGER
	dd	2
; INTEGER
	dd	4
; INTEGER
	dd	0
; INTEGER
	dd	0
; INTEGER
	dd	0
; INTEGER
	dd	0
; INTEGER
	dd	0
; INTEGER
	dd	0
; INTEGER
	dd	0
; DATA
segment	.data
; TEXT
segment	.text
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$n:
; ID
	dd	$_L0
; TEXT
segment	.text
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$i:
; INTEGER
	dd	0
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_main:function
; LABEL
$_main:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; IMM
	push	dword 3
; IMM
	push	dword 2
; CALL
	call	$_power
; TRASH
	add	esp, 8
; PUSH
	push	eax
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; IMM
	push	dword 0
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
; EXTRN
extern	$_prints
; EXTRN
extern	$_println
; EXTRN
extern	$_printi
; EXTRN
extern	$_readi
; EXTRN
extern	$_power
; EXTRN
extern	$_strcmp
