#pragma once
#include "Sprite.h"

class Item {

public:
	Item(std::string NAME, Sprite* THUMBNAIL,int itemid);
	Item();


private:
	std::string name;
	Sprite* thumbnail;
	int ITEM_ID;

};