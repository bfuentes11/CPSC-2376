#include <random>
#include <iostream>
#include "Player.h"
#include "Monster.h"

Player::Player() :Object(Object::Type::player, 0, 1, 0)
{

}

void Player::update(Player& player, std::vector<Monster>& monsters) {
	//copied from lines 44-60 of pp6.cpp
	std::cout << "What do you do? (a)ttack (h)eal ";
	char command{ 'x' };
	std::cin >> command;
	switch (command)
	{
	case 'a':
	{
		int monsterNum{ 1 };
		if (monsters.size() > 1)
		{
			std::cout << "Which Monster: ";
			std::cin >> monsterNum;
		}
		if (monsterNum > 0 && monsterNum <= monsters.size())
		{

			monsters[monsterNum - 1].defend(player.attack());
		}
		break;
	}
	case 'h':
		player.heal();
		break;
	default:
		std::cout << "please enter a or h" << std::endl;
		break;
	}
}

void Player::print(std::ostream& o) const
{
	if (objectName) Object::print(o);
	else {
		o << "Player L:" << getLevel() << std::endl;
		Object::print(o);
		o << " HP:" << getHealth() << " SP:" << getSP();
	}
}

void Player::levelUp()
{
	level++;
	std::normal_distribution<double> randomHealth(20.0 + level * 5, 5.0);
	health += std::max(1, (int)randomHealth(engine));

	std::normal_distribution<double> randomStrength(3.0 + level, 1.0);
	strength += std::max(1, (int)randomStrength(engine));
	SP += std::max(1, (int)randomStrength(engine));

	//grab new item.
	std::uniform_int_distribution<int> randomItem(0, (int)Item::Type::numTypes - 1);
	std::normal_distribution<double> randomBonus((double)level, (double)level / 2);
	Item found{ (Item::Type)randomItem(engine), std::max(1, (int)randomBonus(engine)) };

	std::cout << "You found a " << found << "!!!!" << std::endl;
	if (
		auto haveOne{ inventory.find(found.getClassification()) };
		haveOne == inventory.end()
		|| inventory[found.getClassification()] < found
		)
	{
		std::cout << "You keep the shiny new toy!" << std::endl;
		inventory[found.getClassification()] = found;
	}
	else
	{
		std::cout << "You toss aside the ugly old thing!" << std::endl;
	}
}

int Player::getLevel() const
{
	return level;
}

int Player::getSP() const
{
	return SP;
}

/*int Player::damage() const
{
	int potentialDamage{ strength };
	if (auto sword{ inventory.find(Item::Type::sword) }; sword != inventory.end())
	{
		potentialDamage += sword->second;
	}
	std::normal_distribution<double> damageDealt(potentialDamage, 2.0);


	std::cout << *this << " deals ";
	return std::max(1, (int)damageDealt(engine));
}
*/

//add attack after damage since attack and dmg are similar or not idk.
int Player::attack() const {
	//searches for sword in inventory
	if (auto sword{ inventory.find(Item::Type::sword) }; sword != inventory.end()){
		return damageDone(sword->second.getBonusValue());
}
	else
	{
		return damageDone(0);
	}
}

std::map<Item::Type, Item> Player::getInventory() const
{
	return inventory;
}

/*void Player::defense(int damage)
{
	int AC{ 0 };
	if (auto armor{ inventory.find(Item::Type::armor) }; armor != inventory.end())
	{
		AC += armor->second;
	}
	if (auto shield{ inventory.find(Item::Type::shield) }; shield != inventory.end())
	{
		AC += shield->second;
	}
	std::normal_distribution<double> defense(AC, 1.0 / level);
	damage = std::max(0, damage - (int)defense(engine));

	std::cout << damage << " damage to ";

	std::cout << *this << "!!!" << std::endl;
	health -= damage;
}
*/


void Player::defend(int damage) {
	int AC{ 0 };
	if (auto armor{ inventory.find(Item::Type::armor) }; armor != inventory.end())
	{
		AC += armor->second;
	}
	if (auto shield{ inventory.find(Item::Type::shield) }; shield != inventory.end())
	{
		AC += shield->second;
	}
	damageTaken(damage, AC);
}

void Player::heal()
{
	if (SP >= 2)
	{
		std::normal_distribution<double> randomHeal(strength, 3.0);
		int  amountHealed{ std::max(1, (int)randomHeal(engine)) };

		SP -= 2;
		std::cout << *this << " is healed by " << amountHealed << "hp!" << std::endl;
		health += amountHealed;
	}
	else
	{
		std::cout << "Not enough SP!!!" << std::endl;
	}
}

/*std::ostream& operator<<(std::ostream& o, const Player& src)
{
	o << (Object)src << ", SP:" << src.getSP();
	return o;
}
*/

std::ostream& operator<<(std::ostream& o, const std::map<Item::Type, Item>& src)
{
	std::for_each(src.begin(), src.end(), [&](std::pair<Item::Type, Item> item)
		{
			o << "  " << item.second << std::endl;
		});
	return o;
}
