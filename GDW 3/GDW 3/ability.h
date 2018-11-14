#pragma once
#include "Character.h"
class ability {
	//each ability has an animation...? maybe
	//maybe the following:
public:


	ability(bool rngd, unsigned short pos, unsigned short targrang, float dmgmodpc, float abilityacc);
	ability() {}
	character setTarget(character c) { return c; }
private:
	bool Ranged;
	unsigned short position;//can be 1,2,3,4
	unsigned short targetRange;//can be 1,2,3,4
	float damageModPercent;//for example +0% damage...
	float abilityAccuracy;//some integer
	//effect to be done
	//self effect to be done
};