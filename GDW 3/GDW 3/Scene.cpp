#include "Scene.h"
#include <cstdlib>

//Initializing hero sprites
Sprite *CRUSADER_SPRITE = new Sprite("crusader.txt");
Sprite *GRAVEROBBER_SPRITE = new Sprite("graveRobber.txt");
Sprite *HIGHWAYMAN_SPRITE = new Sprite("highwayman.txt");
Sprite *VESTAL_SPRITE = new Sprite("vestal.txt");

//Initializing enemy sprites
Sprite *SKELETON1_SPRITE = new Sprite("skeleton.txt");
Sprite *SKELETON2_SPRITE = new Sprite("skeleton2.txt");
Sprite *BRAWLER_SPRITE = new Sprite("brawler.txt");
Sprite *DEFENDER_SPRITE = new Sprite("defender.txt");
Sprite *CLEAR_SPRITE = new Sprite("cSpace.txt");

//Initializing more sprites
Sprite *LIGHT10 = new Sprite("Light10.txt");
Sprite *TORCH_SPRITE = new Sprite("Light10.txt");

//Inventory
Inventory AdventurersPack;
Item *torch = new Item("Torch", TORCH_SPRITE);

//Function that replaces a characters sprite with bones when they die
void Scene::killCharacter(character &c)
{
	//Remove from combat list
		//c.die();
	c.getActor()->setPath("bones.txt");

}

//Unimplemented light stuff
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
	
}
//Initializing the stress for all the heroes
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

//Initializes all the things
void Scene::initializeTheCrazyPeople()
{
	//UserInterface list
	UserInterface CrusaderUI("crusaderui.txt");
	UserInterface GraveRobberUI("graveRobberui.txt");
	UserInterface HighwaymanUI("highwaymanui.txt");
	UserInterface VestalUI("vestalui.txt");
	UserInterface EnemyUI("emptyRoom.txt");

	//Switch to pointers
	
	//Setting all the hero stats and abilities
	//character(health, dodge, defence, speed, crit, attack, name, sprite)

	//CRUSADER 
	this->Crusader = character(33, 0.05, 1, 1, 0.03, 6, "Crusader", CRUSADER_SPRITE);//creating a new character. see constructor for what these numbers mean

	Crusader.setUI(CrusaderUI);
	ability Smite(1, "Smite");
	Crusader.setAbility(Smite, 1);

	ability StunningBlow(0.50, "Stunning Blow");
	StunningBlow.setStun(1);
	Crusader.setAbility(StunningBlow, 2);

	ability HolyLance(1, "Holy Lance");
	Crusader.setAbility(HolyLance, 3);

	Crusader.setPosition(4);

	//GRAVE ROBBER 
	this->GraveRobber = character(20, 0.10, 1, 8, 0.06, 4, "Grave Robber", GRAVEROBBER_SPRITE);

	GraveRobber.setUI(GraveRobberUI);
	ability PickToTheFace(0.15, "Pick To The Freakin' Face");
	GraveRobber.setAbility(PickToTheFace, 1);

	ability Lunge(1.40, "Lunge");
	GraveRobber.setAbility(Lunge, 2);

	ability ThrownDagger(0.10, "Thrown Dagger");
	GraveRobber.setAbility(ThrownDagger, 3);

	GraveRobber.setPosition(3);

	//HIGHWAYMAN 
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

	//VESTAL 
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

	//All of these have 30 ish hp..which we will change after anyways

	//Setting all enemy stats and abilities
	//character(health, dodge, defence, speed, crit, attack, name, sprite)
	SkeletonWitch = character(18, 0, 1, 7, 0.01, 6, "Skeleton Witch", SKELETON1_SPRITE);
	
	ability Blast(0.8, "Blast");
	SkeletonWitch.setAbility(Blast, 1);
	ability DarkMagic(1.2, "Dank Magic Attack");
	SkeletonWitch.setAbility(DarkMagic, 2);


	Skeleton = character(20, 0, 1, 2, 0.01, 3, "Skeleton", SKELETON2_SPRITE);
	
	ability Shank(0.7, "Shank");
	Skeleton.setAbility(Shank, 1);
	ability Slash(1, "Slash");
	Skeleton.setAbility(Slash, 2);


	Brawler = character(25, 0, 1, 5, 0.01, 4, "Brawler", BRAWLER_SPRITE);

	ability Fist(0.75, "Hefty Fist");
	Brawler.setAbility(Fist, 1);
	ability Kick(1.1, "Kick");
	Brawler.setAbility(Kick, 2);


	Defender = character(30, 0, 1, 7, 0.01, 2, "Defender", DEFENDER_SPRITE);
	
	ability ShieldBash(0.5, "Shield Bash");
	Defender.setAbility(ShieldBash, 1);
	ability Rush(1, "Rush");
	Defender.setAbility(Rush, 2);
	
	SkeletonWitch.setUI(EnemyUI);



	//Sets the enemies as potential enemies 
	potentialEnemies.push_back(SkeletonWitch);
	potentialEnemies.push_back(Skeleton);
	potentialEnemies.push_back(Brawler);
	potentialEnemies.push_back(Defender);

	//Pushes random potential enemies into the party of enemies
	Enemies.push_back(potentialEnemies[randomEnemySelect1]);
	Enemies.push_back(potentialEnemies[randomEnemySelect2]);
	Enemies.push_back(potentialEnemies[randomEnemySelect3]);
	Enemies.push_back(potentialEnemies[randomEnemySelect4]);

	//Pushes all the heroes into the list of heroes
	Heroes.push_back(Crusader);
	Heroes.push_back(GraveRobber);
	Heroes.push_back(Highwayman);
	Heroes.push_back(Vestal);


	//Pushes everything into the combatlist
	combatList.push_back(Crusader);
	combatList.push_back(GraveRobber);
	combatList.push_back(Highwayman);
	combatList.push_back(Vestal);
	combatList.push_back(Enemies[0]);
	combatList.push_back(Enemies[1]);
	combatList.push_back(Enemies[2]);
	combatList.push_back(Enemies[3]);

}


