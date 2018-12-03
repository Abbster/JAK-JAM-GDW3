#include "Character.h"
//#include "drawing.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include "Scene.h"


int main()
{
	Sprite* BACKGROUND_scene1 = new Sprite("menu3.4.txt");
	Sprite* UI_scene1 = new Sprite("emptyRoom.txt");

	std::vector<Scene*> scenes;

	for (int i = 0; i < 10000; i++) {
		scenes.push_back(new Scene(BACKGROUND_scene1, UI_scene1));
		scenes[i]->play();
		gotoxy(80, 55);
		std::cout << "Fight komplete! Press any key to continue into the depths of madness! \n";
		scenes[i]->~Scene();
		gotoxy(200, 61);
		system("pause");

	}
	


//	decendIntoMadness();

	return 0;
}


