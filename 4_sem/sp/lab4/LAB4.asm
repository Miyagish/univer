MYCODE SEGMENT 'CODE'
	ASSUME CS:MYCODE, DS:MYCODE
	 
	LINE DB 0DH, 0AH, '$'
	
	TABLEHEX DB '0123456789ABCDEF'
	
	HEX PROC
	;ПЕРЕВОД ЧИСЛА В 16-УЮ СИСТЕМУ
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
	
	CLRF PROC
	;ПЕРЕВОД НА НОВУЮ СТРОКУ
		MOV DX, OFFSET LINE
		MOV AH, 09H  ; выводит строку  08H ввод без вывода в консоль
		INT 021H
		RET
	CLRF ENDP
	
	PUTCH PROC
	;ПРОЦЕДУРА ВЫВОДА 1-ГО СИМВОЛА
		MOV AH, 02H
		INT 021H
	RET
	PUTCH ENDP
	
	
	GETCH PROC
	;ПРОЦЕДУРА ВВОДА 1-ГО СИМВОЛА
		MOV AH, 08H
		INT 021H
	RET
	GETCH ENDP	
	
	
	START:
	;Загрузка сегментного регистра данных DS
		PUSH CS
		POP DS  
		CALL GETCH
		MOV CX, 20 
		
		LOOP1:
			PUSH AX
			MOV DL, AL
			CALL PUTCH
			MOV DH, DL
			MOV DL, ' '
			CALL PUTCH
			MOV DL, '-'
			CALL PUTCH
			MOV DL, ' '
			CALL PUTCH
			CALL HEX
			MOV DL, 'H'
			CALL PUTCH
			POP AX
			INC AL
			CALL CLRF
			
		LOOP LOOP1
		
		
		
		
	;ОЖИДАНИЕ ЗАВЕРШЕНИЯ ПРОГРАММЫ
		MOV AH, 01H
		INT 021H
		
	;ВЫХОД ИЗ ПРОГРАММЫ
		MOV AL, 0
		MOV AH, 4CH; 4ch - завершение программы
		INT 021H
MYCODE ENDS
END START