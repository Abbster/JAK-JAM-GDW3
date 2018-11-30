#pragma once
#include "Character.h"
#include <vector>
class Scene {	
public:

	Scene(Sprite* BG, Sprite* UI);
	Scene() {}
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
	character Squatyman;
	character Jelly3;
	character Squatyman2;
	
	//std::vector<character*> actorList;

};