#include "Character.h"
#include <iostream>
typedef double dataValue, resistance;
typedef bool passive, DEBUFF, BUFF;

//function used to replace a sprite
void character::die()
{

	//replacing sprite
	this->actor->setPath("bones.txt");


}

//draws the user interface
void character::drawUserInterface()
{
	this->USER_INTERFACE.getSprite().drawme(0, 44);
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

//sets UI
void character::setUI(UserInterface userInterface)
{
	this->USER_INTERFACE = userInterface;
}

//damage calculation
void character::attack(ability abl, character &enemy)
{
	//seeding time
	srand(time(0));
	gotoxy(85, 52);
	std::cout << this->name << " used " << abl.getName() << std::endl;
	if (enemy.didDodge()) {
		gotoxy(85, 53);
		std::cout << enemy.name << " Dodged!\n";
		return;

	}
	double atcc = this->ATTACC;
	atcc = (rand() % ((int)this->ATTACC + 1) + this->ATTACC);
	atcc *= abl.getModifier();//getting new dmg value by multiplying by a percent amount
	if (this->didCrit()) {
		gotoxy(85, 53);
		std::cout << "CRIT!! " << std::endl;
		atcc *= 2;
	}
	int finAttacc = (atcc + 0.5);
	enemy.currentHP -= finAttacc;//does damage based on character damage values
	gotoxy(85, 54);
	std::cout << enemy.getName() << " took " << finAttacc << " damage!\n";
	gotoxy(85, 55);
	std::cout << enemy.getName() << " HP: " << enemy.getCurrentHP() << std::endl;

	if (abl.hasStun()) {//checks if the ability has stun
		//each ability that has stun has a 50/50 chance to stun
		int randomStun = rand() % 2;
		if (randomStun == 0)
			enemy.stunned = false;
		if (randomStun == 1) 
		{
		gotoxy(85, 56);
		std::cout << "STUNNED!\n";
		enemy.stunned = true;//returns true if true
		}
	}

}
//heal function
void character::heal(ability abl, character & Ally)
{

	srand(time(0));
	gotoxy(85, 51);
	std::cout << this->name << " used " << abl.getName() << std::endl;

	double atcc = this->ATTACC;
	atcc = (rand() % ((int)this->ATTACC + 1) + this->ATTACC);//gets the base damage and adds a random amount, up to the base damage number
	atcc *= abl.getModifier();//getting new dmg value by multiplying by a percent amount
	if (this->didCrit()) {//checks if the character crit
		gotoxy(85, 52);
		std::cout << "CRIT!!" << std::endl;
		atcc *= 2;//doubles attack
	}
	int finAttacc = (atcc + 0.5);//adding .5 so that the attack value is rounded appropriatley
	Ally.currentHP += finAttacc;//does damage based on character damage values
	gotoxy(85, 54);
	std::cout << Ally.name << " was healed " << (int)finAttacc << " health!\n";
	gotoxy(85, 55);
	std::cout << Ally.getName() << " HP: " << Ally.getCurrentHP() << std::endl;
}


void character::setAbility(ability abl, unsigned int abilityNumber)//sets an ability
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
//Sets a characters position
void character::setPosition(unsigned short pos)
{
	this->position = pos;
}

void character::setHeartAttack(bool YN)
{
	this->heartAttack = YN;
}

void character::setSpeed(dataValue s)
{
	this->speed = s;
}


//gets ability
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

//gets ability name
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

//setters and getters

void character::setActor(Sprite * s)
{
	this->actor = s;
}

Sprite * character::getActor()
{
	return this->actor;
}

unsigned short character::getPosition()
{
	return this->position;
}

DEBUFF character::getHeartAttack()
{
	return this->heartAttack;
}
std::string character::getName()
{
	return this->name;
}
std::string& character::getNameREFERENCE()
{
	return this->name;
}

void character::makeDead(int YN)
{
	this->isDead = YN;
}

bool character::amDead()
{
	if (this->isDead)
		return true;
	return false;
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

	//Dodge chances in lanes
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

//crit mod
bool character::didCrit()
{
	srand(time(0));
	double critTemp = rand() % 100 + 1;

	//doubler
	double critUPSCALED = this->crit * 100;
	if (critTemp <= critUPSCALED)
		return true;

	return false;
}

//Function for checking if one character is faster than the other
bool character::isSlowerThan(character & enemy)
{
	if (this->speed == enemy.speed || this->speed < enemy.speed)
		return true;

	else if (this->speed > enemy.speed)
		return false;
}

//Checks if the character is stunned
bool character::isStunned()
{
	return this->stunned;
}

//Applies stun to a character
void character::setStun(bool YN)
{
	this->stunned = YN;
}


//Takes the players turn
void character::takeTurn(int userIn, character &Enemy)
{
	this->attack(this->getAbility(userIn), Enemy);//attacking an enemy at index 1,2,3,4
}
//If the ability heals then this allows you to target allies
void character::takeTurnHeals(int userIn, character & Ally)
{
	this->heal(this->getAbility(userIn), Ally);
}
//enemys turn
void character::takeEnemyTurn(character &Hero)
{
	int r = rand() % 2 + 1;
	this->attack(this->getAbility(r), Hero);
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
