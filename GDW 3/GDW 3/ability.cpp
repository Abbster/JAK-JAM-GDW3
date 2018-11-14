#include "ability.h"

ability::ability(bool rngd, unsigned short pos, unsigned short targrang, float dmgmodpc,std::string NAME)//ability constructor
{
	this->Ranged = rngd; this->position = pos; this->targetRange = targrang; this->damageModPercent = dmgmodpc; this->name = NAME;//constructing the ability

}

bool ability::hasStun()
{
	if (this->Stun)
		return true;
	else
		return false;

}

bool ability::giveEffect(std::string eff)
{
		if (eff == "Stun"){
			this->Stun = true;
		this->hasEffect = true;
		}
		return true;

	
}

float ability::getModifier()
{
	return this->damageModPercent;
}



