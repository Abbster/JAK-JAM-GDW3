#include "Character.h"
#include <iostream>
#include <vector>



int main()
{
	
	std::cout << "                    , g" << std::endl << "          gw,,,    ,@@@" << std::endl << "        @@$$@$$@g@" << std::endl << "     ]@@@@$$@@@@P   ]$%[" << std::endl << "     ,,%@@$$Tl@@@wgg@$" << std::endl << "     Bp%$$@$@@$@$@@@@``" << std::endl << "     ]@@@$@@@@@@@@P" << std::endl << "     @@@$$@@@@@@P" << std::endl << "     $$$@$@@@@@@`" << std::endl << "     ```@@B%@&@@" << std::endl << "      ]@@$$$@$@@" << std::endl << "     @@@$@$@@@NC" << std::endl << "    ]@@@$$@@@@@@" << std::endl << "    @@@@@@@@$@@@C" << std::endl << "  ]@$@@@@N@@@$@@@" << std::endl << "  @@@$$@@@@@@%@@@" << std::endl << "g@@@$M$@@@@@M$@@" << std::endl;
	//all of this is test stuff, we haven't actually implemented the proper characters yet
	int userIn = 0;//values for user input
	int userInTwo = 0;
	std::vector<character> Heroes;//vector of heroes
	std::vector<character> Enemies;//vector of enemies

	character Crusader(33, 0, 0, 10, 0, 6, "Crusader");//creating a new character. see constructor for what these numbers mean
	character Jellyton(14, 0, 0, 12, 0, 7, "One Jelly Boi");
	ability Smite(false, 1, 2, 1, "Smite");//creating ability. again, see constructor
	ability ZelousAccusation(true, 1, 2, 1, "Zelous Accusation");//creating ability. again, see constructor
	ability JellyAttacc(false, 1, 2, 1, "Jelly Attacc");
	Crusader.setAbility(Smite, 1);//sets crusader's first ability to smite
	Crusader.setAbility(ZelousAccusation, 2);
	Jellyton.setAbility(JellyAttacc, 1);
	Crusader.setPosition(1);
	Jellyton.setPosition(1);
	Heroes.push_back(Crusader);//pushes crusader onto the list of heroes
	Enemies.push_back(Jellyton);

	//for loops for comparing the speed of the heroes to the enemies
	for (int i = 0; i < Heroes.size(); i++) {
		//nested for loop
		for (int k = 0; k < Enemies.size(); k++) {


			//while no one is dead (i should change this later, maybe do a party HP
			while (true) {


				//if the hero is faster than the enemy
				if (!Heroes[i].isSlowerThan(Enemies[k])) {

				playerTurn://label

				//gets the name of the current hero and their current hp and prints it out. Neat!
					std::cout << Heroes[i].getName() << " HP: " << Heroes[i].getCurrentHP() << std::endl;
					std::cout << Enemies[k].getName() << " HP: " << Enemies[k].getCurrentHP() << std::endl;


					if (Heroes[i].getCurrentHP() <= 0 || Enemies[k].getCurrentHP() <= 0)
						break;

					//gets the character's abilities and prints them out. exception thrown here
					std::cout << "Select an ability: " << Heroes[i].getAbilityName(1) << ", " << Heroes[i].getAbilityName(2) << "\n"; //<< Heroes[i].getAbilityName(2) << " " << Heroes[i].getAbilityName(3) << " " << Heroes[i].getAbilityName(4) << std::endl;
					std::cin >> userIn;//1 2 3 4
					std::cout << "Select a Target's Position\n";
					std::cin >> userInTwo;// 1 2 3 4

					Heroes[i].attack(Heroes[i].getAbility(userIn), Enemies.at(userInTwo - 1));//attacking an enemy at index 1,2,3,4
					goto enemyTurn;

				}
				//if the hero is slower than the enemy
				if (Heroes[i].isSlowerThan(Enemies[k])) {
				enemyTurn:
					if (Heroes[i].getCurrentHP() <= 0 || Enemies[k].getCurrentHP() <= 0)
						break;
					Enemies[k].attack(Enemies[k].getAbility(1), Heroes[i]);

					goto playerTurn;
				}

			}
		}
	}
	system("pause");


	//learn open gl 


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

