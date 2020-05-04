echo off
:menu
cls
echo 1)  вызвать меню помощи
echo 2)  информация о команде help
echo 3)  информация о команде date
echo 4)  Информация о студенте
echo 5)  Выход
be ask "Choose 1,2,3,4,5 - " '12345' default=4 timeout=50
 
if ERRORLEVEL 5 goto 5
if ERRORLEVEL 4 goto 4
if ERRORLEVEL 3 goto 3
if ERRORLEVEL 2 goto 2
if ERRORLEVEL 1 goto 1

goto fin 
:1
cls
echo 1. вызвать меню помощи
help /all
pause
goto menu 
 
:2
cls 
echo 2. информация о команде help
help /?
pause 
goto menu 
 
:3
cls 
echo 3. информация о команде date
echo Команда Date показывает текущую дату и позволяет ее изменить
pause 
goto menu

:4
cls
echo 4. Информация о студенте 
call myhelp.bat
pause
goto menu

:5
cls
echo 5. Выход
pause
goto fin

:fin 
if (%1) == (yes) call %2 timeout=10
ECHO Closing the program 