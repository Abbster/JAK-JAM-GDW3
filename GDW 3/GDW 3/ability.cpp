#include "ability.h"

ability::ability(float dmgmodpc, std::string NAME)
{
	this->damageModPercent = dmgmodpc;
	this->name = NAME;
}

void ability::setStun(int YN)
{
	this->Stun = YN;
}

bool ability::hasStun()
{
	return this->Stun;
}

void ability::setHitsMulti(bool YN)
{
	if (YN)
		this->hitsMultiple = true;
	else
		this->hitsMultiple = false;

}

float ability::getModifier()
{
	return this->damageModPercent;
}



