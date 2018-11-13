#pragma once
#include <string>
#include <cstdlib>
#include<ctime>
#include "ability.h"
class character {

public:
	
	//test functions with templates for literally anything
	typedef double dataValue,resistance;
	typedef bool passive, DEBUFF,BUFF,abilities;
	

	//takes in base values
	character(dataValue hp, dataValue Dodge, dataValue protecc, dataValue spd, dataValue accMod, dataValue critt, dataValue dmgmin, dataValue dmgmax);
	void attack(unsigned short target,character enemy,ability abl);
	void setAbility1(ability abl);
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
	resistance
		stun_resist,
		poison_resist,
		bleed_resist,
		debuff_resist,
		move_resist,
		disease_resist,
		trap_resist;
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
	BUFF
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
	unsigned short position;//1,2,3,4

		


};


