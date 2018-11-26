#pragma once
#include "Character.h"
#include <vector>
class Scene {	//Abstract base class -> this is just an outline, a base Scene object never exists, only derivitives like start scene and main scene and end scene exist.
public:

	Scene(Sprite* BG, Sprite* UI);
	void play();

	 ~Scene();//virtual...?
	
	////Overload these to give different behaviour based on scene ie putting code to draw differently based on the scene like drawing splash screen vs gameloop.
	//virtual void start();// = 0;
	//virtual void update() = 0;
	//virtual void finish();// = 0;
	////Can have as many polymorphics methods as you like
	//
	//virtual void custom1();
	//virtual void custom2();

private:
	Sprite* background;
	Sprite* UI;
	//std::vector<character*> actorList;

};

