/*
	ShapeX v1.0
	Copyright (C) 2018-2021 MathInDOS
	
	What is it?
	~~~~~~~~~~~
	ShapeX is a single header only file which enables you to draw shapes with default Windows
	Operating System dependency, without using other huge files such as (*.dll). It used GDIPlus
	to draw shapes and GDIPlus already have every Windows PC (Starting from Windows XP to 10)
	
	
	License (QSDL-1)
	~~~~~~~~~~~~~~~~
	
	To know more about LICENSE, take a look of LICENSE.md file.
	
	
	How to Compile? (Windows)
	~~~~~~~~~~~~~~~~~~~~~~~~~
	To compile this file along with project you need to type this (DLL) and need to define (UNICODE\)
	for GCC Compilers
	
	g++ <filename.cpp> -o <output.exe> -lgdiplus -municode
	
	Ex.
	g++ example.cpp -o example.exe -lgdiplus -municode
	
	IMPORTANT FOR OLD COMPILERS!!
	
	If you are using DevC++ or Code::Blocks old version then don't forget to define C++ language standard 
	to -std=c++17 or -std=c++2a
	
	In DevC++
	---------
	-std=c++17 -lgdiplus -municode
	
	Same process to Code::Blocks
	
	MSVC Compilers
	~~~~~~~~~~~~~~
	I don't test this version with MSVC Compiler so if you trying to compile this file with MSVC then you should
	found many types of WARNINGS (or ERRORS). In next version I will add how to compile with MSVC
	
	
	Legacy Mode
	~~~~~~~~~~~
	To use this program in Windows 10 you need to first enable Legacy Mode in cmd.
	Legacy Mode function will add soon!
	
	Example
	~~~~~~~
	
	#include <windows.h>
	#include "ShapeX.h"
		
	int wmain(int argc, wchar_t *argv[])   // For unicode support
	{
		ShapeX shape;
		shape.DrawLine(100, 200, 300, 100, 0, 255, 0, 12);  // x1 y1 x2 y2 r g b pen-width = GDIPlus Line!
		return 0;
	}
	
*/


#define WIN32_LEAN_AND_MEAN
#define Smooth Gdiplus::SmoothingModeHighQuality
#include <windows.h>
#include <gdiplus.h>

class ShapeX
{
	public:
	// Draw Line using point to point
	// Pw Pointer width
	
