#pragma once
#include "Character.h"
#include <vector>
class Scene {	
public:

	Scene(Sprite* BG, Sprite* UI);
	void play();
	void initializeTheCrazyPeople();

	void killCharacter(character &c);

	 ~Scene();
	
	

private:
	Sprite* background;
	Sprite* UI;
	//unsigned int lightLevel = 10; might be a bit hard to manage
	std::vector<character> Enemies;//vector of enemies
	std::vector<character> Heroes;//vector of heroes
	std::vector<character> combatList;
	character Crusader;
	character GraveRobber;
	character Highwayman;
	character Vestal;
	character Jelly	;
	character Jelly2;
	character Jelly3;
	character Jelly4;
	
	//std::vector<character*> actorList;

};