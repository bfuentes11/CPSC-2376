#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>

//Changed to PP1 Solution as recommended.


struct Object
{
	std::string name;
	int strength{ 0 };
	int health{ 0 };
};

//Declarations
std::vector<Object>	loadMonsters(const std::string& fileName);
void displayBattle(const Object& player, const std::vector<Object>& monsters);
bool monsterAttack(Object& player, std::vector<Object>& monsters);
int playerAttack(Object& player,const std::vector<Object>& monsters);
int attack(Object& object);
void defend(Object& object, int damage);
void heal(Object& object);

std::random_device seed;
std::default_random_engine e(seed());


int main()
{


	std::normal_distribution<double> randomHealth(30.0, 5.0);
	std::normal_distribution<double> randomStrength(5.0, 1.0);

	

	Object player
	{
		"Lon",
		std::max(1, (int)randomStrength(e)),
		std::max(1, (int)randomHealth(e))
	};

	std::vector<Object>monsters{ loadMonsters("monsters.txt") };

	//Got rid of while loop temporarily, parts of it are being sent to our functions


	std::cout << monsters.size() << " monster(s) approaches!!" << std::endl;
	bool allDead{ false };

	while (player.health > 0 && !monsterAttack(player, monsters)) {


		displayBattle(player, monsters);
		std::cout << "What do you do? (a)ttack (h)eal ";
		char command{  };
		std::cin >> command;
		switch (command)
		{
		case 'a':
		{
			std::cout << "Which Monster: ";
			int monsterNum{ 0 };
			std::cin >> monsterNum;
			if (monsterNum > 0 && monsterNum <= monsters.size())
			{
				if (monsters.at(monsterNum - 1).health > 0)
					monsters[monsterNum - 1].health -= player.strength;
			}
			break;
		}
		case 'h':
			player.health += player.strength * 2;
			break;
		default:
			std::cout << "please enter a or h" << std::endl;
			break;
		}
	}

	if (player.health <= 0) {
		std::cout << "You Have Died" << std::endl;
	}
	else
	{
		std::cout << "You have killed the monsters!!!" << std::endl;
	}
	system("PAUSE");
}


	std::vector<Object> loadMonsters(const std::string& fileName)
	{
		std::fstream doc;
		doc.open(fileName);
		std::vector<Object> monsters;
		if (doc.is_open()) {
			int numMonsters;
			doc >> numMonsters;
			//We recreate the for loop so now it works with our document
			for (int i = 0; i < numMonsters; i++) {

				//Monster stats
				std::string name;
				int strength;
				int health;
				doc >> name;
				doc >> strength;
				doc >> health;

				monsters.push_back({ name, strength,health });
			}

		}
		doc.close();
		return monsters;
	}

	void displayBattle(Object & player, std::vector<Object>&monsters) {
		std::cout << player.name << ": " << player.health << std::endl
			<< "  Monsters: " << std::endl;
		for (int i{ 0 }; i < monsters.size(); i++)
		{
			std::cout << "   " << i + 1 << ". " << monsters[i].name << ": ";
			if (monsters.at(i).health <= 0)
				std::cout << "<DEAD> " << std::endl;
			else
				std::cout << monsters[i].health << std::endl;
		}
	}

	bool monsterAttack(Object & player, std::vector<Object>&monsters) {

		std::bernoulli_distribution willAttack(.75);
		bool allDead{ true };
		for (const auto& monster : monsters)
		{
			if (monster.health > 0)
			{
				allDead = false;
				if (willAttack(e))
				{
					std::cout << monster.name << " attacks!" << std::endl;
					player.health -= monster.strength;
				}
				else
				{
					std::cout << monster.name << " twiddles its thumbs" << std::endl;
				}
			}
		}
		return allDead;
	}

	bool playerAttack(Object& player , std::vector<Object>& monsters) {
		std::cout << "Which Monster: ";
		int monsterNum{ 0 };
		std::cin >> monsterNum;
		if (monsterNum > 0 && monsterNum <= monsters.size())		{
			defend(monsters[monsterNum - 1], attack(player));
		}
	}

	//attack defend work together
	int attack(Object & object) {
		std::normal_distribution<int> damageDealt(object.strength * 2);
		return std::max(1, (int)damageDealt(e));
		std::cout << object.name << "deals ";
	}

	void defend(Object & object, int damage) {
		std::cout << damage << " damage to " << object.name << "!!" << std::endl;
		object.health = object.health - damage;
	}

	void heal(Object& object) {
		std::normal_distribution<int> lifeHeal(object.strength * 2, 3);
		int healAmount{ std::max(1, lifeHeal(e)) };
		std::cout << "You have restored  " << healAmount << " life points." << std::endl;
		object.health = object.health + healAmount;
	}

