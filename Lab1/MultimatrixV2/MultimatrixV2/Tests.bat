@echo off
SET MyProgram = "%~1"

%~1 && goto Error
echo Test without arguments passed

%~1 matrix1.txt && goto Error
echo Test with 1 argument passed

%~1 matrix1.txt zero_matrix.txt > output.txt || goto Error
FC 0_matrix.txt output.txt || goto Error
echo Test with multiplication by the zero matrix on the right passed

%~1 zero_matrix.txt matrix1.txt > output.txt || goto Error
FC 0_matrix.txt output.txt || goto Error
echo Test with multiplication by the zero matrix on the left passed

%~1 matrix1.txt unit_matrix.txt > output.txt || goto Error
FC 6_matrix.txt output.txt || goto Error
echo Test with multiplication by the unit matrix on the right passed

%~1 unit_matrix.txt matrix1.txt > output.txt || goto Error
FC 1_matrix.txt output.txt || goto Error
echo Test with multiplication by the unit matrix on the left passed

%~1 unit_matrix.txt matrix4.txt > output.txt || goto Error
FC double_matrix.txt output.txt || goto Error
echo Test with multiplication double matrix by the unit matrix on the left passed

%~1 matrix4.txt unit_matrix.txt > output.txt || goto Error
FC double_matrix_2.txt output.txt || goto Error
echo Test with multiplication double matrix by the unit matrix on the right passed


echo All tests passed succesfully
exit /B 0

:Error
echo Tests failed
exit /B 1
