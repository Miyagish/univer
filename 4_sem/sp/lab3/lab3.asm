MYCODE SEGMENT 'CODE'
	ASSUME CS:MYCODE, DS:MYCODE
	 
	LINE DB 0DH, 0AH, '$'
	
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
		MOV AH, 01H
		INT 021H
	RET
	GETCH ENDP	
	
	A_CHAR DB 'A'
	B_CHAR DB '�'
	V_CHAR DB '�'
	
	START:
	;����㧪� ᥣ���⭮�� ॣ���� ������ DS
		PUSH CS
		POP DS   
		
	;����� 1 ������� �� �����
		MOV DL, A_CHAR
		CALL PUTCH
		CALL CLRF
		
	;����� 2 ������� �� �����
		MOV DL, B_CHAR
		CALL PUTCH
		CALL CLRF
		
	;����� 3 ������� �� �����
		MOV DL, V_CHAR
		CALL PUTCH
		CALL CLRF
		
	;�������� ���������� ���������
		MOV AH, 01H
		INT 021H
		
	;����� �� ���������
		MOV AL, 0
		MOV AH, 4CH; 4ch - �����襭�� �ணࠬ��
		INT 021H
		MYCODE ENDS
	END START	