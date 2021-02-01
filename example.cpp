#include <windows.h>
#include "ShapeX.h"
	
int wmain(int argc, wchar_t *argv[])   // For unicode support
{
	ShapeX shape;
	shape.DrawLine(100, 200, 300, 100, 0, 255, 0, 12);
	return 0;
}
