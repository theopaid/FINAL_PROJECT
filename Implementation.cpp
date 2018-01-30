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

//Class Living
    Living::Living(string _name, int _level, int _healthPower)
        : name(_name), level(_level), healthPower(_healthPower) {}

    string Living::get_name() const{
        return name;
    }
    
	Living::~Living() {}
	
//Class Hero
	Hero::Hero(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience)
        : Living(_name, _level, _healthPower), magicPower(_magicPower), strength(_strength), dexterity(_dexterity), agility(_agility), money(_money), experience(_experience) {}
    
    float Hero::get_strength() const 
    {
        return strength;
    }
    void Hero::set_strength(float new_strength) 
    {
        strength = new_strength;
    }
    float Hero::get_agility() const
    {
        return agility;
    }
    void Hero::set_agility(float new_agility)  
    {
        agility = new_agility;
    } 
    float Hero::get_dexterity() const
    {
        return dexterity;
    }
    void Hero::set_dexterity(float new_dexterity) 
    {
        dexterity = new_dexterity;
    }

    Hero::~Hero() {}

//Class Sorcerer
Sorcerer::Sorcerer(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience)
        : Hero(_name, _level, _healthPower, _magicPower, _strength, _dexterity, _agility, _money, _experience)
    {
        Hero::set_dexterity(Hero::get_dexterity() * (1 + dexterity_boost));
        Hero::set_agility(Hero::get_agility() * (1 + agility_boost));
    }
    void Sorcerer::LevelUp()
    {
        strength = strength + strength * (5.0 / 100.0);
        agility = agility + agility * (10.0 / 100.0);
        dexterity = dexterity + dexterity * (15.0 / 100.0);
    }

    Sorcerer::~Sorcerer() {}
    
//Class Paladin
	Paladin::Paladin(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience)
        : Hero(_name, _level, _healthPower, _magicPower, _strength, _dexterity, _agility, _money, _experience)
    {
        Hero::set_strength(Hero::get_strength() * (1 + strength_boost));
        Hero::set_dexterity(Hero::get_dexterity() * (1 + dexterity_boost));
    }
    void Paladin::LevelUp()
    {
        strength = strength + strength * (15.0 / 100.0);
        agility = agility + agility * (5.0 / 100.0);
        dexterity = dexterity + dexterity * (10.0 / 100.0);
    }

    Paladin::~Paladin() {}

//Class Monster
	Monster::Monster(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility)
        : Living(_name, _level, _healthPower), damage_var(_damage_var), defense(_defense), dodge_possibility(_dodge_possibility) {}
    int Monster::get_damage_var() const 
    {
        return damage_var;
    }
    void Monster::set_damage_var(int new_dmgvar)
    {
        damage_var = new_dmgvar;
    }
    int Monster::get_defense() const 
    {
        return defense;
    }
    void Monster::set_defense(int new_defence) 
    {
        defense = new_defence;
    }
    float Monster::get_dodge_possibility() const
    {
        return dodge_possibility;
    }
    void Monster::set_dodge_possibility(float new_dodgepos)
    {
        dodge_possibility = new_dodgepos;
    }

    Monster::~Monster() {}

//Class Dragon
    Dragon::Dragon(string _name, int _level, int _healthPower, int _damage_var, int _defense, int _dodge_possibility)
        : Monster(_name, _level, _healthPower, _damage_var, _defense, _dodge_possibility)
    {
        Monster::set_damage_var(Monster::get_damage_var() * (1 + dmg_var_boost));
    }

    Dragon::~Dragon() {}


//Class Exoskeleton
    Exoskeleton::Exoskeleton(string _name, int _level, int _healthPower, int _damage_var, int _defense, int _dodge_possibility)
        : Monster(_name, _level, _healthPower, _damage_var, _defense, _dodge_possibility)
    {
        Monster::set_defense(Monster::get_defense() * (1 + defense_boost));
    }

    Exoskeleton::~Exoskeleton() {}

//Class Spirit
    Spirit::Spirit(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility)
        : Monster(_name, _level, _healthPower, _damage_var, _defense, _dodge_possibility)
    {
        Monster::set_dodge_possibility(Monster::get_dodge_possibility() * (1 + dodge_pos_boost));
    }

    Spirit::~Spirit() {}

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
