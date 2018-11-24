#include "Sprite.h"

Sprite::Sprite(std::string filePath)
{
	this->PATH = filePath;
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
		}
		file.close();
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}

