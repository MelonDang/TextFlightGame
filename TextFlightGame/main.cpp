#include "console.h"
#include "flight.h"

#include <cstdio>

int main()
{
	int plane_x = 14;
	int plane_y = 28;

	SetConsoleSize(30, 30);

	while (true)
	{
		system("cls");

		if (GetAsyncKeyState(VK_LEFT) & 0x8000 && plane_x > 0)
		{
			plane_x -= 1;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && plane_x < 28)
		{
			plane_x += 1;
		}

		SetConsolePos(plane_x, plane_y);
		printf("¡Ú");
		Sleep(50);
	}
	system("pause");
	return 0;
}