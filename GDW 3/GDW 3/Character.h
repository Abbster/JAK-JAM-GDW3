#pragma once
#include <string>
	template <class type>
class character {

public:
	
	//test functions with templates for literally anything
	void setGeneric(type thisvalue, type newval);
	type getGeneric(type thisvalue);

	

	class ablity {
	private:
		typedef unsigned short rank, target;//can be 1,2,3,4
		float damageMod, critMod;
		int accuracy;
		typedef std::string range;//can be "melee" or "ranged"
	};


	//data members
private:
	typedef float dataValue,resistance;
	typedef bool passive, debuff,buff,abilities;
	dataValue
		maxHP,
		dodge,
		speed,
		crit,
		damage;
	resistance
		stun,
		poison,
		bleed,
		debuff,
		move,
		disease,
		trap;
	passive
		corpseClear,
		preventAmbush,
		religious;
	debuff
		bleed,
		blight,
		stun,
		debuff,
		mark,
		move,
		horror,
		heartAttack,
		deathsDoor,
		deathsDoorRecovery;
	buff
		Buff,
		guard,
		riposte,
		restoration,
		aegis;
	

		


};


