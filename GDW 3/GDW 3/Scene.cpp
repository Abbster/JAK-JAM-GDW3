#include "Scene.h"
Scene::Scene(Sprite * BG, Sprite * UI)
{
	this->background = BG;
	this->UI = UI;
}
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}


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
	gotoxy(5, 49);
	std::cout << "Turn Order: ";
	for (int i = 0; i < size; i++)
		std::cout << c[i].getName() << " ";//prints the elements of the array
	std::cout << std::endl;//ends the line after printing the array
	return c;//returning the sorted array

}
std::vector<character> sortNoText(std::vector<character> &c, int size) {

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

	return c;//returning the sorted array

}
std::vector<character> sortPosition(std::vector<character> &c, int size) {

	//static int *sortedArray = new int[size];//declaring static dynamic array

	double change = 0;//variable to hold the current element

	for (int i = size - 1; i > 0; i--) {//for loop controlling which elements to loop through first, starting from the last

		for (int j = 0; j < i; j++)//loop that checks each element
		{
			if (c[j].getPosition() > c[j + 1].getPosition()) {//checks if the current element is greater than the next element
				std::swap(c[j], c[j + 1]);
			}
		}

	}
	gotoxy(5, 50);
	std::cout << "Position: ";
	for (int i = 0; i < size; i++)
		std::cout << c[i].getName() << " ";//prints the elements of the array
	std::cout << std::endl;//ends the line after printing the array
	return c;//returning the sorted array

}
void Scene::play()
{
	//std::cout << "                    , g" << std::endl << "          gw,,,    ,@@@" << std::endl << "        @@$$@$$@g@" << std::endl << "     ]@@@@$$@@@@P   ]$%[" << std::endl << "     ,,%@@$$Tl@@@wgg@$" << std::endl << "     Bp%$$@$@@$@$@@@@``" << std::endl << "     ]@@@$@@@@@@@@P" << std::endl << "     @@@$$@@@@@@P" << std::endl << "     $$$@$@@@@@@`" << std::endl << "     ```@@B%@&@@" << std::endl << "      ]@@$$$@$@@" << std::endl << "     @@@$@$@@@NC" << std::endl << "    ]@@@$$@@@@@@" << std::endl << "    @@@@@@@@$@@@C" << std::endl << "  ]@$@@@@N@@@$@@@" << std::endl << "  @@@$$@@@@@@%@@@" << std::endl << "g@@@$M$@@@@@M$@@" << std::endl;
	//all of this is test stuff, we haven't actually implemented the proper characters yet
	int userIn = 0;//values for user input
	int userInTwo = 0;
	static std::vector<character> Enemies;//vector of enemies
	static std::vector<character> Heroes;//vector of heroes

	//switch to pointers

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
	ability DivineGrace(1, 2, 2, 2, 1, 2, 3, 4, 0.75, "Divine Grace");
	Vestal.setAbility(DivineGrace, 1);
	ability Dazzle(1, 2, 2, 2, 1, 2, 3, 4, 0.75, "Dazzling Light");
	Vestal.setAbility(Dazzle, 2);
	ability DivineComfort(1, 2, 2, 2, 1, 2, 3, 4, 0.75, "Divine Comfort");
	Vestal.setAbility(DivineComfort, 3);

	Vestal.setPosition(1);


	character Jelly(502, 0, 1, 4, 0.01, 4, "Jelly");
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


	this->background->drawme();
	system("pause");
	system("CLS");

	//int userIn = 0, userInTwo = 0; 
	bool run = true;

	sort(combatList, 5);
	//sort(Enemies, 1);
	while (run) {
		gotoxy(2, 2);
		std::cout << "START ENCOUNTER!\n";
		for (int i = 0; i < combatList.size(); i++) {
			for (int j = 0; j < Enemies.size(); j++) {
				for (int k = 0; k < Heroes.size(); k++) {
					system("cls");
					this->UI->drawme();
					//if (Enemies[j].getCurrentHP() <= 0)
					//	run = false;

					sort(combatList, combatList.size());
					sortNoText(Heroes, Heroes.size());
					if (combatList[i].getName() == "Crusader" || combatList[i].getName() == "Grave Robber"
						|| combatList[i].getName() == "Highwayman" || combatList[i].getName() == "Vestal") {


						gotoxy(5, 51);
						std::cout << "Its " << combatList[i].getName() << "'s Turn!\n";
						//std::cout << "HP: " << combatList[i].getCurrentHP() << std::endl;

						gotoxy(5, 52);
						std::cout << Heroes[k].getName() << " HP: " << Heroes[k].getCurrentHP() << std::endl;
						gotoxy(5, 53);
						std::cout << "Select an ability: " << combatList[i].getAbilityName(1) << ", " << combatList[i].getAbilityName(2) << ", " << combatList[i].getAbilityName(3) << "\n";
						gotoxy(5, 54);
						std::cin >> userIn;//1 2 3 4

						gotoxy(100, 49);
						std::cout << "Select a Target's Position\n";
						gotoxy(100, 50);
						std::cin >> userInTwo;// 4 5 6 7 (or 1 2 3 4 if healing...maybe)
						sortPosition(Heroes, Heroes.size());//make another sort function with positions
						if (combatList[i].getName() == "Vestal" && userIn == 1 || combatList[i].getName() == "Vestal" && userIn == 3)
							combatList[i].takeTurnHeals(userIn, Heroes[userInTwo - 1]);
						else
							combatList[i].takeTurn(userIn, Enemies[userInTwo - 1]);

						if (Enemies[j].getCurrentHP() <= 0)
						{
							run = false;
							break;
						}
						break;
					}
					else {
						int randomSelect = rand() % 4;
						gotoxy(5, 49);
						if (!Enemies[j].isStunned())
							combatList[i].takeEnemyTurn(Heroes[randomSelect]);
						else {
							std::cout << combatList[i].getName() << " was stunned and can't act!\n";
							Enemies[j].setStun(false);
						}
						if (Heroes[k].getHeartAttack()) {
							gotoxy(5, 49);
							std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
							combatList.erase(combatList.begin() + i);
							Heroes.erase(Heroes.begin() + k);
							i--;
							k--;

						}
						break;
					}
				}
			}

			gotoxy(200, 61);
			system("pause");
			if (!run)
				break;

		}
	}
}
