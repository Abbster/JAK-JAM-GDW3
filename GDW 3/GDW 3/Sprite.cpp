#include "Sprite.h"

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}
Sprite::Sprite(std::string filePath)
{
	this->PATH = filePath;
}

void Sprite::drawme(int x, int y)
{
	std::string line;
	std::ifstream file;

	file.open(this->PATH);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			gotoxy(x, y);
			std::cout << line << "\n";
			y++;
		}
		file.close();
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}
void Sprite::drawme()
{
	std::string line;
	std::ifstream file;

	file.open(this->PATH);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			std::cout << line << "\n";
			//y++;
		}
		file.close();
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}

void Sprite::setPath(std::string FILEPATH)
{
	this->PATH = FILEPATH;
}


