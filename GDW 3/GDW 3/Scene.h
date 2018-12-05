#pragma once
#include "Character.h"
#include <vector>
class Scene {	
public:

	Scene(Sprite* BG, Sprite* UI);
	Scene() {}
	void play();
	//function for initializing everything
	void initializeTheCrazyPeople();

	void killCharacter(character &c);
	void checkTorchSprite(Sprite &t);

	
	 ~Scene();
	
	
	 //Keeps stress throughout battles
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
	character SkeletonWitch;
	character Defender;
	character Skeleton;
	character Brawler;

	//pseudo shit
	int lightLevel = 10;
	
	//std::vector<character*> actorList;

};