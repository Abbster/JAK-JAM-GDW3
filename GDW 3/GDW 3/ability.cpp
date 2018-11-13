#include "ability.h"

ability::ability(bool rngd, unsigned short pos, unsigned short targrang, float dmgmodpc, float abilityacc)//ability constructor
{
	this->Ranged = rngd; this->position = pos; this->targetRange = targrang; this->damageModPercent = dmgmodpc; this->abilityAccuracy = abilityacc;//constructing the ability

}
