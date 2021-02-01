# ShapeX

ShapeX - A Win32 drawing (header only) file

# What is it?
	-----------
	ShapeX is a single header only file which enables you to draw shapes with default Windows
	Operating System dependency, without using other huge files such as (*.dll). It used GDIPlus
	to draw shapes and GDIPlus already have every Windows PC (Starting from Windows XP to 10)
	
	
# License (QSDL-1)
	----------------	
	To know more about LICENSE, take a look of LICENSE.md file.
	
	
# How to Compile? (Windows)
	-------------------------
  To compile this file along with project you need to type this (DLL) and need to define (UNICODE\)
	for GCC Compilers
	
	g++ <filename.cpp> -o <output.exe> -lgdiplus -municode
	
	Ex.
	g++ example.cpp -o example.exe -lgdiplus -municode
	
	IMPORTANT FOR OLD COMPILERS!!
	
	If you are using DevC++ or Code::Blocks old version then don't forget to define C++ language standard 
	to -std=c++17 or -std=c++2a
	
# In DevC++
	---------
	-std=c++17 -lgdiplus -municode
	
	Same process to Code::Blocks
	
# MSVC Compilers
	--------------
	I don't test this version with MSVC Compiler so if you trying to compile this file with MSVC then you should
	found many types of WARNINGS (or ERRORS). In next version I will add how to compile with MSVC
	
	
# Legacy Mode
	-----------
  To use this program in Windows 10 you need to first enable Legacy Mode in cmd.
	Legacy Mode function will add soon!
	
# Example
	-------
	````
  C++
  
	#include <windows.h>
	#include "ShapeX.h"
		
	int wmain(int argc, wchar_t *argv[])   // For unicode support
	{
		ShapeX shape;
		shape.DrawLine(100, 200, 300, 100, 0, 255, 0, 12);  // x1 y1 x2 y2 r g b pen-width = GDIPlus Line!
		return 0;
	}
  ````
