#include <iostream>
#include <vector>
#include <random>
using namespace std;

struct Player
{
	std::string Name;
	int strength{ 0 };
	int health{ 0 };
};

int main()
{
	random_device seed;
	default_random_engine e(seed());
	std::normal_distribution<double> nDist(30.0, 5.0);

	double x = nDist(e);

	cout << x;
	
	
	
}
