#include "ability.h"

ability::ability(unsigned short pos1, unsigned short pos2, unsigned short pos3, unsigned short pos4, unsigned short targetrange1, unsigned short targetrange2, unsigned short targetrange3, unsigned short targetrange4, float dmgmodpc, std::string NAME)
{
	this->position1 = pos1;
	this->position2 = pos2;
	this->position3 = pos3;
	this->position4 = pos4;
	this->targetRange1 = targetrange1;
	this->targetRange2 = targetrange2;
	this->targetRange3 = targetrange3;
	this->targetRange4 = targetrange4;
	this->damageModPercent = dmgmodpc;
	this->name = NAME;
}

void ability::setStun(bool YN)
{
	if (YN == true)
		this->Stun = true;
	else
		this->Stun = false;
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



