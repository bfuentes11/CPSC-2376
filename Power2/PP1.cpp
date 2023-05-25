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
int attack();
void defend();
void heal();


//TodoList
/*
loadmonsters DONE
displaybattle DONE
monsterattack
playerattack
attack
defend
heal
*/
std::random_device seed;
std::default_random_engine engine(seed());


int main()
{


	std::normal_distribution<double> randomHealth(30.0, 5.0);
	std::normal_distribution<double> randomStrength(5.0, 1.0);

	int numMonsters;

	Object player
	{
		"Lon",
		std::max(1, (int)randomStrength(engine)),
		std::max(1, (int)randomHealth(engine))
	};

	std::vector<Object>monsters{loadMonsters("monsters.txt")};

	//Got rid of while loop temporarily, parts of it are being sent to our functions


	std::cout << numMonsters << " monster(s) approaches!!" << std::endl;
	bool allDead{ false };



	if (player.health <= 0)
	{
		std::cout << "You Have Died" << std::endl;
	}
	if (player.health <= 0 && allDead)
	{
		std::cout << "BUT" << std::endl;
	}
	if (allDead)
	{
		std::cout << "You have killed the monsters!!!" << std::endl;
	}
	system("PAUSE");

	std::vector<Object> loadMonsters(const std::string & fileName) {
		std::fstream doc;
		doc.open(fileName);
		std::vector<Object> monsters;
		if (doc.is_open()) {
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

	void displayBattle(Object& player, std::vector<Object>&monsters) {
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

	bool monsterAttack(Object& player, std::vector<Object>& monsters) {
		std::bernoulli_distribution willAttack(.75);
		allDead = true;
		for (const auto& monster : monsters)
		{
			if (monster.health > 0)
			{
				allDead = false;
				if (willAttack(engine))
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
	}

	bool playerAttack() {
		std::cout << "Which Monster: ";
		int monsterNum{ 0 };
		std::cin >> monsterNum;
		if (monsterNum > 0 && monsterNum <= monsters.size())
		{
			defend();
		}
	}

}
