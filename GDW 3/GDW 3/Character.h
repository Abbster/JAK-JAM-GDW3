#pragma once
#include <string>
#include <cstdlib>
#include<ctime>
#include <vector>
#include "ability.h"
#include "Sprite.h"
#include "UserInterface.h"
#include "Inventory.h"

//main character class
class character {

public:

	//typedef to organize values
	typedef double dataValue, resistance;
	typedef bool passive, DEBUFF, BUFF;

	void die();
	//wrapper function
	void drawUserInterface();

	//takes in base values to construct a character
	character(dataValue hp, dataValue Dodge, dataValue protecc, dataValue spd, dataValue critt, dataValue attacc, std::string NAME, Sprite * SPRITE);
	character();//default constructor


	//sets a character's UI
	void setUI(UserInterface userInterface);

	//sets an ability to a character
	void setAbility(ability abl, unsigned int abilityNumber);
	//attack function, main focus of combat
	void attack(ability abl, character &enemy);
	//same as attack function
	void heal(ability abl, character &ally);

	//getters for ability and the name of an ability
	ability getAbility(unsigned int abilitynumber);
	std::string getAbilityName(unsigned int abilitynumber);

	//getter and setter for this character's actor
	void setActor(Sprite* s);
	Sprite* getActor();

	//getter and setter for position
	void setPosition(unsigned short pos);
	unsigned short getPosition();
	
	//functions to check if the character dodged or crit
	bool didDodge();
	bool didCrit();

	//might not need
	void setHeartAttack(bool YN);
	DEBUFF getHeartAttack();

	//function that check if a character is slower than another
	bool isSlowerThan(character &enemy);
	//checks if a hero is stunned
	bool isStunned();
	//variable to set stun value of a character
	void setStun(bool YN);

	//getters for the name of a character
	std::string getName();
	std::string& getNameREFERENCE();//might not need

	//might not need
	void makeDead(int YN);
	bool amDead();
	
	//getter and setter of speed
	dataValue getSpeed();
	void setSpeed(dataValue s);
	
	dataValue getATTACC();
	dataValue getCurrentHP();
	void takeTurn(int userIn, character & Enemy);
	void takeTurnHeals(int userIn, character & Ally);
	void takeEnemyTurn(character & Hero);

	

	//data members
private:
	dataValue//basic data values
		maxHP,
		currentHP,
		dodge,
		speed,
		PROTECC,
		crit,
		ATTACC;

	DEBUFF
		stunned = false,
		heartAttack = false;
	ability
		able1,
		able2,
		able3,
		able4;
	std::string name;
	std::string healthBar;
	bool corpse, didAttacc;
	unsigned short position;//1,2,3,4
	bool isDead = false;


	//sprite for the character
	Sprite * actor;
	//user interface for each character
	UserInterface USER_INTERFACE;



};

//Party class
class Party : character {

public:
	Party();
	Party(character FIRST, character SECOND, character THIRD, character FOURTH, Inventory INVENTORY);

	//gets an inventory reference
	Inventory& getInventory();

private:
	character first, second, third, fourth;
	//inventory object
	Inventory inventory;

};

