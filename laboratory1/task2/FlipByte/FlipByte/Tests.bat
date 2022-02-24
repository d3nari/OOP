@echo off
SET MyProgram="%~1"

REM Defend from start
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
) 

REM Number not out of bounds
%MyProgram% "11" > %TEMP%\output.txt || goto err
fc %TEMP%\output.txt Number_output.txt > nul || goto err
echo Test 1 passed


exit /B 0

:err 
echo Test failed
exit /B 1