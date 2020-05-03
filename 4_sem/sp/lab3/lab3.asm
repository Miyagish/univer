MYCODE SEGMENT 'CODE'
	ASSUME CS:MYCODE, DS:MYCODE
	 
	LINE DB 0DH, 0AH, '$'
	
	CLRF PROC
	;……‚„ € ‚“ ‘’“
		MOV DX, OFFSET LINE
		MOV AH, 09H  ; ΆλΆ®¤¨β αβΰ®ªγ  08H ΆΆ®¤ ΅¥§ ΆλΆ®¤  Ά ª®­α®«μ
		INT 021H
		RET
	CLRF ENDP
	
	PUTCH PROC
	;–…„“€ ‚›‚„€ 1-ƒ ‘‚‹€
		MOV AH, 02H
		INT 021H
	RET
	PUTCH ENDP
	
	
	GETCH PROC
	;–…„“€ ‚‚„€ 1-ƒ ‘‚‹€
		MOV AH, 01H
		INT 021H
	RET
	GETCH ENDP	
	
	A_CHAR DB 'A'
	B_CHAR DB ''
	V_CHAR DB '‚'
	
	START:
	;‡ £ΰγ§ª  α¥£¬¥­β­®£® ΰ¥£¨αβΰ  ¤ ­­λε DS
		PUSH CS
		POP DS   
		
	;‚›‚„ 1 ‘‚‹€ € €
		MOV DL, A_CHAR
		CALL PUTCH
		CALL CLRF
		
	;‚›‚„ 2 ‘‚‹€ € €
		MOV DL, B_CHAR
		CALL PUTCH
		CALL CLRF
		
	;‚›‚„ 3 ‘‚‹€ € €
		MOV DL, V_CHAR
		CALL PUTCH
		CALL CLRF
		
	;†„€… ‡€‚…… ƒ€›
		MOV AH, 01H
		INT 021H
		
	;‚›•„ ‡ ƒ€›
		MOV AL, 0
		MOV AH, 4CH; 4ch - § Ά¥ΰθ¥­¨¥ ―ΰ®£ΰ ¬¬λ
		INT 021H
		MYCODE ENDS
	END START	