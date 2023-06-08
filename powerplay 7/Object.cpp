#include <random>
#include <iostream>
#include "Object.h"
std::random_device Object::seed;
std::default_random_engine Object::engine(seed());

Object::Object(Type name, int strength, int health, int level) : name{ name }, strength{ strength }, health{ health }, level{ level }
{
}


int Object::damageDone(int modification) const
{
	Object::objectName = true;
	std::normal_distribution<double> dmgInflict(strength + modification, 2.0);
	std::cout << *this << " damage dealt";
	return std::max(1, (int)dmgInflict(engine));
}

int Object::damageTaken(int damageDone, int AC)
{
	Object::objectName = true;
	std::normal_distribution<double> defend(AC, 1.0 / level);
	damageDone = std::max(0, damageDone - (int)defend(engine));

	std::cout << damageDone << " damaged inflicted to ";
	std::cout << *this << std::endl;
	
	health -= damageDone;
	return damageDone;
	
}


bool Object::isDead()
{
	return health <= 0;
}

Object::Type Object::getName() const
{
	return name;
}

int Object::getLevel() const
{
	return level;
}

int Object::getHealth() const
{
	return health;
}

std::ostream& operator<<(std::ostream& o, const Object& src)
{
	o << "L:" << src.getLevel() << " ";
	switch (src.getName())
	{
	case Object::Type::player:
		std::cout << "Player";
		break;
	case Object::Type::slime:
		std::cout << "Slime";
		break;
	case Object::Type::orc:
		std::cout << "Orc";
		break;
	case Object::Type::sprite:
		std::cout << "Sprite";
		break;
	case Object::Type::dragon:
		std::cout << "Dragon";
		break;
	}
	o << " h:" << src.getHealth();
	return o;
}
