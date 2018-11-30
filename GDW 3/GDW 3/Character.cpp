#include "Character.h"
#include "drawing.h"
#include <iostream>
typedef double dataValue, resistance;
typedef bool passive, DEBUFF, BUFF;





void character::die()
{

	//replacing sprite
	this->actor->setPath("bones.txt");


}

void character::drawUserInterface()
{
	this->USER_INTERFACE.getSprite().drawme(0, 64);
}

//character constructor
character::character(dataValue hp, dataValue Dodge, dataValue protecc, dataValue spd, dataValue critt, dataValue attacc, std::string NAME, Sprite * SPRITE)
{

	this->maxHP = hp;
	this->dodge = Dodge;
	this->PROTECC = protecc;
	this->speed = spd;
	this->crit = critt;
	this->ATTACC = attacc;
	this->currentHP = this->maxHP;
	this->name = NAME;
	this->actor = SPRITE;
}

character::character()
{
}

void character::setUI(UserInterface userInterface)
{
	this->USER_INTERFACE = userInterface;
}

//damage calculation
void character::attack(ability abl, character &enemy)
{
	srand(time(0));
	gotoxy(5, 51);
	std::cout << this->name << " used " << abl.getName() << std::endl;
	if (enemy.didDodge()) {
		gotoxy(20, 51);
		std::cout << enemy.name << " dodged!\n";
		return;

	}
	double atcc = this->ATTACC;
	atcc = (rand() % ((int)this->ATTACC + 1) + this->ATTACC);
	atcc *= abl.getModifier();//getting new dmg value by multiplying by a percent amount
	if (this->didCrit()) {
		gotoxy(20, 51);
		std::cout << "CRIT!!" << std::endl;
		atcc *= 2;
	}
	int finAttacc = (atcc + 0.5);
	enemy.currentHP -= finAttacc;//does damage based on character damage values
	gotoxy(5, 59);
	std::cout << enemy.getName() << " took " << finAttacc << " damage!\n";
	gotoxy(5, 60);
	std::cout << enemy.getName() << " HP: " << enemy.getCurrentHP() << std::endl;


	if (enemy.stress >= 10) {
		std::cout << enemy.getName() << " had a heart attack!\n";
		enemy.heartAttack = true;
		enemy.currentHP = 0;
		std::cout << enemy.getName() << " HP: " << enemy.getCurrentHP() << std::endl;

	}
	if (abl.hasStun()) {//checks if the ability has stun
		int randomStun = rand() % 2;
		//if (randomStun == 0)
		//	enemy.stunned = false;
		//if (randomStun == 1) {
			std::cout << "STUNNED!\n";
			enemy.stunned = true;//returns true if true
		//}
	}

}

void character::heal(ability abl, character & Ally)
{
	srand(time(0));
	gotoxy(5, 55);
	std::cout << this->name << " used " << abl.getName() << std::endl;

	double atcc = this->ATTACC;
	atcc = (rand() % ((int)this->ATTACC + 1) + this->ATTACC);
	atcc *= abl.getModifier();//getting new dmg value by multiplying by a percent amount
	if (this->didCrit()) {
		gotoxy(20, 55);
		std::cout << "CRIT!!" << std::endl;
		atcc *= 2;
	}
	int finAttacc = (atcc + 0.5);
	Ally.currentHP += finAttacc;//does damage based on character damage values
	gotoxy(5, 59);
	std::cout << Ally.name << " was healed " << (int)finAttacc << " health!\n";
	gotoxy(5, 60);
	std::cout << Ally.getName() << " HP: " << Ally.getCurrentHP() << std::endl;
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
void character::setPosition(unsigned short pos)//just a base setter for the gazillion that need to be done
{
	this->position = pos;
}
void character::setStress(dataValue AH)
{
	this->stress = AH;
}
void character::setHeartAttack(bool YN)
{
	this->heartAttack = YN;
}

void character::setSpeed(dataValue s)
{
	this->speed = s;
}

void character::setHealthBar(std::string s)
{
	this->healthBar = s;
}
ability character::getAbility(unsigned int abilitynumber)
{
	switch (abilitynumber) {
	case 1:
		return this->able1;
	case 2:
		return this->able2;
	case 3:
		return this->able3;
	case 4:
		return this->able4;
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

Sprite * character::getActor()
{
	return this->actor;
}



unsigned short character::getPosition()
{
	return this->position;
}
dataValue character::getStress()
{
	return this->stress;
}



DEBUFF character::getHeartAttack()
{
	return this->heartAttack;
}
std::string character::getName()
{
	return this->name;
}

dataValue character::getSpeed()
{
	return this->speed;
}

dataValue character::getATTACC()
{
	return this->ATTACC;
}

dataValue character::getCurrentHP()
{
	return this->currentHP;
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





bool character::isSlowerThan(character & enemy)
{
	if (this->speed == enemy.speed || this->speed < enemy.speed)
		return true;

	else if (this->speed > enemy.speed)
		return false;
}

bool character::isStunned()
{
	return this->stunned;
}

void character::setStun(bool YN)
{
	this->stunned = YN;
}



void character::takeTurn(int userIn, character &Enemy)
{
	this->attack(this->getAbility(userIn), Enemy);//attacking an enemy at index 1,2,3,4
}

void character::takeTurnHeals(int userIn, character & Ally)
{
	this->heal(this->getAbility(userIn), Ally);
}

void character::takeEnemyTurn(character &Hero)
{
	Hero.stress += 3;
	this->attack(this->getAbility(1), Hero);
}

Party::Party()
{

}

Party::Party(character FIRST, character SECOND, character THIRD, character FOURTH, Inventory INVENTORY)
{
	this->first = FIRST;
	this->second = SECOND;
	this->third = THIRD;
	this->fourth = FOURTH;
	this->inventory = INVENTORY;
}

Inventory& Party::getInventory()
{
	return this->inventory;
}
