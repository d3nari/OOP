@echo off
SET MyProgram="%~1"

REM Defend from start
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
) 

REM Number not out of bounds
%MyProgram% "202" > %TEMP%\output.txt || goto err
fc %TEMP%\output.txt Number_output.txt > nul || goto err
echo Test 1 passed

REM Null number
%MyProgram% "" > %TEMP%\output.txt && goto err
fc %TEMP%\output.txt Null_Number_output.txt || goto err
echo Test 2 passed

REM Number outs of bounds
%MyProgram% "258" > %TEMP%\output.txt && goto err
fc %TEMP%\output.txt Number_Out_Bounds_output.txt || goto err
echo Test 3 passed

REM Input value not digit
%MyProgram% "1f3" > %TEMP%\output.txt && goto err
fc %TEMP%\output.txt Not_Digit_output.txt || goto err
echo Test 4 passed

exit /B 0

:err 
echo Test failed
exit /B 1