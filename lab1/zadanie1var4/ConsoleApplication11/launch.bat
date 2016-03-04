rem @echo off
SET program="%1"
if %program% == "" goto err

echo 1
%program% empty.txt output1.txt 1 123
if ERRORLEVEL 1 goto testFailed

echo 2
%program% input.txt output2.txt 123 0
if ERRORLEVEL 1 goto testFailed

echo 3
%program% input1.txt output3.txt are qwerty
if ERRORLEVEL 1 goto testFailed

echo 4
%program% input2.txt output4.txt ma mama
if ERRORLEVEL 1 goto testFailed

echo 5
%program% input3.txt output5.txt 1231234 mama
if ERRORLEVEL 1 goto testFailed

echo 6
%program% input1.txt output6.txt 123
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>