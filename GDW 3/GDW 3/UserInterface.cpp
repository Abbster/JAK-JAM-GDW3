#include "UserInterface.h"

UserInterface::UserInterface()
{

}

UserInterface::UserInterface(std::string FILEPATH)
{
	this->charUI.setPath(FILEPATH);
}

Sprite UserInterface::getSprite()
{
	return this->charUI;
}
