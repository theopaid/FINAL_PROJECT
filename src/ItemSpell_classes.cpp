#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <list>
#include <fstream>
#include <climits>
#include "Interface.h"

using namespace std;

// Class Item
Item::Item(string _name, int _price, int _base_level)
    : name(_name), price(_price), base_level(_base_level) {}

TypeOfItem Item::get_type() const
{
    return item_type;
}

void Item::set_type(TypeOfItem _type)
{
    item_type = _type;
}

string Item::getName()
{
    return name;
}

int Item::getPrice()
{
    return price;
}

int Item::get_dmg_red()
{
}

int Item::get_dmg()
{
}

Item::~Item() {}

// Class Weapon
Weapon::Weapon(string _name, int _price, int _base_level, int _damage, int _hands)
    : Item(_name, _price, _base_level), damage(_damage), hands(_hands)
{
    Item::set_type(weapon);
}

int Weapon::getHands()
{
    return hands;
}

float Weapon::get_boost() {}

int Weapon::get_dmg()
{
    return damage;
}

Weapon::~Weapon() {}

// Class Armor
Armor::Armor(string _name, int _price, int _base_level, int _dmg_reduction)
    : Item(_name, _price, _base_level), dmg_reduction(_dmg_reduction)
{
    Item::set_type(armor);
}

int Armor::getHands() {}

float Armor::get_boost() {}

int Armor::get_dmg_red()
{
    return dmg_reduction;
}

Armor::~Armor() {}

// Class StrengthPotion
StrengthPotion::StrengthPotion(string _name, int _price, int _base_level, float _boost)
    : Item(_name, _price, _base_level), boost(_boost)
{
    Item::set_type(strength_potion);
}

float StrengthPotion::get_boost()
{
    return boost;
}

int StrengthPotion::getHands() {}

StrengthPotion::~StrengthPotion() {}

// Class DexterityPotion
DexterityPotion::DexterityPotion(string _name, int _price, int _base_level, float _boost)
    : Item(_name, _price, _base_level), boost(_boost)
{
    Item::set_type(dexterity_potion);
}

float DexterityPotion::get_boost()
{
    return boost;
}

int DexterityPotion::getHands() {}

DexterityPotion::~DexterityPotion() {}

// Class Agility Potion
AgilityPotion::AgilityPotion(string _name, int _price, int _base_level, float _boost)
    : Item(_name, _price, _base_level), boost(_boost)
{
    Item::set_type(agility_potion);
}

float AgilityPotion::get_boost()
{
    return boost;
}

/*void AgilityPotion::use_the_potion(Hero& my_hero)
{
    my_hero.add_boost_to_strength(boost);
}*/

int AgilityPotion::getHands() {}

AgilityPotion::~AgilityPotion() {}

// Class Spell
Spell::Spell(string _name, int _price, int _base_level, int _dmg_var, int _mana)
    : name(_name), price(_price), base_level(_base_level), dmg_var(_dmg_var), mana(_mana) {}

TypeOfItem Spell::get_type() const
{
    return item_type;
}

void Spell::set_type(TypeOfItem _type)
{
    item_type = _type;
}

string Spell::getName()
{
    return name;
}

int Spell::get_dmg_var()
{
    return dmg_var;
}

int Spell::get_mana()
{
    return mana;
}

int Spell::getPrice() {
    return price;
}

Spell::~Spell() {}

// Class IceSpell
IceSpell::IceSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dmg_var_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), dmg_var_reduction(_dmg_var_reduction)
{
    Spell::set_type(ice_spell);
}

int IceSpell::spell_poisoning()
{
    return dmg_var_reduction;
}

IceSpell::~IceSpell() {}

// Class FireSpell
FireSpell::FireSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _armor_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), armor_reduction(_armor_reduction)
{
    Spell::set_type(fire_spell);
}

int FireSpell::spell_poisoning()
{
    return armor_reduction;
}

FireSpell::~FireSpell() {}

// Class LightingSpell
LightingSpell::LightingSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dodge_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), dodge_reduction(_dodge_reduction)
{
    Spell::set_type(lighting_spell);
}

int LightingSpell::spell_poisoning()
{
    return dodge_reduction;
}

LightingSpell::~LightingSpell() {}