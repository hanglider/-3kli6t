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

set arr[0].file=tests.bat
set arr[1].file=run_double_linked_list_tests.bat
set arr[2].file=run_vector_tests.bat

set arr[5].folder=tests
set arr[6].folder=run_double_linked_list_tests
set arr[7].folder=run_vector_tests


for /L %%i in (0, 1, 2) do ( 
	copy ..\%SOURCE_FOLDER%\!arr[%%i].folder!\!arr[%%i].file! .\!arr[%%i].folder!
)

copy ..\run_tests.bat .
