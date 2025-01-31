#pragma once

#include "console.h"

#include <cstdio>

void SetConsoleCursorPos(short x, short y)
{
	const COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetConsoleCursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO cur_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur_info);

	return { cur_info.dwCursorPosition.X, cur_info.dwCursorPosition.Y };
}

void SetConsoleColor(unsigned char bg_color, unsigned char text_color)
{
	if (bg_color > 15 || text_color > 15) { return; }

	const unsigned short color = (bg_color << 4) | text_color;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SetShowCursor(bool flag)
{
	CONSOLE_CURSOR_INFO cur_info;
	const HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(console_handle, &cur_info);
	cur_info.bVisible = flag;
	SetConsoleCursorInfo(console_handle, &cur_info);
}

void SetConsoleSize(int cols, int lines)
{
	char command[100];
	sprintf_s(command, "mode con cols=%d lines=%d", cols, lines);
	system(command);
}