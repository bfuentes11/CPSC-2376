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

//Character and Monster actions
void characterHeal(Player& player) {
	int heal = player.strength * 2;
}
void playerAttack(Player& player) {
	int playerAttack = player.strength;
}
void monsterAttack(Monster& monster) {
	int monstAttack = monster.monstStrength;
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

	Monster Enemy1{ "Monster1" , strMonster, vitMonster };
	Monster Enemy2{ "Monster2" , strMonster, vitMonster };
	Monster Enemy3{ "Monster3" , strMonster, vitMonster };

	//Monster Deletion
	if (x == 1) {
		monst.resize(1);
		Monster Enemy1{ "Monster1" , strMonster, vitMonster };
		
	}
	else if (x == 2) {
		monst.resize(2);
		Monster Enemy1{ "Monster1" , strMonster, vitMonster };
		Monster Enemy2{ "Monster2" , strMonster, vitMonster };
		
	}
	else {
		monst.resize(3);
		Monster Enemy1{ "Monster1" , strMonster, vitMonster };
		Monster Enemy2{ "Monster2" , strMonster, vitMonster };
		Monster Enemy3{ "Monster3" , strMonster, vitMonster };
		
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
	while (Link.health != 0 || x != 0) {
		int choice = 0;
		cout << "BATTLE BEGIN" << endl << endl;
		
		//display stats
		nameCharacter(Link);
		displayHealth(Link);
		displayStrength(Link);

		//battle system (player turn)
		cout << "Choose an action" << endl << "1. Attack " << " 2. Heal" << endl;
		cout << "3. Walk Away" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("CLS");
			cout << "Who would you like to attack ?" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				if (Enemy1.monstHealth == 0) {
					cout << "Monster is dead cannot attack";
						x - 1;

				}
				else {
					cout << "Monster Health: " << Enemy1.monstHealth << endl;
					cout << "Attacking" << endl;
					Enemy1.monstHealth - Link.strength;
					cout << "Monster Health is now : " << Enemy1.monstHealth;
					break;
				}
			case 2:
				if ()
				else if (Enemy2.monstHealth == 0) {
					cout << "Monster is dead cannot attack";
						x - 1;

				}
				else {
					cout << "Monster Health: " << Enemy2.monstHealth << endl;
					cout << "Attacking" << endl;
					Enemy2.monstHealth - Link.strength;
					cout << "Monster Health is now : " << Enemy2.monstHealth;
					break;
			case 3:
				if (Enemy3.monstHealth == 0) {
					cout << "Monster is dead cannot attack";
						x - 1;

				}
				else {
					cout << "Monster Health: " << Enemy3.monstHealth << endl;
					cout << "Attacking" << endl;
					Enemy3.monstHealth - Link.strength;
					cout << "Monster Health is now : " << Enemy3.monstHealth;
					break;
			default:
				break;
			}

		default:
			break;
		}
		

	}


	
	
	
}