	void DrawLine(int x1, int y1, int x2, int y2, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw); // Pen Color and Size
		gf.SetSmoothingMode(Smooth);
		gf.DrawLine(&pen, x1, y1, x2, y2);
		// Don't shutdown Gdiplus else your program will crash unexpectedly next line will not execute.
	}
	
	void DrawRec(int x1, int y1, int x2, int y2, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		// Create a rect function that enables everything in one line and quickly.
		Gdiplus::Rect rect(x1, y1, x2, y2);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw); // Pen Color and Size
		gf.SetSmoothingMode(Smooth);
		
		gf.DrawRectangle(&pen, rect);
	}
	
	// Fill the retangle
	
	void FillRec(int x1, int y1, int x2, int y2, int r, int g, int b)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Rect rect(x1, y1, x2, y2);
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		gf.FillRectangle(&brush, rect);
	}
	
	void DrawEllipse(int x1, int y1, int x2, int y2, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		Gdiplus::Rect rect(x1, y1, x2, y2);
		gf.SetSmoothingMode(Smooth);
		gf.DrawEllipse(&pen, rect);
	}
	
	void FillEllipse(int x1, int y1, int x2, int y2, int r, int g, int b)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Rect rect(x1, y1, x2, y2);
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		gf.FillEllipse(&brush, rect);
	}
	
	void DrawCurve(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		 Gdiplus::Point point_1(p1, p2);
		 Gdiplus::Point point_2(p3, p4);
		 Gdiplus::Point point_3(p5, p6);
		 Gdiplus::Point point_4(p7, p8);
		
		Gdiplus::Point everyPoint[4] = {
			point_1,
			point_2,
			point_3,
			point_4
		};
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		gf.SetSmoothingMode(Smooth);
		gf.DrawCurve(&pen, everyPoint, 4);
	}
	
	void DrawLongCurve(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, int p13, int p14, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		Gdiplus::Point point_4(p7, p8);
		Gdiplus::Point point_5(p9, p10);
		Gdiplus::Point point_6(p11, p12);
		Gdiplus::Point point_7(p13, p14);
		
		Gdiplus::Point everyPoint[7] = {
			point_1,
			point_2,
			point_3,
			point_4,
			point_5,
			point_6,
			point_7
		};
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		gf.SetSmoothingMode(Smooth);
		gf.DrawClosedCurve(&pen, everyPoint, 7);
	}
	
	void DrawBeziers(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, int p13, int p14, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		Gdiplus::Point point_4(p7, p8);
		Gdiplus::Point point_5(p9, p10);
		Gdiplus::Point point_6(p11, p12);
		Gdiplus::Point point_7(p13, p14);
		
		Gdiplus::Point everyPoint[7] = {
			point_1,
			point_2,
			point_3,
			point_4,
			point_5,
			point_6,
			point_7
		};
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		gf.SetSmoothingMode(Smooth);
		gf.DrawBeziers(&pen, everyPoint, 7);
	}
	
	void DrawArc(int p1, int p2, int p3, int p4, int p5, int p6, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::REAL x = p1;
		Gdiplus::REAL y = p2;
		Gdiplus::REAL width = p3;
		Gdiplus::REAL height = p4;
		Gdiplus::REAL angle = p5;
		Gdiplus::REAL skip = p6;
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		gf.SetSmoothingMode(Smooth);
		gf.DrawArc(&pen, x, y, width, height, angle, skip);
	}
	
	void DrawTraingle(int p1, int p2, int p3, int p4, int p5, int p6, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		
		Gdiplus::Point everyPoint[3] = {
			point_1,
			point_2,
			point_3
		};
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		gf.SetSmoothingMode(Smooth);
		gf.DrawPolygon(&pen, everyPoint, 3);
	}
	
	void FillTraingle(int p1, int p2, int p3, int p4, int p5, int p6, int r, int g, int b)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		
		Gdiplus::Point everyPoint[3] = {
			point_1,
			point_2,
			point_3
		};
		
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		gf.FillPolygon(&brush, everyPoint, 3);
	}
	
	void DrawCircle(int width, int height, int radius, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		
		gf.SetSmoothingMode(Smooth);
		gf.DrawEllipse(&pen, width-radius, height-radius, radius+radius, radius+radius);
	}
	
	void FillCircle(int width, int height, int radius, int r, int g, int b)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		gf.SetSmoothingMode(Smooth);
		gf.FillEllipse(&brush, width-radius, height-radius, radius+radius, radius+radius);
	}
	
	void DrawPie(int p1, int p2, int p3, int p4, int p5, int p6, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Rect rect(p1, p2, p3, p4);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		Gdiplus::REAL angle = p5;
		Gdiplus::REAL skip = p6;
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawPie(&pen, rect, angle, skip);
	}
	
	void FillPie(int p1, int p2, int p3, int p4, int p5, int p6, int r, int g, int b)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Rect rect(p1, p2, p3, p4);
		
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		Gdiplus::REAL angle = p5;
		Gdiplus::REAL skip = p6;
		gf.FillPie(&brush, rect, angle, skip);
	}
	
	void DrawPolygon(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		Gdiplus::Point point_4(p7, p8);
		Gdiplus::Point point_5(p9, p10);
		
		Gdiplus::Point everyPoint[5] = {
			point_1,
			point_2,
			point_3,
			point_4,
			point_5
			
		};
		
		gf.SetSmoothingMode(Smooth);
		gf.DrawPolygon(&pen, everyPoint, 5);
	}
	
	void FillPolygon(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int r, int g, int b, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		Gdiplus::Point point_4(p7, p8);
		Gdiplus::Point point_5(p9, p10);
		
		Gdiplus::Point everyPoint[5] = {
			point_1,
			point_2,
			point_3,
			point_4,
			point_5
			
		};
		
		gf.FillPolygon(&brush, everyPoint, 5);
	}
	
	void DrawStar(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, int p18, int p19, int p20, int p21, int p22, int r, int g, int b, int pw)
	{
		
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), pw);
		
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		Gdiplus::Point point_4(p7, p8);
		Gdiplus::Point point_5(p9, p10);
		Gdiplus::Point point_6(p11, p12);
		Gdiplus::Point point_7(p13, p14);
		Gdiplus::Point point_8(p15, p16);
		Gdiplus::Point point_9(p17, p18);
		Gdiplus::Point point_10(p19, p20);
		Gdiplus::Point point_11(p21, p22);
	
		Gdiplus::Point everyPoint[11] = {
			point_1,
			point_2,
			point_3,
			point_4,
			point_5,
			point_6,
			point_7,
			point_8,
			point_9,
			point_10,
			point_11
		};
		
		gf.SetSmoothingMode(Smooth);
		gf.DrawPolygon(&pen, everyPoint, 11);
	}
	
	void FillStar(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12, int p13, int p14, int p15, int p16, int p17, int p18, int p19, int p20, int p21, int p22, int r, int g, int b)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
				
		Gdiplus::Point point_1(p1, p2);
		Gdiplus::Point point_2(p3, p4);
		Gdiplus::Point point_3(p5, p6);
		Gdiplus::Point point_4(p7, p8);
		Gdiplus::Point point_5(p9, p10);
		Gdiplus::Point point_6(p11, p12);
		Gdiplus::Point point_7(p13, p14);
		Gdiplus::Point point_8(p15, p16);
		Gdiplus::Point point_9(p17, p18);
		Gdiplus::Point point_10(p19, p20);
		Gdiplus::Point point_11(p21, p22);
	
		Gdiplus::Point everyPoint[11] = {
			point_1,
			point_2,
			point_3,
			point_4,
			point_5,
			point_6,
			point_7,
			point_8,
			point_9,
			point_10,
			point_11
		};
		
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		gf.FillPolygon(&brush, everyPoint, 11);
	}
	
	void DrawText(const wchar_t *arg, int x, int y, int r, int g, int b, const wchar_t *ff, const wchar_t *fs, int pw)
	{
		HDC hdc = GetDC(GetConsoleWindow());

		Gdiplus::GdiplusStartupInput gsi;
		ULONG_PTR token;
		Gdiplus::GdiplusStartup(&token, &gsi, nullptr);
		Gdiplus::Graphics gf(hdc);
		
		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		
		/* Font : Arial */
		if(!_wcsicmp(ff, L"ari") || !_wcsicmp(ff, L"arial"))
		{
			Gdiplus::FontFamily ff(L"Arial", nullptr);

			if(!_wcsicmp(fs, L"regular") || !_wcsicmp(fs, L"regu"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else if(!_wcsicmp(fs, L"italic") || !_wcsicmp(fs, L"ital"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);				
			}
			else if(!_wcsicmp(fs, L"bold") || !_wcsicmp(fs, L"bld"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else if(!_wcsicmp(fs, L"underline") || !_wcsicmp(fs, L"undrline"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else if(!_wcsicmp(fs, L"strikeout") || !_wcsicmp(fs, L"strkout"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else
			{}
		}
		
		/* Font : Calibri */
		else if(!_wcsicmp(ff, L"calibri") || !_wcsicmp(ff, L"calib"))
		{
			Gdiplus::FontFamily ff(L"Calibri", nullptr);
			
			if(!_wcsicmp(fs, L"regular") || !_wcsicmp(fs, L"regu"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else if(!_wcsicmp(fs, L"italic") || !_wcsicmp(fs, L"ital"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);				
			}
			else if(!_wcsicmp(fs, L"bold") || !_wcsicmp(fs, L"bld"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else if(!_wcsicmp(fs, L"underline") || !_wcsicmp(fs, L"undrline"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else if(!_wcsicmp(fs, L"strikeout") || !_wcsicmp(fs, L"strkout"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else
			{}
		}
			
		/* Font : Cambria */
		else if(!_wcsicmp(ff, L"cambria") || !_wcsicmp(ff, L"camb"))
		{
			Gdiplus::FontFamily ff(L"Cambria", nullptr);
			
			if(!_wcsicmp(fs, L"regular") || !_wcsicmp(fs, L"regu"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else if(!_wcsicmp(fs, L"italic") || !_wcsicmp(fs, L"ital"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);				
			}
			else if(!_wcsicmp(fs, L"bold") || !_wcsicmp(fs, L"bld"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else if(!_wcsicmp(fs, L"underline") || !_wcsicmp(fs, L"undrline"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else if(!_wcsicmp(fs, L"strikeout") || !_wcsicmp(fs, L"strkout"))
			{
				Gdiplus::Font font(&ff, pw, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
				gf.DrawString(arg, -1, &font, Gdiplus::PointF(x, y), &brush);
			}
			else
			{}
		}
		
		else
		{}
	}
	
};

