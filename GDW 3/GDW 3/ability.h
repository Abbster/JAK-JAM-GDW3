#pragma once
#include <string>
class ability {
	
public:

	ability(unsigned short pos1,unsigned short pos2,unsigned short pos3,unsigned short pos4, 
		unsigned short targetrange1, unsigned short targetrange2, unsigned short targetrange3, unsigned short targetrange4,float dmgmodpc,std::string NAME);
	ability() {}
	void setStun(bool YN);
	bool getStun() { return this->Stun; }
	void setHitsMulti(bool YN);
	float getModifier();
	std::string getName() { return this->name; }
private:
	std::string name;
	bool hasEffect;
	bool hitsMultiple;
	bool Stun;
	unsigned short position1;//can be 1,2,3,4 - closest position at which an ability can be used. for example, for smite, its 1
	unsigned short position2;//second closest
	unsigned short position3;//third closest
	unsigned short position4;//furthest position away
	unsigned short targetRange1;//can be 5,6,7,8 - closest position at which an enemy can still be hit by an ability, for smite its 1
	unsigned short targetRange2;
	unsigned short targetRange3;
	unsigned short targetRange4;

	float damageModPercent;//for example +0% damage...
	float abilityAccuracy;//some integer
	//effect to be done
	//self effect to be done
};