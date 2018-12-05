#pragma once
#include <string>
class ability {
	
public:

	//Constructor for abilities
	ability(float dmgmodpc,std::string NAME);
	ability() {}
	//Getters and stters for status effects
	void setStun(int YN);
	bool hasStun();
	void setHitsMulti(bool YN);
	float getModifier();
	std::string getName() { return this->name; }
private:
	
	std::string name;
	//Booleans for the status of status effects
	bool hasEffect;
	bool hitsMultiple;
	bool Stun = false;

	//numbers for accuracy and the damage modification number
	float damageModPercent;//for example +0% damage...
	float abilityAccuracy;//some integer

	//effect to be done
	//self effect to be done
};