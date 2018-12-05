#pragma once
#include "Sprite.h"
#include <string>
#include <vector>

class Item {

public:
	//Contructor for an item
	Item(std::string NAME, Sprite* THUMBNAIL);
	Item();
	
	//Function for using a torch
	void useTorch();

private:
	//Stuff
	std::string name;
	Sprite* thumbnail;

};

class Inventory {

public:
	Inventory();
	//list of references to item pointers
	std::vector<Item*>& getItems();
	void addItem(Item *item);//add an item to the inventory


private:
	std::vector<Item*> items;

};