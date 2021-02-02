#include <windows.h>

void SetConsoleCursorPos(short x, short y);
COORD GetConsoleCursorPos();
void SetConsoleColor(unsigned char bg_color, unsigned char text_color);
void SetShowCursor(bool flag);
void SetConsoleSize(int cols, int lines);