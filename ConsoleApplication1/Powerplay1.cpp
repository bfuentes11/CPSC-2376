#include <iostream>
#include <vector>
#include <random>
using namespace std;

// Player template
struct Player
{
	std::string Name;
	int strength{};
	int health{};
};

//  Displays character name
void nameCharacter(Player& player) {
	std::cout << "Name: " << player.Name << std::endl;
}
// Displays character strength
void displayStrength(Player& player) {
	std::cout << "Strength: " << player.strength<< std::endl;
}

void displayHealth(Player& player) {
	std::cout << "Health: " << player.health << std::endl;
}

int main()
{
	//Engine, Player, and Monster setup

	std::random_device seed;
	std::default_random_engine e(seed());
	std::normal_distribution<double> nDist(30.0, 5.0);
	std::uniform_int_distribution<int> uiDist(1, 3);

	int strPlayer = 1 + nDist(e);
	int vitPlayer = 1 + nDist(e);

	int strMonster = 1 + nDist(e);
	int vitMonster = 1 + nDist(e);
	
	std::vector <int> monst;
	monst = { uiDist(e) };
	
	
	
	string customName;

	std::cout << "What is your name" << endl;
	
	std::cin >> customName;

	cout << endl;

	std::cout << "Hello " << customName << endl;
	
	Player Link{ customName , strPlayer, vitPlayer};
	cout << endl << "Here is your profile: " << endl;
	nameCharacter(Link);
	displayHealth(Link);
	displayStrength(Link);

	cout << monst.size();

	//Game Start



	
	
	
}
