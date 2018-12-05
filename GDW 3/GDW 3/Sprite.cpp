#include "Sprite.h"


//draws to a given X Y
void gotoxy(int x, int y)
{
	//coord that stores X Y
	COORD pos = { x, y };
	//handle that will ouput in the right place
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	//sets the cursor position to our given X Y properly
	SetConsoleCursorPosition(output, pos);
}
Sprite::Sprite(std::string filePath)
{
	this->PATH = filePath;
}

//draw at a given X Y
void Sprite::drawme(int x, int y)
{
	//create an object of string and in-file stream
	std::string line;
	std::ifstream file;

	//open this file
	file.open(this->PATH);

	//try to open the file
	if (file.is_open())
	{
		while (getline(file, line))//while we aren't at the end of the file
		{
			gotoxy(x, y);
			std::cout << line << "\n";//print things from the file
			y++;// incrememnt Y to push to the next line
		}
		file.close();//close the line
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

std::string Sprite::getPath()
{
	return this->PATH;
}

void Sprite::setPath(std::string FILEPATH)
{
	this->PATH = FILEPATH;
}


