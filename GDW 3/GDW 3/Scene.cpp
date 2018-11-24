#include "Scene.h"
Scene::Scene(Sprite * BG, Sprite * UI, std::vector<character*> actorList)
{
	this->background = BG;
	this->UI = UI;
	this->actorList = actorList;
}
