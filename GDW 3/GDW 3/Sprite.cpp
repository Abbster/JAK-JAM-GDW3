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
void Sprite::setDefaultPosition(int X, int Y)
{
	this->defaultPosition = PositionVector(X, Y);
}

void Sprite::move()
{
	if (isEvent(Events::D)) {
		this->drawme(this->getDefaultPosition().X() + 1, this->getDefaultPosition().Y());
		//this->first.getActor()->drawme(&this->first.getActor()->getDefaultPosition().X + 1, &this->first.getActor()->getDefaultPosition().Y);
		//this->second.getActor()->drawme(&this->second.getActor()->getDefaultPosition().X + 1, &this->second.getActor()->getDefaultPosition().Y);
		//this->third.getActor()->drawme(&this->third.getActor()->getDefaultPosition().X + 1, &this->third.getActor()->getDefaultPosition().Y);
		//this->fourth.getActor()->drawme(&this->fourth.getActor()->getDefaultPosition().X + 1, &this->fourth.getActor()->getDefaultPosition().Y);

	}
}

PositionVector Sprite::getDefaultPosition()
{
	return this->defaultPosition;
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


