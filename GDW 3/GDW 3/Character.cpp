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
	int finAttacc = (atcc + 0.5);
	enemy.currentHP -= finAttacc;//does damage based on character damage values
	std::cout << enemy.getName() << " took " << finAttacc << " damage!\n";
	std::cout << enemy.getName() << " HP: " << enemy.getCurrentHP()<<std::endl;
	if (abl.hasStun()) {//checks if the ability has stun
		int randomStun = rand() % 2;
		if (randomStun == 0)
			enemy.stunned = false;
		if (randomStun == 1) {
			std::cout << "STUNNED!\n";
			enemy.stunned = true;//returns true if true
		}
	}

}

void character::heal(ability abl, character & Ally)
{
	srand(time(0));
	std::cout << this->name << " used " << abl.getName() << std::endl;

	double atcc = this->ATTACC;
	atcc = (rand() % ((int)this->ATTACC + 1) + this->ATTACC);
	atcc *= abl.getModifier();//getting new dmg value by multiplying by a percent amount
	if (this->didCrit()) {
		std::cout << "CRIT!!" << std::endl;
		atcc *= 2;
	}
	int finAttacc = (atcc + 0.5);
	Ally.currentHP += finAttacc;//does damage based on character damage values
	std::cout << Ally.name << " was healed " << (int)atcc << " health!\n";
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
	double dodgeTemp = rand() % 100 + 1;
	if (this->position == 2)
		this->dodge += .05;
	if (this->position == 3)
		this->dodge += .10;
	if (this->position == 4)
		this->dodge += .15;

	double dodgeUPSCALED = this->dodge * 100;
	if (dodgeTemp <= dodgeUPSCALED)
		return true;

	return false;

}

bool character::didCrit()
{
	srand(time(0));
	double critTemp = rand() % 100 + 1;

	double critUPSCALED = this->crit * 100;
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
	if (this->speed == enemy.speed || this->speed < enemy.speed)
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

void character::takeTurn(int userIn, character &Enemy)
{
	this->attack(this->getAbility(userIn), Enemy);//attacking an enemy at index 1,2,3,4
}

void character::takeTurnHeals(int userIn, character & Ally)
{
	std::cout << "healy boi\n";
	this->heal(this->getAbility(userIn), Ally);
}

void character::takeEnemyTurn(character &Hero)
{
	this->attack(this->getAbility(1), Hero);
}


