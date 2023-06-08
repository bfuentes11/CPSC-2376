#ifndef MONSTER_H
#define MONSTER_H
#include "Object.h"

class Player;
class Monster :
	public Object
{
public:
	Monster() {};
	Monster(const Player& player);
	//int damage() const;

	void update(const Player& player, const std::vector<Monster>& monsters) override;

	int attack() const override;
	void print(std::ostream& o) const override;
	void defense(int damage) override;
private:
	int AC{ 0 };

};

#endif // !MONSTER_H