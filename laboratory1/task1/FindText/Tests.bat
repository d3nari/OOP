@echo off
SET MyProgram="%~1"

REM Defend from start
if %MyProgram%=="" (
	echo Please specify path to program
	exit /B 1
) 

REM Find exist word in multi-line file 
%MyProgram% MultiLineFile.txt "needle" > %TEMP%\output.txt || goto err
fc %TEMP%\output.txt MultiLineFile_output.txt > nul || goto err
echo Test 1 passed

REM Find exist word in single-line file 
%MyProgram% SingleLineFile.txt "Needle" > %TEMP%\output.txt || goto err
fc %TEMP%\output.txt SingleLineFile_output.txt > nul || goto err
echo Test 2 passed

REM Find exist word in empty file 
%MyProgram% EmptyFile.txt "Needle" > %TEMP%\output.txt || goto err
fc %TEMP%\output.txt EmptyFile_output.txt > nul || goto err
echo Test 3 passed

REM Find non-exist word in multi-line file 
%MyProgram% WithoutSearchWordFile.txt "needle" > %TEMP%\output.txt || goto err
fc %TEMP%\output.txt WithoutSearchWordFile_output.txt > nul || goto err
echo Test 4 passed

REM Find null word in file
%MyProgram% FileForNullWord.txt "" > %TEMP%\output.txt && goto err
fc %TEMP%\output.txt FileForNullWord_output.txt > nul || goto err
echo Test 5 passed

REM Incorrect file
%MyProgram% FileNameWithEror.txt "needle" > %TEMP%\output.txt && goto err
fc %TEMP%\output.txt FileNameWithEror_output.txt > nul || goto err
echo Test 6 passed

exit /B 0

:err 
echo Test failed
exit /B 1