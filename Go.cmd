if .%USERDOMAIN% == .Pijus goto :savasPC
Rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPC
make

:toliau
main.exe > result0.txt

echo 3 3 >> test1.cfg
echo 1 2 >> test1.cfg
echo 2 3 >> test1.cfg
echo 3 1 >> test1.cfg

main.exe test1.cfg > result1.txt

echo 4 0 >> test1.cfg

main.exe test2.cfg > result2.txt