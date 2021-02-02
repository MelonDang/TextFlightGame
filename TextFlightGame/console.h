#include <windows.h>

void SetConsolePos(short x, short y);
COORD GetConsolePos();
void SetConsoleColor(unsigned char bg_color, unsigned char text_color);
void SetShowCursor(bool flag);