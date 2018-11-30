#pragma once
#include <string>
#include <cstdlib>
#include<ctime>
#include <vector>
#include "ability.h"
#include "Sprite.h"
#include "UserInterface.h"
#include "Inventory.h"

class character {

public:
	
	//test functions with templates for literally anything
	typedef double dataValue,resistance;
	typedef bool passive, DEBUFF,BUFF;
	
	void die();
	//wrapper function
	void drawUserInterface();

	//takes in base values
	character(dataValue hp, dataValue Dodge, dataValue protecc, dataValue spd, dataValue critt, dataValue attacc, std::string NAME, Sprite * SPRITE);
	character();
	
	void setUI(UserInterface userInterface);
	UserInterface getUserInterface();

	void setAbility(ability abl,unsigned int abilityNumber);
	void attack(ability abl, character &enemy);
	void heal(ability abl, character &ally);
	
	ability getAbility(unsigned int abilitynumber);
	std::string getAbilityName(unsigned int abilitynumber);

	Sprite* getActor();
	
	
	void setPosition(unsigned short pos);
	unsigned short getPosition ();
	bool didDodge();
	bool didCrit();
	void setStress(dataValue AH);
	dataValue getStress();
	void setHeartAttack(bool YN);
	DEBUFF getHeartAttack();
	bool isSlowerThan(character &enemy);
	bool isStunned();
	void setStun(bool YN);

	
	std::string getName();
	dataValue getSpeed();
	void setSpeed(dataValue s);
	void setHealthBar(std::string s);
	dataValue getATTACC();
	dataValue getCurrentHP();
	void takeTurn(int userIn,character & Enemy);
	void takeTurnHeals(int userIn, character & Ally);
	void takeEnemyTurn(character & Hero);

	//data members...a lot of which are going to be cut (yikes)
private:
	dataValue
		maxHP,
		currentHP,
		dodge,
		speed,
		PROTECC,
		crit,
		ATTACC,
		stress;
		int inBetweenDamage;//this will be the random number between damagemin and damage max
	passive
		corpseClear,
		preventAmbush,
		religious;
	DEBUFF
		bleed,
		blight,
		stunned = false,
		debuff,
		mark,
		move,
		horror,
		heartAttack = false,
		deathsDoor,
		deathsDoorRecovery;
	BUFF//maybe cut
		buff,
		guard,
		riposte,
		restoration,
		aegis;
	ability
		able1,
		able2,
		able3,
		able4;
	std::string name;
	std::string healthBar;
	bool corpse,didAttacc;
	unsigned short position;//1,2,3,4
	bool isDead = false;


	Sprite * actor;
	UserInterface USER_INTERFACE;
	//each character should have a sprite

		

};


class Party : character {

public:
	Party();
	Party(character FIRST, character SECOND, character THIRD, character FOURTH, Inventory INVENTORY);

	Inventory& getInventory();

private:
	character first, second, third, fourth;
	Inventory inventory;

};

