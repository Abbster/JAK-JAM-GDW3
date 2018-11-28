#include "Inventory.h"

Inventory::Inventory()
{
}

std::vector<Item*> Inventory::getItems()
{
	return this->items;
}

Item::Item(std::string NAME, Sprite * THUMBNAIL)
{
	this->name = NAME;
	this->thumbnail = THUMBNAIL;
}

Item::Item()
{
}
