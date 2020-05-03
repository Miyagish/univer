MYCODE SEGMENT 'CODE'
	ASSUME CS:MYCODE, DS:MYCODE
	 
	LINE DB 0DH, 0AH, '$'
	
	TABLEHEX DB '0123456789ABCDEF'
	
	HEX PROC
	;������� ����� � 16-�� �������
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
	;������� �� ����� ������
		MOV DX, OFFSET LINE
		MOV AH, 09H  ; �뢮��� ��ப�  08H ���� ��� �뢮�� � ���᮫�
		INT 021H
		RET
	CLRF ENDP
	
	PUTCH PROC
	;��������� ������ 1-�� �������
		MOV AH, 02H
		INT 021H
	RET
	PUTCH ENDP
	
	
	GETCH PROC
	;��������� ����� 1-�� �������
		MOV AH, 08H
		INT 021H
	RET
	GETCH ENDP	
	
	
	START:
	;����㧪� ᥣ���⭮�� ॣ���� ������ DS
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
		
		
		
		
	;�������� ���������� ���������
		MOV AH, 01H
		INT 021H
		
	;����� �� ���������
		MOV AL, 0
		MOV AH, 4CH; 4ch - �����襭�� �ணࠬ��
		INT 021H
MYCODE ENDS
END START