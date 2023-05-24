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
int characterHeal(Player& player) {
	int heal = player.strength * 2;
	return heal;
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
	std::bernoulli_distribution bDist(0.75);


	
	/*
	Player Stats
	Plus one is being used to avoid having str and health set to 0
	*/
	int strPlayer = 1 + nDist(e);
	int vitPlayer = 1 + nDist(e);

	
	//Monster Stats
	int strMonster = 1 + nDist(e);
	int strMonster2 = 1 + nDist(e);
	int strMonster3 = 1 + nDist(e);
	int vitMonster = 1 + nDist(e);
	int vitMonster2 = 1 + nDist(e);
	int vitMonster3 = 1 + nDist(e);
	
	
	//Random Monster Count
	std::vector <int> monst;
	monst = { uiDist(e) };
	int x = monst.size();


	Monster Enemy1{ "Monster1" , strMonster, vitMonster };
	Monster Enemy2{ "Monster2" , strMonster2, vitMonster2 };
	Monster Enemy3{ "Monster3" , strMonster3, vitMonster3};

	//Monster Deletion
	if (x == 1) {
		monst.resize(1);
		Monster Enemy1{ "Monster1" , strMonster, vitMonster };
		Monster Enemy2{ "Monster2" , strMonster2, vitMonster2 };
		Monster Enemy3{ "Monster3" , strMonster3, vitMonster3 };


	}
	else if (x == 2) {
		monst.resize(2);
		Monster Enemy1{ "Monster1" , strMonster, vitMonster };
		Monster Enemy2{ "Monster2" , strMonster2, vitMonster2 };

	}
	else {
		monst.resize(3);
		Monster Enemy1{ "Monster1" , strMonster, vitMonster };
		Monster Enemy2{ "Monster2" , strMonster2, vitMonster2 };
		Monster Enemy3{ "Monster3" , strMonster3, vitMonster3 };

	}

	//Balancing to avoid getting oneshot
	if (vitPlayer < strMonster || strMonster2 || strMonster3) {
		vitPlayer = vitPlayer + 20;
	}
	



	string customName;

	std::cout << "What is your name" << endl;

	std::cin >> customName;

	//system("CLS");


	std::cout << "Hello " << customName << endl;

	Player Link{ customName , strPlayer, vitPlayer };


	std::cout << endl;

	system("PAUSE");
	//system("CLS");
	
	
	//Game Start
	while (Link.health > 0 && x > 0) {
		int choice = 0;
		int secondChoice = 0;
			
		std::cout << "BATTLE BEGIN" << endl << endl;

		//display stats
		nameCharacter(Link);
		displayHealth(Link);
		displayStrength(Link);

		//battle system (player turn)
		std::cout << "Choose an action" << endl << "1. Attack " << " 2. Heal" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			//system("CLS");
			std::cout << "Who would you like to attack ?" << endl;
			cin >> secondChoice;
			switch (secondChoice)
			{
			case 1:
				if (Enemy1.monstHealth <= 0) {
					std::cout << "Monster is dead cannot attack";
					x - 1;
					break;
				}
				else {
					std::cout << "Monster Health: " << Enemy1.monstHealth << endl;
					std::cout << "Attacking" << endl;
					Enemy1.monstHealth = Enemy1.monstHealth - Link.strength;
					std::cout << "Monster Health is now : " << Enemy1.monstHealth;
					break;
				}
			case 2:
				if (Enemy2.monstHealth <= 0) {
					std::cout << "Monster is dead cannot attack";
					x - 1;
					break;
				}
				else {
					std::cout << "Monster Health: " << Enemy2.monstHealth << endl;
					std::cout << "Attacking" << endl;
					Enemy2.monstHealth = Enemy2.monstHealth - Link.strength;
					std::cout << "Monster Health is now : " << Enemy2.monstHealth;
					break;
			case 3:
				if (Enemy3.monstHealth <= 0) {
					std::cout << "Monster is dead cannot attack";
					x - 1;
					break;
				}
				else {
					std::cout << "Monster Health: " << Enemy3.monstHealth << endl;
					std::cout << "Attacking" << endl;
					Enemy3.monstHealth = Enemy3.monstHealth - Link.strength;
					std::cout << "Monster Health is now : " << Enemy3.monstHealth;
					break;
			default:
				std::cout << "You have attacked air." << endl;
				break;
				}

			

				}



			}
			break;
		case 2:
			std::cout << "HEALING" << endl;
			Link.health = characterHeal(Link);

			std::cout << "You have restored " << Link.health << " points" << endl;
			break;
		
		default:
			cout << "You lose a turn for trying to be funny" << endl;
			break;





		}

		//system("CLS");
		std::cout << endl << "ENEMY PHASE" << endl;

		for (auto num : monst) {
			if (bDist(e) >= 1) {
				if (Enemy1.monstHealth > 0) {
					Link.health = Link.health - Enemy1.monstStrength;
					std::cout << "You have lost " << Enemy1.monstStrength << " health" << endl;
				}
				else if(Enemy2.monstHealth > 0){
					Link.health = Link.health - Enemy2.monstStrength;
					std::cout << "You have lost " << Enemy2.monstStrength << " health" << endl;

				}
				else if (Enemy3.monstHealth > 0) {
					Link.health = Link.health - Enemy3.monstStrength;
					std::cout << "You have lost " << Enemy3.monstStrength << " health" << endl;
				}
				else {
					std::cout << "ALL MONSTERS ARE DEAD!" << endl;
						x = 0;
				}
			}

		}
		system("PAUSE");
		//system("CLS");
	}

	if (Link.health <= 0) {
		std::cout << "You have died" << endl << "Game over";
	}
	else {
		std::cout << "You have slain all the monsters!" << endl << "Game over";
		}

	
}