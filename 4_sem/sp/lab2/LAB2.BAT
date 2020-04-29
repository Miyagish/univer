echo off
:menu
cls
echo 1)  ãæ©
echo 2)  Lý¯þ¨üð¡ø  þ úþüðýôõ help
echo 3)  Lý¯þ¨üð¡ø  þ úþüðýôõ date
echo 4)  Lý¯þ¨üð¡ø  þ ¸ªºôõýªõ
echo 5)  Tv¿þô
be ask "Choose 1,2,3,4,5 - " '12345' default=4 timeout=50
 
if ERRORLEVEL 5 goto 5
if ERRORLEVEL 4 goto 4
if ERRORLEVEL 3 goto 3
if ERRORLEVEL 2 goto 2
if ERRORLEVEL 1 goto 1

goto fin 
:1
cls
echo 1. Tv÷þò üõý¦ ÿþüþø
help /all
pause
goto menu 
 
:2
cls 
echo 2. Lý¯þ¨üð¡ø  þ úþüðýôõ help
help /?
pause 
goto menu 
 
:3
cls 
echo 3. Lý¯þ¨üð¡ø  þ úþüðýôõ date
echo ¦þüðýôð Date ÿþúð÷vòðõª ôðªº ø ÿþ÷òþû õª õ¬ ø÷üõýøª¹
pause 
goto menu

:4
cls
echo 4. Lý¯þ¨üð¡ø  þ ¸ªôõýªõ
call myhelp.bat
pause
goto menu

:5
cls
echo 5. òv¿þô
pause
goto fin

:fin 
if (%1) == (yes) call %2
ECHO Closing the program 