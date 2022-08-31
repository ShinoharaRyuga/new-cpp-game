#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include "DxLib.h"
#include "dxlib_ext.h"

void DrawStringEx(const int x, const int y, const int color, const char* _str, ...) {
	char buff[255] = { 0 };
	va_list argptr;
	va_start(argptr, _str);
	vsprintf_s(buff, _str, argptr);
	va_end(argptr);
	DrawString(x, y, buff, color);
}

void DrawLineEx(const tnl::Vector3& p, const tnl::Vector3& v, const float length, const int color) {
	tnl::Vector3 n = v;
	n.normalize();
	n *= length;
	DrawLine((int)p.x, (int)p.y, (int)p.x + (int)n.x, (int)p.y + (int)n.y, color, false);
}

void DrawBoxEx(const tnl::Vector3& p, const float width, const float height, const bool fill, const int color) {
	float lx = p.x - width * 0.5f;
	float rx = p.x + width * 0.5f;
	float up = p.y - height * 0.5f;
	float down = p.y + height * 0.5f;
	DrawBox((int)lx, (int)up, (int)rx, (int)down, color, fill);
}


void DrawGridGround(const float square_size, int row_num, int color) {

	MATRIX im;
	CreateIdentityMatrix(&im);
	SetTransformToWorld(&im);

	row_num = (1 == row_num % 2) ? row_num + 1 : row_num;

	float l = square_size * row_num * 0.5f;
	float n = -l;
	for (int i = 0; i < row_num + 1; ++i) {
		if ((row_num >> 1) == i) {
			DrawLine3D({ n, 0, l }, { n, 0, -l }, 0xffff0000);
			DrawLine3D({ l, 0, n }, { -l, 0, n }, 0xff0000ff);
		}
		else {
			DrawLine3D({ n, 0, l }, { n, 0, -l }, color);
			DrawLine3D({ l, 0, n }, { -l, 0, n }, color);
		}
		n += square_size;
	}
	DrawLine3D({ 0, l, 0 }, { 0, -l, 0 }, 0xff00ff00);

}

