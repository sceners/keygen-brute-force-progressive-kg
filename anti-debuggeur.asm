;****************************************************************************************
;
;		QQs macros et fonction pour rendre la vie d'un cracker + dure :)
;	PS:vous pouvez utiliser ces sources comme bon vous semble mais pensez a moi
;	dans vos Greetz ca serait sympa :)
;****************************************************************************************

Is_Fct_Bpxed	PROTO
.code

pCall	MACRO	Fonction_Called
	pushf
	push	eax
	mov	eax,Fonction_Called
	movzx	eax,byte ptr [eax]	;on prends le premier byte
	xor	eax,0CCh		;la fonction a ete bpxee?
	jnz	@No_Bpx
	pop	eax
	popf
	jmp	@Dont_Call
	
@No_Bpx:
	pop	eax
	popf
	call	Fonction_Called

@Dont_Call:
ENDM

Callp	Macro	Fonction
	push	Fonction
	call	Is_Fct_Bpxed
ENDM



;*******************Shit# Macro****************
;	Utilisee pour faire chier le mec 
;	quand il trace	.....facile a enlever
;	cShit=Code shit		dShit=Data Shit
;***********************************************
cShit1	Macro
	jmp	$+5
	db	0CDh,020h,0C7h
ENDM

cShit2	Macro
	jmp	$+5
	db	0CDh,020h,0EAh
ENDM

cShit3	Macro
	jmp	$+5
	db	0CDh,020h,0EBh
ENDM

cShit4	Macro
	jmp	$+3
	db	0EBh
ENDM

cShit5	Macro
	jmp	$+6
	db	0EBh,0CDh,020h,0EBh
ENDM

cShit6	Macro
	jmp	$+5
	db	0CDh,020h,0C7h
ENDM

cShit7	Macro
	jmp	$+5
	db	0CDh,020h,0EAh
ENDM

cShit8	Macro
	jmp	$+5
	db	0CDh,020h,0EBh
ENDM


dShit1	Macro
	db	0CDh,020h
ENDM

dShit2	Macro
	db	0EBh
ENDM

dShit3	Macro
	db	0E8h
ENDM

dShit4	Macro
	db	0CDh,020h
ENDM

dShit5	Macro
	db	0EBh
ENDM

dShit6	Macro
	db	0E8h
ENDM

;*******************Special Jump****************
;	Utilisee pour faire chier le crackeur 
;	ca sautera vers la routine apres le ret
;
;	lJump=Late Jump	->Appelle la routine au
;			  prochain ret
;			  
;***********************************************

lJump	Macro	addresse1
	call	$+8
	db	0CDh,020h,0EBh
	cShit2
	jmp	$+5
	db	0EBh
	jmp	addresse1
	cShit1
	add	dword ptr [esp],11
ENDM


Is_Fct_Bpxed	proc
	pushf
	push	eax
	
	mov	eax,[esp+0Ah]		;on a dans eax,l'offset de la fonction qu'on va appeller
	cmp	byte ptr [eax],0CCh	;il y a un bpm dessus??
	jnz	@No_BPX			;c bon on l'execute
	
	pop	eax			;mauvais garcon on l'execute pas!!
	popf
	ret				;on peut voir si la fonction a reussit en testant le dword ptr en esp s'il
					;est egal a celui de l'offset de la fct qu'on aurait du appeller->elle n'a pas etee appellee!!!!
	
@No_BPX:
	pop	eax
	popf

	pop	eax
	xchg	dword ptr [esp],eax	;on change au niveau de la pile
	push	eax
	ret
Is_Fct_Bpxed	endp