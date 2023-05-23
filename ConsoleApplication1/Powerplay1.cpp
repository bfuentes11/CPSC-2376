#include <iostream>
#include <vector>
#include <random>
#include <stdlib.h>
using namespace std;

// Player template
struct Player
{
	std::string Name;
	int strength{};
	int health{};
};

// Monster template
struct Monster
{
	std::string monstName;
	int monstStrength{};
	int monstHealth{};

};

//Heals Character
void characterHeal(Player& player) {
	int heal = player.strength * 2;
}

//Displays character name
void nameCharacter(Player& player) {
	std::cout << "Name: " << player.Name << std::endl;
}

// Displays character strength
void displayStrength(Player& player) {
	std::cout << "Strength: " << player.strength<< std::endl;
}

//Displays character health
void displayHealth(Player& player) {
	std::cout << "Health: " << player.health << std::endl;
}

int main()
{
	//Engine creation

	std::random_device seed;
	std::default_random_engine e(seed());
	std::normal_distribution<double> nDist(30.0, 5.0);
	std::uniform_int_distribution<int> uiDist(1, 3);

	/*
	Player and Monster Stats
	Plus one is being used to avoid having str and health set to 0
	*/
	int strPlayer = 1 + nDist(e);
	int vitPlayer = 1 + nDist(e);

	int strMonster = 1 + nDist(e);
	int vitMonster = 1 + nDist(e);
	//Random Monster Count
	std::vector <int> monst;
	monst = { uiDist(e) };
	int x = monst.size();

	//Monster Creation
	if (x == 1) {
		Monster enemy1{ "Monster1" , strMonster, vitMonster };
	}
	else if (x == 2) {
		Monster enemy1{ "Monster1" , strMonster, vitMonster };
		Monster enemy2{ "Monster2" , strMonster, vitMonster };
	}
	else {
		Monster enemy1{ "Monster1" , strMonster, vitMonster };
		Monster enemy2{ "Monster2" , strMonster, vitMonster };
		Monster enemy3{ "Monster3" , strMonster, vitMonster };
	}



	string customName;

	std::cout << "What is your name" << endl;

	std::cin >> customName;

	system("CLS");


	std::cout << "Hello " << customName << endl;

	Player Link{ customName , strPlayer, vitPlayer };
	cout << endl << "Here is your profile: " << endl;
	nameCharacter(Link);
	displayHealth(Link);
	displayStrength(Link);

	cout << endl;

	system("PAUSE");
	system("CLS");


	//Game Start
	while (Link.health != 0 || monst.size() != 0) {
		int choice = 0;
		cout << "BATTLE BEGIN" << endl << endl;
		cout << "Choose an action" << endl << "1. Attack " << " 2. Heal" << endl;
		cout << "3. Walk Away" << endl;
		switch (choice) {
		case 1: 




		}

	}


	
	
	
}
