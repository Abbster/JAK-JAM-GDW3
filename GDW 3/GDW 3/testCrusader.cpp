#include "Character.h"
#include <iostream>
#include <vector>



int main()
{
	int userIn = 0;
	int userInTwo = 0;
	std::vector<character> Heroes;
	std::vector<character> Enemies;
	
	character Crusader(33, 0, 0, 10, 0, 6, "Crusader");
	character Jellyton(14, 0, 0, 12, 0, 7, "One Jelly Boi");
	ability Smite(false, 1, 2, 1, "Smite");
	ability JellyAttacc(false, 1, 2, 1, "Jelly Attacc");
	Crusader.setAbility(Smite, 1);
	Jellyton.setAbility(JellyAttacc, 1);
	Heroes.push_back(Crusader);
	Enemies.push_back(Jellyton);
	
	for (int i = 0; i < Heroes.size(); i++) {
		for (int k = 0; k < Enemies.size(); k++) {

			std::cout << Heroes[i].getName() << " HP: " << Heroes[i].getCurrentHP() << std::endl;
			std::cout << Enemies[i].getName() << " HP: " << Enemies[i].getCurrentHP() << std::endl;


			while (Heroes[i].getCurrentHP() > 0 || Enemies[k].getCurrentHP() > 0) {
				if (!Heroes[i].isSlowerThan(Enemies[k])) {
					playerTurn:
					std::cout << "Select an ability: " << Heroes[i].getAbilityName(1) << " " << Heroes[i].getAbilityName(2) << " " << Heroes[i].getAbilityName(3) << " " << Heroes[i].getAbilityName(4) << std::endl;
					std::cin >> userIn;//1 2 3 4
					Heroes[i].selectAbility(userIn);
					std::cout << "Select a Target's Position\n";
					std::cin >> userInTwo;

					Heroes[i].attack(Heroes[i].selectAbility(userIn), Enemies.at(userInTwo));//attacking
					goto enemyTurn;

				}if (Heroes[i].isSlowerThan(Enemies[k])) {
					enemyTurn:
					Enemies[k].attack(Enemies[k].getAbility(1), Heroes[i]);
					goto playerTurn;
				}

			}
		}
	}
	system("pause");





	//std::cout << "                    , g" << std::endl << "          gw,,,    ,@@@" << std::endl << "        @@$$@$$@g@" << std::endl << "     ]@@@@$$@@@@P   ]$%[" << std::endl << "     ,,%@@$$Tl@@@wgg@$" << std::endl << "     Bp%$$@$@@$@$@@@@``" << std::endl << "     ]@@@$@@@@@@@@P" << std::endl << "     @@@$$@@@@@@P" << std::endl << "     $$$@$@@@@@@`" << std::endl << "     ```@@B%@&@@" << std::endl << "      ]@@$$$@$@@" << std::endl << "     @@@$@$@@@NC" << std::endl << "    ]@@@$$@@@@@@" << std::endl << "    @@@@@@@@$@@@C" << std::endl << "  ]@$@@@@N@@@$@@@" << std::endl << "  @@@$$@@@@@@%@@@" << std::endl << "g@@@$M$@@@@@M$@@" << std::endl;
	//
	//system("pause");
	//character Crusader(33, 0.05, 0, 0, .03, 6, "Crusader");
	//Crusader.setPosition(1);
	//character Enemy(20, .15, 0, 0, 0, 5, "Evil Dog");
	//Enemy.setPosition(1);
	//ability Smite(false, 1, 1, 1, "Smite");
	//ability Claw(false, 1, 1, 1, "Claw");
	//Crusader.setAbility(Smite, 1);
	//Enemy.setAbility(Claw, 1);
	//
	//while (true) {
	//	system("cls");
	//	std::cout << Enemy.getName() << ": " << Enemy.getCurrentHP() << std::endl;//prints out name and hp
	//	system("pause");
	//
	//	Crusader.attack(Smite, Enemy);//attacks enemy with smite
	//	if (Enemy.getCurrentHP() <= 0)
	//		break;
	//	std::cout << Enemy.getName() << " is at " << Enemy.getCurrentHP() << " HP!" << std::endl;//print out new hp
	//	std::cout << Crusader.getName() << ": " << Crusader.getCurrentHP() << std::endl;
	//	system("pause");
	//	Enemy.attack(Claw, Crusader);
	//	if (Crusader.getCurrentHP() <= 0)
	//		break;
	//	std::cout << Crusader.getName() << " is at " << Crusader.getCurrentHP() << " HP!" << std::endl;
	//	system("pause");
	//	//Smite.giveEffect("Stun"); //some test shit
	//}

	return 0;
}

