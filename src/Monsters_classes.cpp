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

//Class Monster
Monster::Monster(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility)
    : Living(_name, _level, _healthPower), damage_var(_damage_var), defense(_defense), dodge_possibility(_dodge_possibility)
{
    on_fire = 0;
    on_ice = 0;
    on_lighting = 0;
}

int Monster::get_damage_var() const
{
    return damage_var;
}
void Monster::set_damage_var(int new_dmgvar)
{
    damage_var = new_dmgvar;
}
float Monster::get_defense() const
{
    return defense;
}
void Monster::set_defense(float new_defence)
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

int Monster::get_onFire()
{
    return on_fire;
}

int Monster::get_onIce()
{
    return on_ice;
}

int Monster::get_onLighting()
{
    return on_lighting;
}

void Monster::set_onFire(int _rounds)
{
    on_fire = _rounds;
}

void Monster::set_onIce(int _rounds)
{
    on_ice = _rounds;
}

void Monster::set_onLIghting(int _rounds)
{
    on_lighting = _rounds;
}

int Monster::get_starting_dmg_var()
{
    return starting_dmg_var;
}

void Monster::set_starting_dmg_var(int _value)
{
    starting_dmg_var = _value;
}

float Monster::get_starting_defense()
{
    return starting_defense;
}

void Monster::set_starting_defense(float _value)
{
    starting_defense = _value;
}

float Monster::get_starting_dodge_pos()
{
    return starting_dodge_pos;
}

void Monster::set_starting_dodge_pos(float _value)
{
    starting_dodge_pos = _value;
}

void Monster::displayStats()
{
    cout << get_name() << "'s Stats:" << endl
         << "Health Power : " << get_HP() << endl
         << "Level : " << get_Level() << endl
         << "Damage : " << get_damage_var() << " - " << get_damage_var() + 15 << endl
         << "Defense : " << get_defense() << " %" << endl
         << "Dodge Possibility : " << int(get_dodge_possibility() * 100) << " %" << endl
         << endl;
}

Monster::~Monster() {}

//Class Dragon
Dragon::Dragon(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility)
    : Monster(_name, _level, _healthPower, _damage_var, _defense, _dodge_possibility)
{
    Monster::set_damage_var(Monster::get_damage_var() * (1.0 + float(dmg_var_boost)));
}

Dragon::~Dragon() {}

//Class Exoskeleton
Exoskeleton::Exoskeleton(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility)
    : Monster(_name, _level, _healthPower, _damage_var, _defense, _dodge_possibility)
{
    Monster::set_defense(Monster::get_defense() * (1.0 + float(defense_boost)));
}

Exoskeleton::~Exoskeleton() {}

//Class Spirit
Spirit::Spirit(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility)
    : Monster(_name, _level, _healthPower, _damage_var, _defense, _dodge_possibility)
{
    Monster::set_dodge_possibility(Monster::get_dodge_possibility() * (1 + dodge_pos_boost));
}

Spirit::~Spirit() {}