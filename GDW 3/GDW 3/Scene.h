#pragma once
#include "Character.h"
#include <vector>
class Scene {	//Abstract base class -> this is just an outline, a base Scene object never exists, only derivitives like start scene and main scene and end scene exist.
public:

	Scene(Sprite* BG, Sprite* UI);
	void play();
	void initializeTheCrazyPeople();

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

	//character GraveRobber;
	//ability PickToTheFace;
	//ability Lunge;
	//ability ThrownDagger;
	//
	//character Crusader(33, 0.05, 1, 1, 0.03, 6, "Crusader", CRUSADER_SPRITE);
	//ability Smite;
	//ability StunningBlow;
	//ability HolyLance;
	//
	//
	//character Highwayman;
	//ability GrapeshotBlast;
	//ability PointBlackShot;
	//ability PistolShot;
	//
	//character Vestal;
	//ability DivineGrace;
	//ability Dazzle;
	//ability DivineComfort;
	


	
	//std::vector<character*> actorList;

};