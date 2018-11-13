#include "Character.h"


//some test stuff

character::character(dataValue hp, dataValue Dodge, dataValue protecc, dataValue spd, dataValue accMod, dataValue critt, dataValue dmgmin,dataValue dmgmax)//not sure about min/max damage, still working out the function for that
{
	srand(time(0));

	
	this->maxHP = hp;
	this->dodge = Dodge;
	this->protection = protecc;
	this->speed = spd;
	this->accuracyMod = accMod;
	this->crit = critt;
	this->damageMin = dmgmin;
	this->damageMax = dmgmax;
	this->maxHP = this->currentHP;
}


void character::attack(unsigned short targetpos,character enemy, ability abl)//this is um...please help my mind is breaking
{
	
	
}
void character::setAbility1(ability abl)//pretty simple sheit
{
	this->able1 = abl;
}

void character::setPosition(unsigned short pos)//just a base setter for the gazillion that need to be done
{
	this->position = pos;
}
