#ifndef PLAYER_H
#define PLAYER_H


#include "Object.h"
#include "Item.h"
class Player :
	public Object
{
public:
	Player();

	void levelUp();
	void update(std::vector<Object*> objects) override;

	int getLevel() const;
	int getSP() const;

	int attack() const override;
	void defend(int damage) override;
	void print(std::ostream& o) const override;	
	void heal();


private:
	//edit pointer 
	std::map<Item::Type, std::unique_ptr<Item>>inventory ;
	int SP{ 0 };
};
//edited operator overload
std::ostream& operator<< (std::ostream& o, const std::map<Item::Type, std::unique_ptr<Item*>>& src);
#endif // !PLAYER_H