#include "Character.h"
#include <iostream>
typedef double dataValue, resistance;
typedef bool passive, DEBUFF, BUFF;
//some test stuff

character::character(dataValue hp, dataValue Dodge, dataValue protecc, dataValue spd, dataValue critt, dataValue attacc, std::string NAME)//not sure about min/max damage, still working out the function for that
{

	this->maxHP = hp;
	this->dodge = Dodge;
	this->PROTECC = protecc;
	this->speed = spd;
	this->crit = critt;
	this->ATTACC = attacc;
	this->currentHP = this->maxHP;
	this->name = NAME;
}


void character::attack(ability abl, character &enemy)//this is um...please help my mind is breaking
{

	srand(time(0));
	std::cout << this->name << " used " << abl.getName() << std::endl;
	if (enemy.didDodge()) {
		std::cout << enemy.name << " dodged!\n";
		return;

	}
	double atcc = this->ATTACC;
	atcc = (rand() % ((int)this->ATTACC + 1) + this->ATTACC);
	atcc *= abl.getModifier();//getting new dmg value by multiplying by a percent amount
	if (this->didCrit()) {
		std::cout << "CRIT!!" << std::endl;
		atcc *= 2;
	}
	enemy.currentHP -= (atcc + 0.05);//does damage based on character damage values
	std::cout << enemy.getName() << " took " << (int)atcc << " damage!\n";
	if (abl.getStun()) {//checks if the ability has stun
		int randomStun = rand() % 2;
		if (randomStun == 0)
			enemy.stunned = false;
		if (randomStun == 1)
			enemy.stunned = true;//returns true if true

	}

}

void character::setAbility(ability abl, unsigned int abilityNumber)//pretty simple sheit
{
	switch (abilityNumber) {
	case 1:
		this->able1 = abl;
		break;
	case 2:
		this->able2 = abl;
		break;
	case 3:
		this->able3 = abl;
		break;
	case 4:
		this->able4 = abl;
		break;
	}
}

ability character::getAbility(unsigned int abilitynumber)
{
	switch (abilitynumber) {
	case 1:
		return this->able1;
		break;
	case 2:
		return this->able2;
		break;
	case 3:
		return this->able3;
		break;
	case 4:
		return this->able4;
		break;
	}
}

std::string character::getAbilityName(unsigned int abilitynumber)
{
	switch (abilitynumber) {
	case 1:
		return this->able1.getName();
	case 2:
		return this->able2.getName();
	case 3:
		return this->able3.getName();
	case 4:
		return this->able4.getName();
	}
}


void character::setPosition(unsigned short pos)//just a base setter for the gazillion that need to be done
{
	this->position = pos;
}


bool character::didDodge()
{
	srand(time(0));
	float dodgeTemp = rand() % 100 + 1;
	if (this->position == 2)
		this->dodge += .05;
	if (this->position == 3)
		this->dodge += .10;
	if (this->position == 4)
		this->dodge += .15;

	float dodgeUPSCALED = this->dodge * 100;
	if (dodgeTemp <= dodgeUPSCALED)
		return true;

	return false;

}

bool character::didCrit()
{
	srand(time(0));
	float critTemp = rand() % 100 + 1;

	float critUPSCALED = this->crit * 100;
	if (critTemp <= critUPSCALED)
		return true;

	return false;
}

void character::setStress(dataValue AH)
{
	this->stress = AH;
}

bool character::isSlowerThan(character & enemy)
{
	if (this->speed == enemy.speed||this->speed < enemy.speed)
		return true;
	
	else if (this->speed > enemy.speed)
		return false;
}



dataValue character::getATTACC()
{
	return this->ATTACC;
}

dataValue character::getCurrentHP()
{
	return this->currentHP;
}
