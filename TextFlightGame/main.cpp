#include "console.h"
#include "flight.h"

#include <cstdio>
#include <random>

int main()
{
	int plane_x = 14;
	int plane_y = 28;

	int bullet_x = 0;
	int bullet_y = 0;
	bool is_bullet_exist = false;

	int enemy_x = 0;
	int enemy_y = 0;
	bool is_enemy_exist = false;

	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(0, 28);

	SetConsoleSize(30, 30);

	SetShowCursor(false);

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

		if (!is_enemy_exist)
		{
			enemy_x = dis(gen);
			enemy_y = 0;
			is_enemy_exist = true;
		}

		if (is_enemy_exist)
		{
			SetConsoleCursorPos(enemy_x, enemy_y);
			printf("¢¾");
			enemy_y += 1;
			if (enemy_y > plane_y)
			{
				is_enemy_exist = false;
			}
		}
		

		if (is_bullet_exist)
		{
			SetConsoleCursorPos(bullet_x, bullet_y);
			printf("¡è");
			bullet_y -= 1;

			if (bullet_y <= 0) { is_bullet_exist = false; }
		}

		SetConsoleCursorPos(plane_x, plane_y);
		printf("¡Ú");
		Sleep(50);
	}
	system("pause");
	return 0;
}