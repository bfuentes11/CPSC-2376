#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

//Changed to PP1 Solution as recommended.


struct Object
{
	std::string name;
	int strength{ 0 };
	int health{ 0 };
};
std::vector<Object>	loadMonsters(std::string& filename);
//displayBattle is void because it does not return anything
void displayBattle(const Object& player, const std::vector<Object>& monsters);
int monsterAttack();
int playerAttack();
int attack();
void defend();
void heal();


//TodoList
/*
loadmonsters DONE
displaybattle
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

	Object player
	{
		"Lon",
		std::max(1, (int)randomStrength(engine)),
		std::max(1, (int)randomHealth(engine))
	};
	std::vector<Object>monsters{ loadMonsters(monsters.txt) };

	//Got rid of for loop and engine for monsters 
	//because our Monsters come from a text file now
	

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
}
