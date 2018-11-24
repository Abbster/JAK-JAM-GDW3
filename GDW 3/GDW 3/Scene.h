#pragma once
#include "Character.h"
#include <vector>
class Scene {
public:

	Scene(Sprite* BG, Sprite* UI, std::vector<character*> actorList);
	~Scene();



private:
	Sprite* background;
	Sprite* UI;
	std::vector<character*> actorList;

};