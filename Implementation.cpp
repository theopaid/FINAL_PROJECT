#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Interface.h"

using namespace std;

enum square_type
{
    nonAccessible,
    market,
    common
};

enum next_move
{
    up,
    down,
    right_, //right and left are used in std namespace, so using them in this enum, would be ambiguous.
    left_
};

// Class Item
Item::Item(string _name, int _price, int _base_level)
    : name(_name), price(_price), base_level(_base_level) {}

Item::~Item() {}

// Class Weapon
Weapon::Weapon(string _name, int _price, int _base_level, int _damage, int _hands)
    : Item(_name, _price, _base_level), damage(_damage), hands(_hands) {}

Weapon::~Weapon() {}

// Class Armor
Armor::Armor(string _name, int _price, int _base_level, int _dmg_reduction)
    : Item(_name, _price, _base_level), dmg_reduction(_dmg_reduction) {}

Armor::~Armor() {}

// Class StrengthPotion
StrengthPotion::StrengthPotion(string _name, int _price, int _base_level, float _boost)
    : Item(_name, _price, _base_level), boost(_boost) {}

float StrengthPotion::get_boost() const
{
    return boost;
}

void StrengthPotion::use_the_potion(&Hero my_hero)
{
    my_hero.add_boost_to_strength(boost);
}

StrengthPotion::~StrengthPotion()
{
    cout << "Hurray! You used all of the Strength Potion." << endl;
}

// Class DexterityPotion
DexterityPotion::DexterityPotion(string _name, int _price, int _base_level, float _boost)
    : Item(_name, _price, _base_level), boost(_boost) {}

float DexterityPotion::get_boost() const
{
    return boost;
}

void DexterityPotion::use_the_potion(&Hero my_hero)
{
    my_hero.add_boost_to_strength(boost);
}

DexterityPotion::~DexterityPotion()
{
    cout << "Hurray! You used all of the Dexterity Potion." << endl;
}

// Class Agility Potion
AgilityPotion::AgilityPotion(string _name, int _price, int _base_level, float _boost)
    : Item(_name, _price, _base_level), boost(_boost) {}

float AgilityPotion::get_boost() const
{
    return boost;
}

void AgilityPotion::use_the_potion(&Hero my_hero)
{
    my_hero.add_boost_to_strength(boost);
}

AgilityPotion::~AgilityPotion()
{
    cout << "Hurray! You used all of the Agility Potion." << endl;
}

// Class Spell
Spell::Spell(string _name, int _price, int _base_level, int _dmg_var, int _mana)
    : name(_name), price(_price), base_level(_base_level), dmg_var(_dmg_var), mana(_mana) {}

Spell::~Spell() {}

// Class IceSpell
IceSpell::IceSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dmg_var_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), dmg_var_reduction(_dmg_var_reduction) {}

IceSpell::~IceSpell() {}

// Class FireSpell
FireSpell::FireSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _armor_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), armor_reduction(_armor_reduction) {}

FireSpell::~FireSpell() {}

// Class LightingSpell
LightingSpell::LightingSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dodge_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), dodge_reduction(_dodge_reduction) {}

LightingSpell::~LightingSpell() {}

// Class Grid
Grid::Grid(int _x, int _y, int _heroes_count)
    : x(_x), y(_y), heroes_count(_heroes_count), row(_x, common), my_grid(_y, row)
{
    cout << "The map is getting rendered!" << endl;
    //square_type random_sq;
    srand(time(NULL));
    //vector< vector<square_type> > my_vector(x, vector<square_type>(y));
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            my_grid[i][j] = static_cast<square_type>(rand() % 3);
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            switch (my_grid[i][j])
            {
            case nonAccessible:
                cout << "n";
                break;
            case market:
                cout << "m";
                break;
            case common:
                cout << "c";
                break;
            }
        }
        cout << endl;
    }
}

void Grid::move(next_move my_move)
{
    switch (my_move)
    {
    case up:

        break;
    case down:

        break;
    case right_:

        break;
    case left_:

        break;
    }
}

Grid::~Grid() {}