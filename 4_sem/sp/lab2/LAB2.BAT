echo off
:menu
cls
echo 1)  �맢��� ���� �����
echo 2)  ���ଠ�� � ������� help
echo 3)  ���ଠ�� � ������� date
echo 4)  ���ଠ�� � ��㤥��
echo 5)  ��室
be ask "Choose 1,2,3,4,5 - " '12345' default=4 timeout=50
 
if ERRORLEVEL 5 goto 5
if ERRORLEVEL 4 goto 4
if ERRORLEVEL 3 goto 3
if ERRORLEVEL 2 goto 2
if ERRORLEVEL 1 goto 1

goto fin 
:1
cls
echo 1. �맢��� ���� �����
help /all
pause
goto menu 
 
:2
cls 
echo 2. ���ଠ�� � ������� help
help /?
pause 
goto menu 
 
:3
cls 
echo 3. ���ଠ�� � ������� date
echo ������� Date �����뢠�� ⥪���� ���� � �������� �� ��������
pause 
goto menu

:4
cls
echo 4. ���ଠ�� � ��㤥�� 
call myhelp.bat
pause
goto menu

:5
cls
echo 5. ��室
pause
goto fin

:fin 
if (%1) == (yes) call %2 timeout=10
ECHO Closing the program 