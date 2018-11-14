#pragma once
#include <string>
class ability {
	
public:

	ability(bool rngd, unsigned short pos, unsigned short targrang, float dmgmodpc,std::string NAME);
	ability() {}
	bool hasStun();
	bool giveEffect(std::string eff);
	float getModifier();
	std::string getName() { return this->name; }
private:
	std::string name;
	bool hasEffect;
	bool Stun;
	bool Ranged;
	unsigned short position;//can be 1,2,3,4
	unsigned short targetRange;//can be 1,2,3,4
	float damageModPercent;//for example +0% damage...
	float abilityAccuracy;//some integer
	//effect to be done
	//self effect to be done
};