#pragma once
#include <string>
class ability {
	
public:

	ability(float dmgmodpc,std::string NAME);
	ability() {}
	void setStun(int YN);
	bool hasStun();
	void setHitsMulti(bool YN);
	float getModifier();
	std::string getName() { return this->name; }
private:
	std::string name;
	bool hasEffect;
	bool hitsMultiple;
	bool Stun = false;


	float damageModPercent;//for example +0% damage...
	float abilityAccuracy;//some integer
	//effect to be done
	//self effect to be done
};