#pragma once
#include <iostream>

using namespace std;

class Character {
protected:
	int health = 0;
	int strength = 0;
	string name;
	string race;

	bool cursed = false;
	bool blessed = false;

	void setName(string name);
	void setRace(string race);
public:
	void setHealth(int health);
	void setStrength(int strength);
	void setCurse(bool value);
	void setBless(bool value);

	int getHealth();
	int getStrength();
	bool getCursed();
	bool getBlessed();
	string getName();

	virtual void attack(Character* aim);
	virtual void specialAttack(Character* aim);

	void takeDamage(int strength);
	void heal();
	void showStats();
};

class Warrior : public Character {
protected:
	string weapon;
	void setWeapon(string weapon);
public:
	Warrior();
	~Warrior();

	void attack(Character* aim) override;
};

class Mage : public Character {
protected:
	string magic;
public:
	Mage();
	~Mage();

	void setMagic(string magic);
	void attack(Character* aim) override;
};

class Knight : public Warrior {
public:
	Knight(string name);
	void specialAttack(Character* aim) override;
};

class Archer : public Warrior {
public:
	Archer(string name);
	void specialAttack(Character* aim) override;
};

class LightMage : public Mage {
public:
	LightMage(string name);
	void specialAttack(Character* aim) override;
};

class DarkMage : public Mage {
public:
	DarkMage(string name);
	void specialAttack(Character* aim) override;
};

Character* createCharacter(int num, string name);
void chooseAction(int num, bool& strongAttackUsed, Character* subject, Character* object, bool& invalid);