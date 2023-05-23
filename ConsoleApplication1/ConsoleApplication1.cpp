#include <iostream>
#include <vector>
#include <random>
using namespace std;

int main()
{
	random_device seed;
	default_random_engine e(seed());
	std::normal_distribution<double> nDist(30.0, 5.0);

	double x = nDist(e);

	cout << x;
	

	struct Player
	{
		std::string Link;
		double strength{ 0 };
		int health{ 0 };
	};
}
