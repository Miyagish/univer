MYCODE SEGMENT 'CODE'
	ASSUME CS:MYCODE, DS:DATA

CLRF PROC	; ……‚„ € ‚“ ‘’“
	
		MOV DX, OFFSET LINE
		MOV AH, 09H  ; ΆλΆ®¤¨β αβΰ®ªγ  08H ΆΆ®¤ ΅¥§ ΆλΆ®¤  Ά ª®­α®«μ
		INT 021H
		RET
	CLRF ENDP
	
	PUTCH PROC	; –…„“€ ‚›‚„€ 1-ƒ ‘‚‹€
	
		MOV AH, 02H
		INT 021H
	RET
	PUTCH ENDP
	
	
	GETCH PROC	; –…„“€ ‚‚„€ 1-ƒ ‘‚‹€
	
		MOV AH, 01H
		INT 021H
	RET
	GETCH ENDP	

	TRANS_LINE PROC
	MOV CX, 0
	
	TRANSLATE:
		MOV BX, CX
		MOV DH, [LINE_GET+2+BX]
		CMP DH, '$'
		JE ENDF
		INC CX
		CALL HEX
		INC CX
		MOV DL, ' '
		CALL PUTCH
		
		
	LOOP TRANSLATE
	
	ENDF:
	CALL CLRF
	RET
	TRANS_LINE ENDP
	
	HEX PROC	; ……‚„ ‘‚‹€ ‚ 16-“ ‘‘’…“
		MOV BX, OFFSET TABLEHEX
		MOV AL, DH
		SHR AL, 4
		XLAT
		MOV DL, AL
		CALL PUTCH
		
		MOV AL, DH
		AND AL, 0FH
		XLAT
		MOV DL, AL
		CALL PUTCH
		RET
	HEX ENDP
	
	BACK_SPACE:
	DEC BX
	INC CX
	JMP END_GET_LINE
	
	OVERFLOW:
	INC BX
	MOV [LINE_GET+2+BX], '$'
	JMP ENDL
		
	START:
	; ‡ £ΰγ§ª  α¥£¬¥­β­®£® ΰ¥£¨αβΰ  ¤ ­­λε DS
		PUSH CS
		MOV AX, DATA
		MOV DS, AX
		MOV CX, 10
		
		GET_LINES:
			PUSH CX
			MOV BX, 0
			
			GET_LINE:
				MOV CX, 20
				
				CALL GETCH
				
				CMP AL, '$'
				JE ENDL
				CMP BX, 19
				JE OVERFLOW
				CMP AL, '*'
				JE EXIT_PNT
				CMP AL, 08H
				JE BACK_SPACE
				
				MOV [LINE_GET+2+BX], AL
				INC BX
				
				END_GET_LINE:
				
			LOOP GET_LINE
			
			ENDL:
			MOV [LINE_GET+2+BX], '$'
			MOV DL, ' '
			CALL PUTCH
			MOV DL, '='
			CALL PUTCH
			MOV DL, ' '
			CALL PUTCH
			CALL TRANS_LINE
			
			POP CX
			
		LOOP GET_LINES
			
			
	EXIT_PNT:	; †„€… ‡€‚…… ƒ€›
	
		CALL CLRF
		MOV DX, OFFSET END_MESSAGE
		MOV AH, 09H
		INT 021H
		MOV AH, 01H
		INT 021H
		
	 ; ‚›•„ ‡ ƒ€›
		MOV AL, 0
		MOV AH, 4CH; 4ch - ‡€‚……… ƒ€›
		INT 021H



data segment

LINE DB 0DH, 0AH, '$'

	LINE_PUT db 20,?,20 Dup(?),'$'
	LINE_GET db 22,?,22 Dup(?),'$'

	TABLEHEX DB '0123456789ABCDEF'
	END_MESSAGE DB '‡€‚……… ƒ€›, „‹ „‹†… €†’… ‹“ “.$'

data ends

stk segment stack
db 256 dup(0)
stk ends

MYCODE ENDS
END START