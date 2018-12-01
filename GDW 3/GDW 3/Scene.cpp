#include "Scene.h"
#include "Input.h"
#include "Events.h"

Sprite *CRUSADER_SPRITE = new Sprite("crusader.txt");
Sprite *GRAVEROBBER_SPRITE = new Sprite("graveRobber.txt");
Sprite *HIGHWAYMAN_SPRITE = new Sprite("highwayman.txt");
Sprite *VESTAL_SPRITE = new Sprite("vestal.txt");

Sprite *SKELETON1_SPRITE = new Sprite("skeleton.txt");
Sprite *SKELETON2_SPRITE = new Sprite("skeleton2.txt");
Sprite *BRAWLER_SPRITE = new Sprite("brawler.txt");
Sprite *DEFENDER_SPRITE = new Sprite("defender.txt");
Sprite *LIGHT10 = new Sprite("Light10.txt");
Sprite *TORCH_SPRITE = new Sprite("Light10.txt");

Inventory AdventurersPack;
Item *torch = new Item("Torch", TORCH_SPRITE);

void Scene::killCharacter(character &c)
{
	//remove from combat list
		//c.die();
	c.getActor()->setPath("bones.txt");

}
void Sprite::checkTorchSprite(int lightlevel)
{
	switch (lightlevel) {

	case 10:
		this->setPath("Light10.txt");
		break;
	case 9:

		break;



	}
}
Scene::~Scene()
{
	//delete this;
	//delete CRUSADER_SPRITE;
	//delete GRAVEROBBER_SPRITE;
	//delete HIGHWAYMAN_SPRITE;
	//delete VESTAL_SPRITE;
	//delete SKELETON1_SPRITE;
	//delete SKELETON2_SPRITE;
	//delete TORCH_SPRITE;
	//delete torch;


}
Scene::Scene(Sprite * BG, Sprite * UI)
{
	this->background = BG;
	this->UI = UI;
	Sprite *topTorch = new Sprite("Light10.txt");

}
void Scene::initializeTheCrazyPeople()
{
	//userInterface list
	UserInterface CrusaderUI("crusaderui.txt");
	UserInterface GraveRobberUI("graveRobberui.txt");
	UserInterface HighwaymanUI("highwaymanui.txt");
	UserInterface VestalUI("vestalui.txt");

	//switch to pointers

	//CRUSADER 33
	this->Crusader = character(133, 0.05, 1, 1, 0.03, 6, "Crusader", CRUSADER_SPRITE);//creating a new character. see constructor for what these numbers mean

	Crusader.setUI(CrusaderUI);
	ability Smite(3, 4, 4, 4, 5, 6, 6, 6, 1, "Smite");
	Crusader.setAbility(Smite, 1);//sets crusader's first ability to smite

	ability StunningBlow(3, 4, 4, 4, 5, 6, 6, 6, 0.50, "Stunning Blow");
	StunningBlow.setStun(1);
	Crusader.setAbility(StunningBlow, 2);

	ability HolyLance(1, 2, 2, 2, 6, 7, 8, 8, 1, "Holy Lance");
	Crusader.setAbility(HolyLance, 3);

	Crusader.setPosition(4);

	//GRAVE ROBBER 20
	this->GraveRobber = character(3331, 0.10, 1, 8, 0.06, 4, "Grave Robber", GRAVEROBBER_SPRITE);

	GraveRobber.setUI(GraveRobberUI);
	ability PickToTheFace(2, 3, 4, 4, 5, 6, 6, 6, 0.15, "Pick To The Freakin' Face");
	GraveRobber.setAbility(PickToTheFace, 1);

	ability Lunge(1, 2, 2, 2, 5, 6, 7, 7, 1.40, "Lunge");
	GraveRobber.setAbility(Lunge, 2);

	ability ThrownDagger(1, 2, 3, 3, 6, 7, 8, 8, 0.10, "Thrown Dagger");
	GraveRobber.setAbility(ThrownDagger, 3);

	GraveRobber.setPosition(3);

	//HIGHWAYMAN 23
	Highwayman = character(3333, .10, 1, 5, 0.05, 5, "Highwayman", HIGHWAYMAN_SPRITE);

	Highwayman.setUI(HighwaymanUI);
	ability GrapeshotBlast(2, 3, 3, 3, 5, 6, 7, 7, 0.50, "Grapeshot Blast");
	GrapeshotBlast.setHitsMulti(true);
	Highwayman.setAbility(GrapeshotBlast, 1);

	ability PointBlankShot(4, 4, 4, 4, 5, 5, 5, 5, 1.50, "Point Blank Shot");
	Highwayman.setAbility(PointBlankShot, 2);

	ability PistolShot(1, 2, 3, 3, 6, 7, 8, 8, 0.15, "Pistol Shot");
	Highwayman.setAbility(PistolShot, 3);

	Highwayman.setPosition(2);

	//VESTAL 24
	Vestal = character(3331, 0, 1, 4, 0.01, 4, "Vestal", VESTAL_SPRITE);

	Vestal.setUI(VestalUI);
	ability DivineGrace(1, 2, 2, 2, 1, 2, 3, 4, 0.75, "Divine Grace");
	Vestal.setAbility(DivineGrace, 1);
	ability Dazzle(1, 2, 2, 2, 1, 2, 3, 4, 0.75, "Dazzling Light");
	Vestal.setAbility(Dazzle, 2);
	ability DivineComfort(1, 2, 2, 2, 1, 2, 3, 4, 0.75, "Divine Comfort");
	Vestal.setAbility(DivineComfort, 3);

	Vestal.setPosition(1);

	int randomEnemySelect1 = rand() % 4;
	int randomEnemySelect2 = rand() % 4;
	int randomEnemySelect3 = rand() % 4;
	int randomEnemySelect4 = rand() % 4;
	std::vector<character> potentialEnemies;
	//all of these have 30 ish hp..which we will change after anyways
	Jelly = character(1, 0, 1, 10, 0.01, 4, "StickBoi", SKELETON1_SPRITE);
	Squatyman = character(1, 0, 1, 1, 0.01, 4, "Squattyboi", SKELETON2_SPRITE);
	Jelly3 = character(1, 0, 1, 30, 0.01, 4, "StickBoi2", BRAWLER_SPRITE);
	Squatyman2 = character(1, 0, 1, 7, 0.01, 4, "Skelebro", DEFENDER_SPRITE);
	ability jello(5, 6, 6, 6, 4, 3, 3, 3, 1, "Heck");
	Jelly.setAbility(jello, 1);//sets crusader's first ability to smite
	Squatyman.setAbility(jello, 1);
	Jelly3.setAbility(jello, 1);
	Squatyman2.setAbility(jello, 1);
	potentialEnemies.push_back(Jelly);
	potentialEnemies.push_back(Squatyman);
	potentialEnemies.push_back(Jelly3);
	potentialEnemies.push_back(Squatyman2);
	Enemies.push_back(potentialEnemies[randomEnemySelect1]);
	Enemies.push_back(potentialEnemies[randomEnemySelect2]);
	Enemies.push_back(potentialEnemies[randomEnemySelect3]);
	Enemies.push_back(potentialEnemies[randomEnemySelect4]);



	Heroes.push_back(Crusader);//pushes crusader onto the list of heroes
	Heroes.push_back(GraveRobber);
	Heroes.push_back(Highwayman);
	Heroes.push_back(Vestal);



	combatList.push_back(Crusader);
	combatList.push_back(GraveRobber);
	combatList.push_back(Highwayman);
	combatList.push_back(Vestal);
	combatList.push_back(Enemies[0]);
	combatList.push_back(Enemies[1]);
	combatList.push_back(Enemies[2]);

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
	gotoxy(5, 43);
	std::cout << "Turn Order: ";
	for (int i = 0; i < size; i++)
		std::cout << c[i].getName() << " ";//prints the elements of the array
	std::cout << std::endl;//ends the line after printing the array
	return c;//returning the sorted array

}
std::vector<character> checkForSameName(std::vector<character> &c, int size) {

	//static int *sortedArray = new int[size];//declaring static dynamic array

	double change = 0;//variable to hold the current element

	for (int i = size - 1; i > 0; i--) {//for loop controlling which elements to loop through first, starting from the last

		for (int j = 0; j < i; j++)//loop that checks each element
		{
			if (c[j].getName() == c[j + 1].getName()) {//checks if the current element is greater than the next element
				//std::swap(c[j], c[j + 1]);
				c[j + 1].getNameREFERENCE().append("de",2);
			}
		}

	}
	
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
	gotoxy(80, 43);
	std::cout << "Position: ";
	for (int i = 0; i < size; i++)
		std::cout << c[i].getName() << " ";//prints the elements of the array
	std::cout << std::endl;//ends the line after printing the array
	return c;//returning the sorted array

}
std::vector<character> sortPositionNoText(std::vector<character> &c, int size) {

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
	return c;//returning the sorted array

}
void Scene::play()
{
	//std::cout << "                    , g" << std::endl << "          gw,,,    ,@@@" << std::endl << "        @@$$@$$@g@" << std::endl << "     ]@@@@$$@@@@P   ]$%[" << std::endl << "     ,,%@@$$Tl@@@wgg@$" << std::endl << "     Bp%$$@$@@$@$@@@@``" << std::endl << "     ]@@@$@@@@@@@@P" << std::endl << "     @@@$$@@@@@@P" << std::endl << "     $$$@$@@@@@@`" << std::endl << "     ```@@B%@&@@" << std::endl << "      ]@@$$$@$@@" << std::endl << "     @@@$@$@@@NC" << std::endl << "    ]@@@$$@@@@@@" << std::endl << "    @@@@@@@@$@@@C" << std::endl << "  ]@$@@@@N@@@$@@@" << std::endl << "  @@@$$@@@@@@%@@@" << std::endl << "g@@@$M$@@@@@M$@@" << std::endl;
	//all of this is test stuff, we haven't actually implemented the proper characters yet

	srand(time(0));
	int userIn = 0;//values for user input
	int userInTwo = 0;



	this->background->drawme();
	//while (true)
	//{
	//POINT cursorPos;
	//GetCursorPos(&cursorPos);
	//ScreenToClient(GetConsoleWindow(), &cursorPos);
	//short mx = 0, my = 0;
	//	mx = cursorPos.x;
	//	my = cursorPos.y;
	//	if (isEvent(Events::Mouse_Left) && mx >= 626 && mx <= 1221 && my >= 631 && my <= 772)
	//		break;
	//}
	initializeTheCrazyPeople();
	system("pause");
	system("CLS");

	//int userIn = 0, userInTwo = 0; 
	bool run = true;

	Party Adventurers(Crusader, GraveRobber, Highwayman, Vestal, AdventurersPack);
	sort(combatList, combatList.size());
	Adventurers.getInventory().addItem(torch);
	//sort(Enemies, 1);
	while (run) {
		for (int i = 0; i < combatList.size(); i++) {
			for (int j = 0; j < Enemies.size(); j++) {
				for (int k = 0; k < Heroes.size(); k++) {
				turn:
					system("cls");

					//this->UI->drawme(0, 0);
					//checkTorchSprite(this->topTorch);
					//this->topTorch->drawme(42, 2);

					//gotoxy(5, 24);
					checkForSameName(Enemies,Enemies.size());
					

					Vestal.getActor()->drawme(5, 22);
					Highwayman.getActor()->drawme(27, 22);
					GraveRobber.getActor()->drawme(49, 22);
					Crusader.getActor()->drawme(70, 24);//subject to change

					Enemies[0].getActor()->drawme(120, 22);
					Enemies[1].getActor()->drawme(145, 22); //subject to change
					Enemies[2].getActor()->drawme(170, 22); //subject to change

					//Vestal.getActor()->drawme(5, 29);

					//if (Enemies[j].getCurrentHP() <= 0)
					//	run = false;

					sort(combatList, combatList.size());
					sortNoText(Heroes, Heroes.size());
					if (combatList[i].getName() == "Crusader" || combatList[i].getName() == "Grave Robber"
						|| combatList[i].getName() == "Highwayman" || combatList[i].getName() == "Vestal") {


						combatList[i].drawUserInterface();
						
						gotoxy(5, 46);
						std::cout << "Its " << combatList[i].getName() << "'s Turn!\n";
						//std::cout << "HP: " << combatList[i].getCurrentHP() << std::endl;

						gotoxy(33, 46);
						std::cout << Heroes[k].getName() << " HP: " << Heroes[k].getCurrentHP() << std::endl;
						//gotoxy(5, 53);
						//std::cout << "Select an ability (1,2,3,4): " << combatList[i].getAbilityName(1) << ", " << combatList[i].getAbilityName(2) << ", " << combatList[i].getAbilityName(3) << ", Use Torch\n";
						gotoxy(85, 51);
						std::cin >> userIn;//1 2 3 4

						if (userIn == 4) {
							if (!Adventurers.getInventory().getItems().empty()) {
								Adventurers.getInventory().getItems().pop_back();
								//gotoxy somewhere
								gotoxy(200, 59);
								std::cout << "used a torch!\n";
							}
							else {
								gotoxy(200, 59);
								std::cout << "No torches!\n";
							}goto turn;
						}

						//gotoxy(100, 49);
						//std::cout << "Select a Target's Position\n";
						gotoxy(140, 51);
						std::cin >> userInTwo;// 4 5 6 7 (or 1 2 3 4 if healing...maybe)
						sortPosition(Heroes, Heroes.size());//make another sort function with positions
						if (combatList[i].getName() == "Vestal" && userIn == 1 || combatList[i].getName() == "Vestal" && userIn == 3)
							combatList[i].takeTurnHeals(userIn, Heroes[userInTwo - 1]);
						else
							combatList[i].takeTurn(userIn, Enemies[userInTwo - 1]);

						if (Enemies[userInTwo - 1].getCurrentHP() <= 0) {

							killCharacter(Enemies[userInTwo - 1]);
							for (int q = 0; q < combatList.size(); q++) {
								if (!Enemies.empty()) {
										if (combatList[q].getName() == Enemies[userInTwo - 1].getName()) {
											combatList.erase(combatList.begin() + q);
											Enemies.erase(Enemies.begin() + (userInTwo - 1));
											q--;
											i--;
											j--;
											break;

										}
								}
							}

						}

						//if ((Enemies[0].getCurrentHP() + Enemies[1].getCurrentHP() + Enemies[2].getCurrentHP() + Enemies[3].getCurrentHP()) <= 0)
						//{
						//	run = false;
						//	break;
						//}
						Vestal.getActor()->drawme(5, 24);
						Highwayman.getActor()->drawme(27, 24);
						GraveRobber.getActor()->drawme(49, 24);
						Crusader.getActor()->drawme(70, 24);//subject to change

						Enemies[0].getActor()->drawme(120, 24);
						Enemies[1].getActor()->drawme(145, 24); //subject to change
						Enemies[2].getActor()->drawme(170, 24); //subject to change
						break;
					}
					else {
						sortPosition(Heroes, Heroes.size());
						int randomSelect = rand() % Heroes.size();
						if (Heroes.size() == 1)
							randomSelect = 0;
						gotoxy(5, 49);
						if (!Enemies[j].isStunned())
							combatList[i].takeEnemyTurn(Heroes[randomSelect]);
						else {
							std::cout << combatList[i].getName() << " was stunned and can't act!\n";
							Enemies[j].setStun(false);
						}
						if (Heroes[randomSelect].getHeartAttack()) {
							gotoxy(5, 50);
							std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
							//combatList.erase(combatList.begin() + i);
							//Heroes.erase(Heroes.begin() + k);
							//i--;
							//k--;

						}

						if (Heroes[randomSelect].getCurrentHP() <= 0)
						{

							//gotoxy(5, 50);
							//std::cout << Heroes[randomSelect].getName() << " hath been deaded \n";
							killCharacter(Heroes[randomSelect]);


							//for (auto itr = combatList.begin(); itr != combatList.end(); itr++) {
							//try {
								for (int q = 0; q < combatList.size(); q++) {
									if (!Heroes.empty()) {
										if(randomSelect < Heroes.size())
										if (combatList[q].getName() == Heroes[randomSelect].getName()) {
											combatList.erase(combatList.begin() + q);
											Heroes.erase(Heroes.begin() + randomSelect);
											q--;
											i--;
											k--;
										}
									}
								}


							}
							Vestal.getActor()->drawme(5, 24);
							Highwayman.getActor()->drawme(27, 24);
							GraveRobber.getActor()->drawme(49, 24);
							Crusader.getActor()->drawme(70, 24);//subject to change

							Enemies[0].getActor()->drawme(120, 24);
							Enemies[1].getActor()->drawme(145, 24); //subject to change
							Enemies[2].getActor()->drawme(170, 24); //subject to change
							break;
						}
					}
					break;
				}

				gotoxy(200, 61);
				if (Heroes.empty())
					run = !run;
				system("pause");
				if (!run)
					break;

			}
		}
	}







