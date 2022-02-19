SET MyProgram="%~1"

REM Defend from start
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
) 

REM Copy empty file
%MyProgram% Empty.txt "%TEMP%\output.txt" || goto err
fc Empty.txt "%TEMP%\output.txt" || goto err

REM Copy empty file
%MyProgram% NonEmptyFile.txt "%TEMP%\output.txt" || goto err
fc NonEmptyFile.txt "%TEMP%\output.txt" || goto err


REM Tests sucsessful
exit /B 0

REM Drop error
:err 
echo Test failed
exit /B 1