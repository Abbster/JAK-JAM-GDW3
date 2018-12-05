#include "Inventory.h"

Inventory::Inventory()
{
}

std::vector<Item*>& Inventory::getItems()
{
	return this->items;
}

//adds an item
void Inventory::addItem(Item * item)
{
	this->items.push_back(item);
}

//makes a new item
Item::Item(std::string NAME, Sprite * THUMBNAIL)
{
	this->name = NAME;
	this->thumbnail = THUMBNAIL;
}

Item::Item()
{
}
