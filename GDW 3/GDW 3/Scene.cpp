#include "Scene.h"

Sprite *CRUSADER_SPRITE = new Sprite("crusader.txt");
Sprite *GRAVEROBBER_SPRITE = new Sprite("graveRobber.txt");
Sprite *HIGHWAYMAN_SPRITE = new Sprite("highwayman.txt");
Sprite *VESTAL_SPRITE = new Sprite("vestal.txt");

Sprite *SKELETON1_SPRITE = new Sprite("skeleton.txt");
Sprite *SKELETON2_SPRITE = new Sprite("skeleton2.txt");
Sprite *BRAWLER_SPRITE = new Sprite("brawler.txt");
Sprite *DEFENDER_SPRITE = new Sprite("defender.txt");
Sprite *CLEAR_SPRITE = new Sprite("cSpace.txt");

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
	int Scene::stress1 = 0;
	int Scene::stress2 = 0;
	int Scene::stress3 = 0;
	int Scene::stress4 = 0;
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
	UserInterface EnemyUI("emptyRoom.txt");

	//switch to pointers

	//CRUSADER 33
	this->Crusader = character(33, 0.05, 1, 1, 0.03, 6, "Crusader", CRUSADER_SPRITE);//creating a new character. see constructor for what these numbers mean

	Crusader.setUI(CrusaderUI);
	ability Smite(1, "Smite");
	Crusader.setAbility(Smite, 1);//sets crusader's first ability to smite

	ability StunningBlow(0.50, "Stunning Blow");
	StunningBlow.setStun(1);
	Crusader.setAbility(StunningBlow, 2);

	ability HolyLance(1, "Holy Lance");
	Crusader.setAbility(HolyLance, 3);

	Crusader.setPosition(4);

	//GRAVE ROBBER 20
	this->GraveRobber = character(20, 0.10, 1, 8, 0.06, 4, "Grave Robber", GRAVEROBBER_SPRITE);

	GraveRobber.setUI(GraveRobberUI);
	ability PickToTheFace(0.15, "Pick To The Freakin' Face");
	GraveRobber.setAbility(PickToTheFace, 1);

	ability Lunge(1.40, "Lunge");
	GraveRobber.setAbility(Lunge, 2);

	ability ThrownDagger(0.10, "Thrown Dagger");
	GraveRobber.setAbility(ThrownDagger, 3);

	GraveRobber.setPosition(3);

	//HIGHWAYMAN 23
	Highwayman = character(23, .10, 1, 5, 0.05, 5, "Highwayman", HIGHWAYMAN_SPRITE);

	Highwayman.setUI(HighwaymanUI);
	ability GrapeshotBlast( 0.50, "Grapeshot Blast");
	GrapeshotBlast.setHitsMulti(true);
	Highwayman.setAbility(GrapeshotBlast, 1);

	ability PointBlankShot(1.50, "Point Blank Shot");
	Highwayman.setAbility(PointBlankShot, 2);

	ability PistolShot(0.15, "Pistol Shot");
	Highwayman.setAbility(PistolShot, 3);

	Highwayman.setPosition(2);

	//VESTAL 24
	Vestal = character(24, 0, 1, 4, 0.01, 4, "Vestal", VESTAL_SPRITE);

	Vestal.setUI(VestalUI);
	ability DivineGrace(0.75, "Divine Grace");
	Vestal.setAbility(DivineGrace, 1);
	ability Dazzle(0.75, "Dazzling Light");
	Vestal.setAbility(Dazzle, 2);
	ability DivineComfort(0.75, "Divine Comfort");
	Vestal.setAbility(DivineComfort, 3);

	Vestal.setPosition(1);

	int randomEnemySelect1 = rand() % 4;
	int randomEnemySelect2 = rand() % 4;
	int randomEnemySelect3 = rand() % 4;
	int randomEnemySelect4 = rand() % 4;
	std::vector<character> potentialEnemies;

	//all of these have 30 ish hp..which we will change after anyways
	SkeletonWitch = character(1, 0, 1, 10, 0.01, 6, "Skeleton Witch", SKELETON1_SPRITE);
	//20
	ability Blast(0.7, "Blast");
	SkeletonWitch.setAbility(Blast, 1);
	ability DarkMagic(1.2, "Dank Magic Attack");
	SkeletonWitch.setAbility(DarkMagic, 2);


	Skeleton = character(1, 0, 1, 1, 0.01, 3, "Skeleton", SKELETON2_SPRITE);
	//25
	ability Shank(0.7, "Shank");
	Skeleton.setAbility(Shank, 1);
	ability Slash(1, "Slash");
	Skeleton.setAbility(Slash, 2);


	Brawler = character(1, 0, 1, 30, 0.01, 4, "Brawler", BRAWLER_SPRITE);
	//30
	ability Fist(0.75, "Hefty Fist");
	Brawler.setAbility(Fist, 1);
	ability Kick(1.1, "Kick");
	Brawler.setAbility(Kick, 2);


	Defender = character(1, 0, 1, 7, 0.01, 2, "Defender", DEFENDER_SPRITE);
	//35
	ability ShieldBash(0.5, "Shield Bash");
	Defender.setAbility(ShieldBash, 1);
	ability Rush(1, "Rush");
	Defender.setAbility(Rush, 2);
	
	SkeletonWitch.setUI(EnemyUI);




	potentialEnemies.push_back(SkeletonWitch);
	potentialEnemies.push_back(Skeleton);
	potentialEnemies.push_back(Brawler);
	potentialEnemies.push_back(Defender);

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
	combatList.push_back(Enemies[3]);

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
		std::cout << c[i].getName() << "  ";//prints the elements of the array
	std::cout << std::endl;//ends the line after printing the array
	return c;//returning the sorted array

}

