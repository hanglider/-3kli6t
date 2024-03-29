@echo off
setlocal EnableDelayedExpansion

set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

set arr[0].file=run_Sorting.bat
set arr[1].file=run_Fibonacci_numbers.bat
set arr[2].file=Diff_enviroments.bat
set arr[3].file=OOP_console.bat
set arr[4].file=BigInteger.bat
set arr[5].file=tests.bat

set arr[0].folder=Sorting
set arr[1].folder=Fibonacci_numbers
set arr[2].folder=Diff_enviroments
set arr[3].folder=OOP_console
set arr[4].folder=BigInteger
set arr[5].folder=tests


for /L %%i in (4) do ( 
	copy ..\%SOURCE_FOLDER%\!arr[%%i].folder!\!arr[%%i].file! .\!arr[%%i].folder!
)

copy ..\run_tests.bat .
