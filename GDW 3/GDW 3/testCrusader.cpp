#include "Character.h"
#include <iostream>
#include <vector>

std::vector<character> sort(std::vector<character> &c, int size) {

	//static int *sortedArray = new int[size];//declaring static dynamic array

	double change = 0;//variable to hold the current element

	for (int i = size - 1; i > 0; i--) {//for loop controlling which elements to loop through first, starting from the last

		for (int j = 0; j < i; j++)//loop that checks each element
		{
			if (c[j].getSpeed() < c[j + 1].getSpeed()) {//checks if the current element is greater than the next element
				std::swap(c[j], c[j + 1]);
			}
		}

	}
	std::cout << "Turn Order: ";
	for (int i = 0; i < size; i++)
		std::cout << c[i].getName() << " ";//prints the elements of the array
	std::cout << std::endl;//ends the line after printing the array
	return c;//returning the sorted array

}

int main()
{

	//std::cout << "                    , g" << std::endl << "          gw,,,    ,@@@" << std::endl << "        @@$$@$$@g@" << std::endl << "     ]@@@@$$@@@@P   ]$%[" << std::endl << "     ,,%@@$$Tl@@@wgg@$" << std::endl << "     Bp%$$@$@@$@$@@@@``" << std::endl << "     ]@@@$@@@@@@@@P" << std::endl << "     @@@$$@@@@@@P" << std::endl << "     $$$@$@@@@@@`" << std::endl << "     ```@@B%@&@@" << std::endl << "      ]@@$$$@$@@" << std::endl << "     @@@$@$@@@NC" << std::endl << "    ]@@@$$@@@@@@" << std::endl << "    @@@@@@@@$@@@C" << std::endl << "  ]@$@@@@N@@@$@@@" << std::endl << "  @@@$$@@@@@@%@@@" << std::endl << "g@@@$M$@@@@@M$@@" << std::endl;
	//all of this is test stuff, we haven't actually implemented the proper characters yet
	int userIn = 0;//values for user input
	int userInTwo = 0;
	std::vector<character> Heroes;//vector of heroes
	std::vector<character> Enemies;//vector of enemies


	//CRUSADER
	character Crusader(33, 0.05, 1, 1, 0.03, 6, "Crusader");//creating a new character. see constructor for what these numbers mean

	ability Smite(3, 4, 4, 4, 5, 6, 6, 6, 1, "Smite");
	Crusader.setAbility(Smite, 1);//sets crusader's first ability to smite

	ability StunningBlow(3, 4, 4, 4, 5, 6, 6, 6, 0.50, "Stunning Blow");
	StunningBlow.setStun(1);
	Crusader.setAbility(StunningBlow, 2);

	ability HolyLance(1, 2, 2, 2, 6, 7, 8, 8, 1, "Holy Lance");
	Crusader.setAbility(HolyLance, 3);

	Crusader.setPosition(4);

	//GRAVE ROBBER
	character GraveRobber(20, 0.10, 1, 8, 0.06, 4, "Grave Robber");

	ability PickToTheFace(2, 3, 4, 4, 5, 6, 6, 6, 0.15, "Pick To The Freakin' Face");
	GraveRobber.setAbility(PickToTheFace, 1);

	ability Lunge(1, 2, 2, 2, 5, 6, 7, 7, 1.40, "Lunge");
	GraveRobber.setAbility(Lunge, 2);

	ability ThrownDagger(1, 2, 3, 3, 6, 7, 8, 8, 0.10, "Thrown Dagger");
	GraveRobber.setAbility(ThrownDagger, 3);

	GraveRobber.setPosition(3);

	//HIGHWAYMAN
	character Highwayman(23, .10, 1, 5, 0.05, 5, "Highwayman");

	ability GrapeshotBlast(2, 3, 3, 3, 5, 6, 7, 7, 0.50, "Grapeshot Blast");
	GrapeshotBlast.setHitsMulti(true);
	Highwayman.setAbility(GrapeshotBlast, 1);

	ability PointBlankShot(4, 4, 4, 4, 5, 5, 5, 5, 1.50, "Point Blank Shot");
	Highwayman.setAbility(PointBlankShot, 2);

	ability PistolShot(1, 2, 3, 3, 6, 7, 8, 8, 0.15, "Pistol Shot");
	Highwayman.setAbility(PistolShot, 3);

	Highwayman.setPosition(2);

	//VESTAL
	character Vestal(24, 0, 1, 4, 0.01, 4, "Vestal");
	ability Judgement(1, 2, 2, 2, 1, 2, 3, 4, 0.75, "Judgement");
	Vestal.setAbility(Judgement, 1);
	Vestal.setPosition(1);
	

	character Jelly(24, 0, 1, 4, 0.01, 4, "Jelly");
	ability jello(5, 6, 6, 6, 4, 3, 3, 3, 1, "Jello");
	Jelly.setAbility(jello, 1);//sets crusader's first ability to smite
	Jelly.setPosition(5);
	Enemies.push_back(Jelly);


	Heroes.push_back(Crusader);//pushes crusader onto the list of heroes
	Heroes.push_back(GraveRobber);
	Heroes.push_back(Highwayman);
	Heroes.push_back(Vestal);


	std::vector<character> combatList;
	combatList.push_back(Crusader);
	combatList.push_back(GraveRobber);
	combatList.push_back(Highwayman);
	combatList.push_back(Vestal);
	combatList.push_back(Jelly);


	//int userIn = 0, userInTwo = 0; 
	bool run = true;
	sort(combatList, 5);
	
	//sort(Enemies, 1);
	while (run) {
		std::cout << "START ENCOUNTER!\n";
		for (int i = 0; i < combatList.size(); i++) {
				for (int j = 0; j < Enemies.size(); j++) {
					if (Enemies[j].getCurrentHP() <= 0)
						run = false;
					system("cls");
					sort(combatList, 5);
					if (combatList[i].getName() == "Crusader" || combatList[i].getName() == "Grave Robber"
						|| combatList[i].getName() == "Highwayman" || combatList[i].getName() == "Vestal") {
						
						
						std::cout << "Its " << Heroes[i].getName() << "'s Turn!\n";
						std::cout << "HP: " << Heroes[i].getCurrentHP() << std::endl;

						std::cout << Enemies[j].getName() << " HP: " << Enemies[j].getCurrentHP() << std::endl;
						std::cout << "Select an ability: " << combatList[i].getAbilityName(1) << ", " << combatList[i].getAbilityName(2) << ", " << combatList[i].getAbilityName(3) << "\n";
						std::cin >> userIn;//1 2 3 4
						std::cout << "Select a Target's Position\n";
						std::cin >> userInTwo;// 4 5 6 7 (or 1 2 3 4 if healing...maybe)
						if (combatList[i].getName() == "Vestal" && userIn == 1 || combatList[i].getName() == "Vestal" && userIn == 3)
							combatList[i].takeTurnHeals(userIn, Heroes[userInTwo - 1]);
						else
							combatList[i].takeTurn(userIn, Enemies[userInTwo - 1]);
					}

					else {
						combatList[i].takeEnemyTurn(Heroes[0]);
						//for (int i = 0; i < Heroes.size(); i++) {
						//	combatList[i].takeEnemyTurn(Heroes.back());
						//}
					}
				}
				system("pause");
			
		}
	}
	//bool run = true;
	//for loops for comparing the speed of the heroes to the enemies
	//while (run) {
	//	for (int i = 0; i < Heroes.size(); i++) {
	//		//nested for loop
	//		for (int k = 0; k < Enemies.size(); k++) {
	//
	//			std::cout << Heroes[i].getName() << " HP: " << (int)Heroes[i].getCurrentHP() << std::endl;
	//			std::cout << Enemies[k].getName() << " HP: " << (int)Enemies[k].getCurrentHP() << std::endl;
	//			//std::cout << "test ";
	//			//while no one is dead (i should change this later, maybe do a party HP)
	//			if (!Heroes[i].isSlowerThan(Enemies[k])) {
	//
	//
	//				if (Heroes[i].getCurrentHP() <= 0 || Enemies[k].getCurrentHP() <= 0)
	//					break;
	//
	//				//gets the character's abilities and prints them out. exception thrown here
	//				std::cout << "Select an ability: " << Heroes[i].getAbilityName(1) << ", " << Heroes[i].getAbilityName(2) << ", " << Heroes[i].getAbilityName(3) << "\n";
	//				std::cin >> userIn;//1 2 3 4
	//				std::cout << "Select a Target's Position\n";
	//				std::cin >> userInTwo;// 4 5 6 7 (or 1 2 3 4 if healing...maybe)
	//
	//				if (Heroes[i].getCurrentHP() <= 0 || Enemies[k].getCurrentHP() <= 0)
	//					run = false;
	//				Heroes[i].attack(Heroes[i].getAbility(userIn), Enemies.at(userInTwo - 1));//attacking an enemy at index 1,2,3,4
	//				continue;
	//			}
	//			//if (!Heroes[i].isSlowerThan(Enemies[k]))
	//			//{
	//				//if (Enemies[k].isStunned())
	//				//	continue;
	//			if (Heroes[i].getCurrentHP() <= 0 || Enemies[k].getCurrentHP() <= 0)
	//				run = false;
	//
	//			Enemies[k].attack(Enemies[k].getAbility(1), Heroes[i]);
	//			//}
	//				//if the hero is faster than the enemy
	//				//if (!Heroes[i].isSlowerThan(Enemies[k])) {
	//
	//				//playerTurn://label
	//
	//				//gets the name of the current hero and their current hp and prints it out. Neat!
	//					//goto enemyTurn;
	//
	//				//if (Heroes[i].isSlowerThan(Enemies[k])) {
	//				//enemyTurn:
	//
	//					//goto playerTurn;
	//				//}
	//				//}
	//				//if the hero is slower than the enemy
	//		}
	//	}
	//}

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

