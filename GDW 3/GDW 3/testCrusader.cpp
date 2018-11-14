#include "Character.h"
#include <iostream>
int main()
{

	character Crusader(33,5,0,1,0,3,6,12);
	ability Smite(false,1,1,0.0,100);
	Crusader.setAbility(Smite, 0);
	srand(time(0));
	std::cout << (rand() % 7 + 6);
	system("pause");

return 0;
}
