rem @echo off
SET program="%1"
if %program% == "" goto err

%program% > out.txt
if ERRORLEVEL 1 goto testFailed
replace.exe empty.txt output.txt 1 123
if ERRORLEVEL 1 goto testFailed

%program% Hello > out2.txt
if ERRORLEVEL 1 goto testFailed
replace.exe input.txt out.txt are is
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>