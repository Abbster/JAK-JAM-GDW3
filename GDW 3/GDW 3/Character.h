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
	typedef bool passive, DEBUFF,BUFF,abilities;
	

	//takes in base values
	character(dataValue hp, dataValue Dodge, dataValue protecc, dataValue spd, dataValue accMod, dataValue critt, dataValue dmgmin);
	void doDamage(character enemy);
	void attack(ability abl, character enemy);
	void setAbility(ability abl,unsigned int abilityNumber);
	void setPosition(unsigned short pos);
	//data members...a lot of which are going to be cut (yikes)
private:
	dataValue
		maxHP,
		currentHP,
		dodge,
		speed,
		accuracyMod,
		protection,
		crit,
		damageMin,
		damageMax;
		int inBetweenDamage;//this will be the random number between damagemin and damage max
	passive
		corpseClear,
		preventAmbush,
		religious;
	DEBUFF
		bleed,
		blight,
		stun,
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
	std::vector<ability> abiles;
	bool corpse;
	unsigned short position;//1,2,3,4

		

};


