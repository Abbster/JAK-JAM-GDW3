#pragma once
#include "Character.h"
#include <vector>
class Scene {	
public:

	Scene(Sprite* BG, Sprite* UI);
	void play();
	void initializeTheCrazyPeople();

	 ~Scene();
	
	

private:
	Sprite* background;
	Sprite* UI;
	//unsigned int lightLevel = 10; might be a bit hard to manage
	

	
	//std::vector<character*> actorList;

};