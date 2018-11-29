#pragma once
#include "Sprite.h"
#include <string>
#include <vector>

class Item {

public:
	Item(std::string NAME, Sprite* THUMBNAIL);
	Item();
	

	void useTorch();

private:
	std::string name;
	Sprite* thumbnail;

};

class Inventory {

public:
	Inventory();
	std::vector<Item*>& getItems();
	void addItem(Item *item);


private:
	std::vector<Item*> items;

};