#pragma once

#include "console.h"

void SetConsolePos(short x, short y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetConsolePos()
{
	CONSOLE_SCREEN_BUFFER_INFO cur_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);

	return { cur_info.dwCursorPosition.X, cur_info.dwCursorPosition.Y };
}

void SetConsoleColor(unsigned char bg_color, unsigned char text_color)
{
	if (bg_color > 15 || text_color > 15) { return; }

	unsigned short color = (bg_color << 4) | text_color;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SetShowCursor(bool flag)
{
	CONSOLE_CURSOR_INFO cur_info;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);
	cur_info.bVisible = flag;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);
}