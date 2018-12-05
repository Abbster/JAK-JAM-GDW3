#pragma once
#include "Sprite.h"
class UserInterface 
{
public:
	UserInterface();
	UserInterface(std::string FILEPATH);

	Sprite getSprite();
private:
	Sprite charUI;//character UI


};

