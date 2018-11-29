#include "Inventory.h"

Inventory::Inventory()
{
}

std::vector<Item*>& Inventory::getItems()
{
	return this->items;
}

void Inventory::addItem(Item * item)
{
	this->items.push_back(item);
	std::cout << "WORKS";
}


Item::Item(std::string NAME, Sprite * THUMBNAIL)
{
	this->name = NAME;
	this->thumbnail = THUMBNAIL;
}

Item::Item()
{
}
