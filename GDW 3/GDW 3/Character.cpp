#include "Character.h"


//some test stuff

character::character(dataValue hp, dataValue Dodge, dataValue protecc, dataValue spd, dataValue accMod, dataValue critt, dataValue dmgmin)//not sure about min/max damage, still working out the function for that
{
	
	this->maxHP = hp;
	this->dodge = Dodge;
	this->protection = protecc;
	this->speed = spd;
	this->accuracyMod = accMod;
	this->crit = critt;
	this->damageMin = dmgmin;
	this->currentHP = this->maxHP;
}


void character::attack(ability abl,character enemy)//this is um...please help my mind is breaking
{
	abl.setTarget(enemy);
	doDamage(enemy);
}
void character::doDamage(character enemy) {
	srand(time(0));
	int dmg = rand() % ((int)this->damageMin + 1) + (int)this->damageMin;
	enemy.currentHP - dmg;

}
void character::setAbility(ability abl,unsigned int abilityNumber)//pretty simple sheit
{
	this->abiles[abilityNumber];
}

void character::setPosition(unsigned short pos)//just a base setter for the gazillion that need to be done
{
	this->position = pos;
}