//Sort function that sorts by speed
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

	//Outputs the turn order
	gotoxy(5, 43);
	std::cout << "Turn Order: ";
	for (int i = 0; i < size; i++)
		std::cout << c[i].getName() << "  ";//prints the elements of the array
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
//A function that sorts the characters by their combat position
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

//A function that sorts the characters by their combat position without text 
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

	//If the heroes are dead
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

	//Redraws the enemies
	int heroShift = 0;
	for (int e = 0; e < Heroes.size(); e++) {
		Heroes[e].getActor()->drawme(5 + heroShift, 21);
		heroShift += 22;
	}

	//Press d to move the heroes
	std::cout << "Press D!\n";
	Party Adventurers(Crusader, GraveRobber, Highwayman, Vestal, AdventurersPack);
	while (true) {
		if (isEvent(Events::D)) {
			for (int u = 0; u < 100; u++) {
				Vestal.getActor()->drawme(5 + u, 22);
				Highwayman.getActor()->drawme(27 + u, 22);
				GraveRobber.getActor()->drawme(49 + u, 22);
				Crusader.getActor()->drawme(71 + u, 22);//subject to change
			}
				break;

		}
	}

	//Sorts the combat list and positions of the enemies
	sortNoText(Heroes, Heroes.size());
	sort(combatList, combatList.size());
	Adventurers.getInventory().addItem(torch);
	sortPosition(Enemies, Enemies.size());

	//Combat loop
	while (run) {
		//Iterates through the combat list
		for (int i = 0; i < combatList.size(); i++) {
			//Iterates through the enemies list
			for (int j = 0; j < Enemies.size(); j++) {
				//Iterates though the heroes list
				for (int k = 0; k < Heroes.size(); k++) {
				turn:
					//start of every turn it clears the screen and redraws everything
					system("cls");
					int heroShift2 = 0;
					int enemyShift2 = 0;
					
					for (int e = 0; e < Heroes.size(); e++) {
						Heroes[e].getActor()->drawme(5 + heroShift2, 21);
						heroShift2 += 22;
					}
					
					for (int e = 0; e < Enemies.size(); e++) {
						Enemies[e].getActor()->drawme(120 + enemyShift2, 21);
						enemyShift2 += 25;
					}


					sort(combatList, combatList.size());
					sortNoText(Heroes, Heroes.size());
					if (combatList[i].getName() == "Crusader" || combatList[i].getName() == "Grave Robber"
						|| combatList[i].getName() == "Highwayman" || combatList[i].getName() == "Vestal") {


						combatList[i].drawUserInterface();
					//Displays stress
					gotoxy(214, 51);
					std::cout << Crusader.getName() << " - " << stress1 << std::endl;
					gotoxy(214, 53);
					std::cout << GraveRobber.getName() << " - " << stress2 << std::endl;
					gotoxy(214, 55);
					std::cout << Highwayman.getName() << " - " << stress3 << std::endl;
					gotoxy(214, 57);
					std::cout << Vestal.getName() << " - " << stress4 << std::endl;

					//Tells the player whos turn it is
						gotoxy(5, 46);
						std::cout << "Its " << combatList[i].getName() << "'s Turn!\n";
						//std::cout << "HP: " << combatList[i].getCurrentHP() << std::endl;

						//Displays the heroes current health
						gotoxy(33, 46);
						std::cout << Heroes[k].getCurrentHP() << std::endl;
						gotoxy(85, 50);
						//User input validation
						while (!(std::cin >> userIn)|| userIn > 4 || userIn <=0) {
							std::cin.clear();
							std::cin.ignore(100, '\n');
							gotoxy(85, 48);
							std::cout << "Select an ability (1,2,3,4(Torch)):\n";

						}//1 2 3 4

						//User input 
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
						//User input validation
						gotoxy(140, 50);
						while (!(std::cin >> userInTwo) || userInTwo > 4 || userInTwo <= 0) {
							std::cin.clear();
							std::cin.ignore(100, '\n');
							gotoxy(85, 48);
							std::cout << "Select a target (1,2,3,4):\n";
						}// 4 5 6 7 (or 1 2 3 4 if healing...maybe)

						//make another sort function with positions
						sortPosition(Heroes, Heroes.size());
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
						//Redraws stuff again
						int heroShift3 = 0;
						for (int e = 0; e < Heroes.size(); e++) {
							Heroes[e].getActor()->drawme(5 + heroShift3, 21);
							heroShift3 += 22;
						}

						int enemyShift3 = 0;
						for (int e = 0; e < Enemies.size(); e++) {
							Enemies[e].getActor()->drawme(120 + enemyShift3, 21);
							enemyShift3 += 25;
						}
						break;
					}


					else {
					//redraws user interface
						SkeletonWitch.drawUserInterface();
						sortPosition(Heroes, Heroes.size());
						int randomSelect = rand() % Heroes.size();
						if (Heroes.size() == 1)
							randomSelect = 0;
						gotoxy(5, 49);
						//Enemies turn (attacks, add stress)
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
						//if the enemy is stunned
						else {
							gotoxy(85, 55);
							std::cout << combatList[i].getName() << " was stunned and can't act!\n";
							combatList[i].setStun(false);
						}
						
						//If the heroes stress is equal to or higher than 10, they will experience cardiac arrest and die
						//if the hero is at 0 hp, they also die
						if (Heroes[randomSelect].getCurrentHP() <= 0 || stress1 >= 10|| stress2 >= 10 || stress3 >= 10 || stress4 >= 10)
						{

							std::cout<<Heroes[randomSelect].getName() << " died!\n";
							
							//Redraws heroes
							for (int q = 0; q < combatList.size(); q++) {
								int heroShift1z = 0;
								for (int e = 0; e < Heroes.size(); e++) {
									Heroes[e].getActor()->drawme(5 + heroShift1z, 21);
									heroShift1z += 22;
								}
								//Clears the heroes sprite if they are dead
								if (!Heroes.empty()) {
									if (randomSelect < Heroes.size())
										if (combatList[q].getName() == Heroes[randomSelect].getName()) {
											Heroes[randomSelect].setActor(CLEAR_SPRITE);
											combatList.erase(combatList.begin() + q);
											Heroes.erase(Heroes.begin() + randomSelect);


											q--;
											i--;
											k--;
										}
								}
							}
						}
						
						//Redraws everything again
						int heroShift4 = 0;
						for (int e = 0; e < Heroes.size(); e++) {
							Heroes[e].getActor()->drawme(5 + heroShift4, 21);
							heroShift4 += 22;
						}

						int enemyShift4 = 0;
						for (int e = 0; e < Enemies.size(); e++) {
							Enemies[e].getActor()->drawme(120 + enemyShift4, 21);
							enemyShift4 += 25;
						}
						break;
					}
				}
				break;
			}

			//Continues program if heroes are alive, ends if they deaded
			gotoxy(200, 61);
			//closes the program if you die
			if (Heroes.empty() || stress1 >= 10 && stress2 >= 10 && stress3 >= 10 && stress4 >= 10) {
				
				exit(0);//closes program
			}
			system("pause");
			

		}
	}
}







