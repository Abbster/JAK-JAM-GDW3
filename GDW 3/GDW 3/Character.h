#pragma once
#include <string>
#include <cstdlib>
#include<ctime>
#include <vector>
#include "ability.h"

class character {

public:
	
	//test functions with templates for literally anything
	typedef double dataValue,resistance;
	typedef bool passive, DEBUFF,BUFF;
	

	//takes in base values
	character(dataValue hp, dataValue Dodge, dataValue protecc, dataValue spd, dataValue critt, dataValue attacc, std::string NAME);
	
	
	void setAbility(ability abl,unsigned int abilityNumber);
	void attack(ability abl, character &enemy);
	
	ability getAbility(unsigned int abilitynumber);
	std::string getAbilityName(unsigned int abilitynumber);
	
	
	void setPosition(unsigned short pos);
	bool didDodge();
	bool didCrit();
	void setStress(dataValue AH);
	bool isSlowerThan(character &enemy);
	bool isStunned() { return this->stunned; }
	
	std::string getName() { return this->name; }
	void setHealthBar(std::string s) { this->healthBar = s; }
	dataValue getATTACC();
	dataValue getCurrentHP();

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
		stunned,
		debuff,
		mark,
		move,
		horror,
		heartAttack,
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
	bool corpse;
	unsigned short position;//1,2,3,4

		

};


