#include "ability.h"

//constructor
ability::ability(float dmgmodpc, std::string NAME)
{
	this->damageModPercent = dmgmodpc;
	this->name = NAME;
}

//set stun for an ability
void ability::setStun(int YN)
{
	this->Stun = YN;
}

bool ability::hasStun()
{
	return this->Stun;
}

//gets modifier
float ability::getModifier()
{
	return this->damageModPercent;
}



