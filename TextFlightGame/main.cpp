#include "console.h"
#include "flight.h"

#include <cstdio>

int main()
{
	int plane_x = 14;
	int plane_y = 28;

	int bullet_x = 0;
	int bullet_y = 0;
	bool is_bullet_exist = false;

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

		if (!is_bullet_exist && GetAsyncKeyState(VK_SPACE) & 0x8000)
		{
			bullet_x = plane_x;
			bullet_y = plane_y - 1;
			is_bullet_exist = true;
		}

		if (is_bullet_exist)
		{
			SetConsoleCursorPos(bullet_x, bullet_y);
			printf("ก่");
			bullet_y -= 1;

			if (bullet_y <= 0) { is_bullet_exist = false; }
		}

		SetConsoleCursorPos(plane_x, plane_y);
		printf("กฺ");
		Sleep(50);
	}
	system("pause");
	return 0;
}