std::vector<character>& checkForSameName(std::vector<character> &c, int size) {

	//static int *sortedArray = new int[size];//declaring static dynamic array

	double change = 0;//variable to hold the current element

	for (int i = size - 1; i > 0; i--) {//for loop controlling which elements to loop through first, starting from the last

		for (int j = 0; j < i; j++)//loop that checks each element
		{
			if (c[j].getName() == c[j + 1].getName()) {//checks if the current element is greater than the next element
				//std::swap(c[j], c[j + 1]);
				c[j + 1].getNameREFERENCE().append("de", 2);
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
	//gotoxy(80, 43);
	//std::cout << "Position: ";
	//for (int i = 0; i < size; i++)
	//	std::cout << c[i].getName() << " ";//prints the elements of the array
	//std::cout << std::endl;//ends the line after printing the array
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
	if (Crusader.getActor()->getPath() == "bones.txt" && GraveRobber.getActor()->getPath() == "bones.txt"
		&& Highwayman.getActor()->getPath() == "bones.txt" && Vestal.getActor()->getPath() == "bones.txt")
		return;

	system("pause");
	system("CLS");

	//int userIn = 0, userInTwo = 0; 
	bool run = true;
	bool didMove = false;
	int vestalPos = 5;
	int highwaymanPos = 27;
	int graveRobberPos = 49;
	int crusaderPos = 71;
	Vestal.getActor()->drawme(5, 22);
	Highwayman.getActor()->drawme(27, 22);
	GraveRobber.getActor()->drawme(49, 22);
	Crusader.getActor()->drawme(71, 22);//subject to change
	Party Adventurers(Crusader, GraveRobber, Highwayman, Vestal, AdventurersPack);
	while (true) {
		if (isEvent(Events::D)) {
			for (int u = 0; u < 100; u++) {
				Vestal.getActor()->drawme(5 + u, 22);
				Highwayman.getActor()->drawme(27 + u, 22);
				GraveRobber.getActor()->drawme(49 + u, 22);
				Crusader.getActor()->drawme(71 + u, 22);//subject to change
			}
			int randEncounterChange = rand() % 2;
			if (randEncounterChange == 0) {
				system("pause");
				system("cls");
			}
			else if (randEncounterChange == 1)
				break;

		}
	}

	sort(combatList, combatList.size());
	Adventurers.getInventory().addItem(torch);
	sortPosition(Enemies, Enemies.size());
	while (run) {
		for (int i = 0; i < combatList.size(); i++) {
			for (int j = 0; j < Enemies.size(); j++) {
				for (int k = 0; k < Heroes.size(); k++) {
				turn:

					system("cls");
					gotoxy(214, 51);
					std::cout << Crusader.getName() << " - " << stress1 << std::endl;
					gotoxy(214, 53);
					std::cout << GraveRobber.getName() << " - " << stress2 << std::endl;
					gotoxy(214, 55);
					std::cout << Highwayman.getName() << " - " << stress3 << std::endl;
					gotoxy(214, 57);
					std::cout << Vestal.getName() << " - " << stress4 << std::endl;
					int shift = 0;
					Vestal.getActor()->drawme(5, 21);
					Highwayman.getActor()->drawme(27, 21);
					GraveRobber.getActor()->drawme(49, 21);
					Crusader.getActor()->drawme(71, 21);//subject to change
					
					for (int e = 0; e < Enemies.size(); e++) {
						Enemies[e].getActor()->drawme(120 + shift, 21);
						shift += 25;
					}


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
						gotoxy(85, 50);
						while (!(std::cin >> userIn)) {
							std::cin.clear();
							std::cin.ignore(100, '\n');
							gotoxy(85, 48);
							std::cout << "Select an ability (1,2,3,4(Torch)):\n";

						}//1 2 3 4

						if (userIn == 4) {
							if (!Adventurers.getInventory().getItems().empty()) {
								Adventurers.getInventory().getItems().pop_back();
								//gotoxy somewhere
								gotoxy(196, 59);
								std::cout << "Used a torch!\n";
							}
							else {
								gotoxy(196, 59);
								std::cout << "No torches!\n";
							}goto turn;
						}

						//gotoxy(100, 49);
						//std::cout << "Select a Target's Position\n";
						gotoxy(140, 50);
						while (!(std::cin >> userInTwo)) {
							std::cin.clear();
							std::cin.ignore(100, '\n');
							gotoxy(85, 48);
							std::cout << "Select an ability (1,2,3,4(Torch)):\n";
						}// 4 5 6 7 (or 1 2 3 4 if healing...maybe)
						sortPosition(Heroes, Heroes.size());//make another sort function with positions
						if (combatList[i].getName() == "Vestal" && userIn == 1 || combatList[i].getName() == "Vestal" && userIn == 3)
							combatList[i].takeTurnHeals(userIn, Heroes[userInTwo - 1]);
						else
							combatList[i].takeTurn(userIn, Enemies[userInTwo - 1]);

						if (Enemies[userInTwo - 1].getCurrentHP() <= 0) {
							for (int q = 0; q < combatList.size(); q++) {
								if (!Enemies.empty()) {
									if (combatList[q].getName() == Enemies[userInTwo - 1].getName()) {
										combatList.erase(combatList.begin() + q);
										Enemies.erase(Enemies.begin() + (userInTwo - 1));
										

										if (Enemies.empty()) {
											run = !run;
											break;
										}
										q--;
										i--;
										j--;
										break;

									}
								}

								
							}

						}

						Vestal.getActor()->drawme(5, 21);
						Highwayman.getActor()->drawme(27, 21);
						GraveRobber.getActor()->drawme(49, 21);
						Crusader.getActor()->drawme(71, 21);//subject to change

						int shift3 = 0;
						for (int e = 0; e < Enemies.size(); e++) {
							Enemies[e].getActor()->drawme(120 + shift3, 21);
							shift3 += 25;
						}
						break;
					}
					else {
						SkeletonWitch.drawUserInterface();
						sortPosition(Heroes, Heroes.size());
						int randomSelect = rand() % Heroes.size();
						if (Heroes.size() == 1)
							randomSelect = 0;
						gotoxy(5, 49);
						if (!Enemies[j].isStunned()) {
							combatList[i].takeEnemyTurn(Heroes[randomSelect]);
							if (Heroes[randomSelect].getName() == "Crusader")
								stress1 += 3;
							else if (Heroes[randomSelect].getName() == "Grave Robber")
								stress2 += 3;
							else if (Heroes[randomSelect].getName() == "Highwayman")
								stress3 += 3;
							else if (Heroes[randomSelect].getName() == "Vestal")
								stress4 += 3;
						}
						else {
							gotoxy(85, 55);
							std::cout << combatList[i].getName() << " was stunned and can't act!\n";
							Enemies[j].setStun(false);
						}
						
						if (Heroes[randomSelect].getCurrentHP() <= 0 || stress1 == 10|| stress2 == 10 || stress3 == 10 || stress4 == 10)
						{

							//gotoxy(5, 50);
							//std::cout << Heroes[randomSelect].getName() << " hath been deaded \n";
						//	killCharacter(Heroes[randomSelect]);


							//for (auto itr = combatList.begin(); itr != combatList.end(); itr++) {
							//try {
							for (int q = 0; q < combatList.size(); q++) {
								if (!Heroes.empty()) {
									if (randomSelect < Heroes.size())
										if (combatList[q].getName() == Heroes[randomSelect].getName()) {
											combatList.erase(combatList.begin() + q);
											Heroes.erase(Heroes.begin() + randomSelect);
											if (Heroes[randomSelect].getName() == "Crusader")
												CLEAR_SPRITE->drawme(crusaderPos, 21);
											else if (Heroes[randomSelect].getName() == "Grave Robber")
												CLEAR_SPRITE->drawme(graveRobberPos, 21);
											else if (Heroes[randomSelect].getName() == "Highwayman")
												CLEAR_SPRITE->drawme(highwaymanPos, 21);
											else if (Heroes[randomSelect].getName() == "Vestal")
												CLEAR_SPRITE->drawme(vestalPos, 21);


											q--;
											i--;
											k--;
										}
								}
							}
						}
						Vestal.getActor()->drawme(5, 21);
						Highwayman.getActor()->drawme(27, 21);
						GraveRobber.getActor()->drawme(49, 21);
						Crusader.getActor()->drawme(71, 21);//subject to change

						int shift2 = 0;
						for (int e = 0; e < Enemies.size(); e++) {
							Enemies[e].getActor()->drawme(120 + shift2, 21);
							shift2 += 25;
						}
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







