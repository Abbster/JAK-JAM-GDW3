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
	void checkTorchSprite(Sprite &t);

	
	 ~Scene();
	
	

	static int stress1, stress2, stress3, stress4;
private:
	Sprite* background;
	Sprite* UI;
	Sprite* topTorch;
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

	//pseudo shit
	int lightLevel = 10;
	
	//std::vector<character*> actorList;

};