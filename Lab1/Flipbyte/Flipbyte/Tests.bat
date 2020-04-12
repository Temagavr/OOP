@echo off
SET MyProgram = "%~1"

 echo hello, %MyProgram%
 echo hi, %~1

%~1 abc && goto err
echo Test with not a number passed

%~1 && goto err
echo Test without argument passed

%~1 -1 && goto err
echo Test with negative number passed

%~1 256 && goto err
echo Test with out of range number passed

%~1 0 > output.txt || goto err
fc output.txt result_0.txt  || goto err
echo Test with 0 passed

%~1 6 > output.txt || goto err
fc output.txt result_96.txt  || goto err
echo Test with 6 passed

%~1 255 > output.txt || goto err
fc output.txt result_255.txt  || goto err
echo Test with 255 passed

%~1 10 > output.txt || goto err
fc output.txt result_80.txt  || goto err
echo Test with 10 passed

echo All test passed succesfully
exit /B 0 

:err
echo Tests failed
exit /B 1