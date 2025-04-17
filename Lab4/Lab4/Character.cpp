#include "Character.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Character::attack(Character* aim) {}
void Character::specialAttack(Character* aim) {}

void Character::heal() {
	cout << this->name << " is healing." << endl;
	health += rand() % 3 + 3;
	cout << this->getName() << "'s health: " << health << endl;
}

Character::~Character() {}

void Character::takeDamage(int strength) {
	if (this->getBlessed() == true) {
		cout << this->name << " is blessed. No damage." << endl;
		setBless(false);
	}
	else {
		if (this->getCursed() == true) {
			cout << this->name << " is still cursed. The damage is greater." << endl;
			strength += 2;
		}

		cout << this->name << " is damaged." << endl;
		strength = rand() % 3 + strength;
		health -= strength;
		cout << "Damage: " << strength << endl;
		cout << this->getName() << "'s health: " << health << endl;
	}
}

void Character::setHealth(int health) {
	this->health = health;
}

int Character::getHealth() {
	return health;
}

int Character::getStrength() {
	return strength;
}

string Character::getName() {
	return name;
}

bool Character::getCursed() {
	return cursed;
}

bool Character::getBlessed() {
	return blessed;
}

void Character::setStrength(int strength) {
	this->strength = strength;
}

void Character::setName(string name) {
	this->name = name;
}

void Character::setRace(string race) {
	this->race = race;
}

void Character::showStats() {
	cout << "Name: " << this->name << endl;
	cout << "Race: " << this->race << endl;
	cout << "Health: " << this->health << endl;
	cout << "Strength: " << this->strength << endl;
}

Warrior::Warrior() {
	setHealth(rand() % 6 + 25);
	setStrength(rand() % 4 + 5);
}

Warrior::~Warrior() {};

void Warrior::attack(Character* aim) {
	cout << this->name << " is attacking with a " << this->weapon << "." << endl;
	aim->takeDamage(this->getStrength());
}

void Warrior::setWeapon(string weapon) {
	this->weapon = weapon;
}

Mage::Mage() {
	setHealth(rand() % 6 + 25);
	setStrength(rand() % 4 + 5);
};

Mage::~Mage() {};

void Mage::attack(Character* aim) {
	cout << this->name << " is attacking with " << this->magic << " magic." << endl;
	aim->takeDamage(this->getStrength());
}

void Mage::setMagic(string magic) {
	this->magic = magic;
}

Knight::Knight(string name) {
	setName(name);
	setRace("knight");
	setWeapon("sword");
}

Archer::Archer(string name) {
	setName(name);
	setRace("archer");
	setWeapon("bow");
}

LightMage::LightMage(string name) {
	setName(name);
	setRace("light mage");
	setMagic("light");
}

DarkMage::DarkMage(string name) {
	setName(name);
	setRace("dark mage");
	setMagic("dark");
}

void Knight::specialAttack(Character* aim) {
	cout << this->getName() << " is fending off " << aim->getName() << "'s attack!" << endl;
	aim->takeDamage(2 * aim->getStrength());
}

void Archer::specialAttack(Character* aim) {
	cout << this->getName() << " is sending a deadly arrow!" << endl;
	aim->takeDamage(2 * this->getStrength());
}

void LightMage::specialAttack(Character* aim) {
	this->setBless(true);
	cout << this->getName() << " is blessed!" << endl;
}

void DarkMage::specialAttack(Character* aim) {
	aim->setCurse(true);
	cout << aim->getName() << " is cursed!" << endl;
}

void Character::setCurse(bool value) {
	this->cursed = value;
}

void Character::setBless(bool value) {
	this->blessed = value;
}

Character* createCharacter(int num, string name) {
	Character* player = nullptr;

	if (num == 1) {
		player = new Knight(name);
	}
	else if (num == 2) {
		player = new Archer(name);
	}
	else if (num == 3) {
		player = new LightMage(name);
	}
	else if (num == 4) {
		player = new DarkMage(name);
	}

	return player;
}

void chooseAction(int num, bool& strongAttackUsed, Character* subject, Character* object, bool& invalid) {
	switch (num) {
	case 1:
		subject->attack(object);
		break;
	case 2:
		subject->heal();
		break;
	case 3:
		if (!strongAttackUsed) {
			subject->specialAttack(object);
			strongAttackUsed = true;
			break;
		}
	default:
		invalid = true;
	}
}