#include "drawing.h"
#include <Windows.h>

void draw(std::string txt)
{
	std::string line;
	std::ifstream file;

	file.open(txt);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			std::cout << line << "\n";	
		}
		file.close();
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}