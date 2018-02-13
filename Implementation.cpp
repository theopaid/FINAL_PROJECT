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

/*void StrengthPotion::use_the_potion(Hero& my_hero)
{
    my_hero.add_boost_to_strength(boost);
}*/

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

/*void DexterityPotion::use_the_potion(Hero& my_hero)
{
    my_hero.add_boost_to_strength(boost);
}*/

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

Spell::~Spell() {}

// Class IceSpell
IceSpell::IceSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dmg_var_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), dmg_var_reduction(_dmg_var_reduction)
{
    Spell::set_type(ice_spell);
}

int IceSpell::spell_poisoning() {
    return dmg_var_reduction;
}

IceSpell::~IceSpell() {}

// Class FireSpell
FireSpell::FireSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _armor_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), armor_reduction(_armor_reduction)
{
    Spell::set_type(fire_spell);
}

int FireSpell::spell_poisoning() {
    return armor_reduction;
}

FireSpell::~FireSpell() {}

// Class LightingSpell
LightingSpell::LightingSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dodge_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), dodge_reduction(_dodge_reduction)
{
    Spell::set_type(lighting_spell);
}

int LightingSpell::spell_poisoning() {
    return dodge_reduction;
}

LightingSpell::~LightingSpell() {}

//Class Living
Living::Living(string _name, int _level, int _healthPower)
    : name(_name), level(_level), healthPower(_healthPower) {}

string Living::get_name() const
{
    return name;
}
int Living::get_Level() const
{
    return level;
}

void Living::set_level(int _lvl)
{
    level = _lvl;
}

int Living::get_HP()
{
    return healthPower;
}

void Living::set_HP(int _hp)
{
    healthPower = _hp;
}

Living::~Living() {}

//Class Hero
Hero::Hero(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience)
    : Living(_name, _level, _healthPower), magicPower(_magicPower), strength(_strength), dexterity(_dexterity), agility(_agility), money(_money), experience(_experience)
{
    my_equipment.hand1 = NULL;
    my_equipment.hand2 = NULL;
    my_equipment.armor = NULL;
}

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
bool Hero::add_inventoryItem(Item *my_item)
{
    for (int i = 0; i < inventory_items.size(); i++)
    {
        if (inventory_items[i]->getName() == my_item->getName())
        {
            delete my_item;
            cout << "This item is already in your inventory!" << endl;
            return false;
        }
    }
    inventory_items.push_back(my_item);
    return true;
}
bool Hero::add_inventorySpell(Spell *my_spell)
{
    for (int i = 0; i < inventory_spells.size(); i++)
    {
        if (inventory_spells[i]->getName() == my_spell->getName())
        {
            delete my_spell;
            cout << "You already own this Spell!" << endl;
            return false;
        }
    }
    inventory_spells.push_back(my_spell);
    return true;
}
void Hero::remove_inventoryItem()
{
    if (inventory_items.size() == 0)
    {
        cout << "There are no items in " << getName() << "'s inventory!" << endl;
        return;
    }
    show_inventory();
    string item_name;
    bool sold = false;
    int money;
    while (!sold)
    {
        cout << endl
             << "Type the name of the item you want to sell:";
        cin >> item_name;
        cout << endl;
        for (int i = 0; i < inventory_items.size(); i++)
        {
            if (item_name == inventory_items[i]->getName())
            {
                money = inventory_items[i]->getPrice() / 2;
                setMoney(getMoney() + inventory_items[i]->getPrice() / 2);
                if (inventory_items[i] == my_equipment.hand1)
                    my_equipment.hand1 = NULL;
                if (inventory_items[i] == my_equipment.hand2)
                    my_equipment.hand2 = NULL;
                if (inventory_items[i] == my_equipment.armor)
                    my_equipment.armor = NULL;
                delete inventory_items[i];
                inventory_items.erase(inventory_items.begin() + i);
                cout << item_name << " has been sold for " << money << " rubles." << endl;
                sold = true;
                break;
            }
        }
        if (!sold)
            cout << "The name of the item is not listed. Please TRY AGAIN" << endl;
    }
}
void Hero::show_inventory()
{
    string type;
    cout << endl
         << "Here are " << getName() << "'s inventory items:" << endl;
    cout << "    NAME    |    TYPE     " << endl;
    for (int i = 0; i < inventory_items.size(); i++)
    {
        switch (inventory_items[i]->get_type())
        {
        case 0:
            type = "Weapon";
            break;
        case 1:
            type = "Armor";
            break;
        case 2:
            type = "Strength Potion";
            break;
        case 3:
            type = "Dexterity Potion";
            break;
        case 4:
            type = "Agility Potion";
            break;
        }
        cout << inventory_items[i]->getName() << "   |    " << type << endl;
    }
}

void Hero::show_spells()
{
    string type;
    cout << endl
         << "Here are " << getName() << "'s owned Spells:" << endl;
    cout << "    NAME    |    TYPE     " << endl;
    for (int i = 0; i < inventory_spells.size(); i++)
    {
        switch (inventory_spells[i]->get_type())
        {
        case 5:
            type = "Ice Spell";
            break;
        case 6:
            type = "Fire Spell";
            break;
        case 7:
            type = "Lighting Spell";
            break;
        }
        cout << inventory_spells[i]->getName() << "   |    " << type << endl;
    }
}

int Hero::getMoney() const
{
    return money;
}
void Hero::setMoney(int _money)
{
    money = _money;
}
int Hero::getLevel() const
{
    return Living::get_Level();
}

string Hero::getName() const
{
    return Living::get_name();
}

int Hero::getHP()
{
    return Living::get_HP();
}

void Hero::setHP(int _hp)
{
    Living::set_HP(_hp);
}

int Hero::getMP()
{
    return magicPower;
}

void Hero::setMP(int _mp)
{
    magicPower = _mp;
}

int Hero::getEXP()
{
    return experience;
}

void Hero::setEXP(int _xp)
{
    experience = _xp;
}

vector<Item *> Hero::getInventory()
{
    return inventory_items;
}

vector<Spell *> Hero::getOwnedSpells()
{
    return inventory_spells;
}

void Hero::displayStats()
{
    cout << getName() << "'s Stats:" << endl
         << "Health Power : " << getHP() << endl
         << "Magic Power : " << magicPower << endl
         << "Strength : " << int(strength * 100) << " %" << endl
         << "Dexterity : " << int(dexterity * 100) << " %" << endl
         << "Agility : " << int(agility * 100) << " %" << endl
         << "Money balance : " << getMoney() << " rubles" << endl
         << "Level : " << getLevel() << endl
         << "Experience : " << experience << endl
         << endl
         << endl;
}

void Hero::displayEquipment()
{
    cout << getName() << "'s Equipment :" << endl;
    if (my_equipment.hand1 == NULL)
        cout << "Left hand : Nothing Equipped" << endl;

    else
        cout << "Left hand : " << my_equipment.hand1->getName() << endl;

    if (my_equipment.hand2 == NULL)
        cout << "Right hand : Nothing Equipped" << endl;

    else
        cout << "Right hand : " << my_equipment.hand2->getName() << endl;

    if (my_equipment.armor == NULL)
        cout << "Armor : Nothing Equipped" << endl;

    else
        cout << "Armor : " << my_equipment.armor->getName() << endl;
}

void Hero::Equip()
{
    if (inventory_items.size() == 0)
    {
        cout << "There are no items in " << getName() << "'s inventory!" << endl;
        return;
    }
    bool itemflag = false;
    for (int i = 0; i < inventory_items.size(); i++)
    {
        if (inventory_items[i]->get_type() == 0 || inventory_items[i]->get_type() == 1)
        {
            itemflag = true;
            break;
        }
    }
    if (!itemflag)
    {
        cout << "There are no Weapons or Armors in your Inventory" << endl;
        return;
    }
    show_inventory();
    string item_name;
    bool equipped = false;
    int money;
    while (!equipped)
    {
        cout << endl
             << "Type the name of the item you want to equip:";
        cin >> item_name;
        cout << endl;
        for (int i = 0; i < inventory_items.size(); i++)
        {
            if (item_name == inventory_items[i]->getName())
            {
                if (inventory_items[i]->get_type() == 0)
                { // Weapon
                    if (inventory_items[i]->getHands() == 2)
                    {
                        my_equipment.hand1 = inventory_items[i];
                        my_equipment.hand2 = inventory_items[i];
                        cout << inventory_items[i]->getName() << " has been equipped to both " << getName() << "'s hands" << endl;
                    }
                    if (inventory_items[i]->getHands() == 1)
                    {
                        if (inventory_items[i] == my_equipment.hand1 || inventory_items[i] == my_equipment.hand1)
                        {
                            cout << "This Item is already equipped!" << endl;
                            return;
                        }
                        string hand_input;
                        while (true)
                        {
                            cout << "In which hand do you want " << inventory_items[i]->getName() << " to be equipped. left or right? : ";
                            cin >> hand_input;
                            cout << endl;
                            if (hand_input == "left")
                            {
                                my_equipment.hand1 = inventory_items[i];
                                cout << inventory_items[i]->getName() << " has been equipped to " << getName() << "'s left hand" << endl;
                                break;
                            }
                            else if (hand_input == "right")
                            {
                                my_equipment.hand2 = inventory_items[i];
                                cout << inventory_items[i]->getName() << " has been equipped to " << getName() << "'s right hand" << endl;
                                break;
                            }
                            else
                            {
                                cout << "Wrong input. Please TRY AGAIN." << endl;
                            }
                        }
                        cout << endl;
                    }
                }
                else if (inventory_items[i]->get_type() == 1)
                { // Armor
                    my_equipment.armor = inventory_items[i];
                    cout << inventory_items[i]->getName() << " has been equipped to " << getName() << "'s armor" << endl;
                }
                else
                { // Potion
                    cout << "This item is a Potion, therefore it can't be equipped!" << endl;
                }
                equipped = true;
                break;
            }
        }
        if (!equipped)
            cout << "The name of the item is not listed. Please TRY AGAIN" << endl;
    }
}

void Hero::usePotion()
{
    if (inventory_items.size() == 0)
    {
        cout << "There are no items in " << getName() << "'s inventory!" << endl;
        return;
    }
    bool potionflag = false;
    for (int i = 0; i < inventory_items.size(); i++)
    {
        if (inventory_items[i]->get_type() == 2 || inventory_items[i]->get_type() == 3 || inventory_items[i]->get_type() == 4)
        {
            potionflag = true;
            break;
        }
    }
    if (!potionflag)
    {
        cout << "There are no Potions in your Inventory" << endl;
        return;
    }
    show_inventory();
    string item_name;
    bool used = false;
    int money;
    while (!used)
    {
        cout << endl
             << "Type the name of the potion you want to use:";
        cin >> item_name;
        cout << endl;
        for (int i = 0; i < inventory_items.size(); i++)
        {
            if (item_name == inventory_items[i]->getName())
            {
                if (inventory_items[i]->get_type() == 0)
                { // Weapon
                    cout << "This item is a Weapon, therefore in can't be consumed!" << endl;
                }
                else if (inventory_items[i]->get_type() == 1)
                { // Armor
                    cout << "This item is an Armor, therefore in can't be consumed!" << endl;
                }
                else
                { // Potion
                    if (inventory_items[i]->get_type() == 2)
                    {
                        strength = strength * (1 + inventory_items[i]->get_boost());
                        cout << "Hurray! You used all of the Strength Potion." << endl;
                        delete inventory_items[i];
                        inventory_items.erase(inventory_items.begin() + i);
                    }
                    else if (inventory_items[i]->get_type() == 3)
                    {
                        dexterity = dexterity * (1 + inventory_items[i]->get_boost());
                        cout << "Hurray! You used all of the Strength Potion." << endl;
                        delete inventory_items[i];
                        inventory_items.erase(inventory_items.begin() + i);
                    }
                    else if (inventory_items[i]->get_type() == 4)
                    {
                        agility = agility * (1 + inventory_items[i]->get_boost());
                        cout << "Hurray! You used all of the Strength Potion." << endl;
                        delete inventory_items[i];
                        inventory_items.erase(inventory_items.begin() + i);
                    }
                }
                used = true;
                break;
            }
        }
        if (!used)
            cout << "The name of the Potion is not listed. Please TRY AGAIN" << endl;
    }
}

Equipment Hero::getEquipment()
{
    return my_equipment;
}

Hero::~Hero()
{
}

//Class Warrior
Warrior::Warrior(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience)
    : Hero(_name, _level, _healthPower, _magicPower, _strength, _dexterity, _agility, _money, _experience)
{
    Hero::set_strength(Hero::get_strength() * (1 + strength_boost));
    Hero::set_agility(Hero::get_agility() * (1 + agility_boost));
}
void Warrior::LevelUp()
{
    cout << Living::get_name() << " is leveling Up!" << endl;
    strength = strength + strength * (35.0 / 100.0);
    agility = agility + agility * (30.0 / 100.0);
    dexterity = dexterity + dexterity * (25.0 / 100.0);
    set_level(get_Level() + 1);
}
Warrior::~Warrior() {}

//Class Sorcerer
Sorcerer::Sorcerer(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience)
    : Hero(_name, _level, _healthPower, _magicPower, _strength, _dexterity, _agility, _money, _experience)
{
    Hero::set_dexterity(Hero::get_dexterity() * (1 + dexterity_boost));
    Hero::set_agility(Hero::get_agility() * (1 + agility_boost));
}
void Sorcerer::LevelUp()
{
    cout << Living::get_name() << " is leveling Up!" << endl;
    strength = strength + strength * (25.0 / 100.0);
    agility = agility + agility * (30.0 / 100.0);
    dexterity = dexterity + dexterity * (35.0 / 100.0);
    set_level(get_Level() + 1);
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
    cout << Living::get_name() << " is leveling Up!" << endl;
    strength = strength + strength * (35.0 / 100.0);
    agility = agility + agility * (25.0 / 100.0);
    dexterity = dexterity + dexterity * (30.0 / 100.0);
    set_level(get_Level() + 1);
}

Paladin::~Paladin() {}

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

int Monster::get_starting_dmg_var() {
    return starting_dmg_var;
}

void Monster::set_starting_dmg_var(int _value) {
    starting_dmg_var = _value;
}

float Monster::get_starting_defense() {
    return starting_defense;
}

void Monster::set_starting_defense(float _value) {
    starting_defense = _value;
}

float Monster::get_starting_dodge_pos() {
    return starting_dodge_pos;
}

void Monster::set_starting_dodge_pos(float _value) {
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

// Class Grid
Grid::Grid(int _x, int _y, int _heroes_count)
    : x(_x), y(_y), heroes_count(_heroes_count), row(_x, common), my_grid(_y, row)
{
    pos_x = 1;
    pos_y = 1;
    cout << "The map is getting rendered!" << endl;
    createMap(x, y);
    cout << "Now the market is being created!" << endl;
    createMarket();
}

void Grid::createMap(int x, int y)
{
    int my_square;
    ifstream MapFile;
    MapFile.open("map.txt");
    if (!MapFile)
    {
        cerr << "Unable to open file map.txt";
        exit(1);
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            MapFile >> my_square;
            switch (my_square)
            {
            case 2:
                my_grid[i][j] = common;
                break;
            case 1:
                my_grid[i][j] = market;
                break;
            case 0:
                my_grid[i][j] = nonAccessible;
                break;
            }
        }
    }
}

void Grid::displayMap()
{
    cout << "Displaying the Map! :" << endl;
    for (int i = 0; i < x * 2 + 1; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "|";
        for (int j = 0; j < y; j++)
        {
            if (j > 0)
                cout << "-";
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
        cout << "|";
        cout << endl;
    }
    for (int i = 0; i < x * 2 + 1; i++)
        cout << "-";
    cout << endl;
    cout << "Your position is : [ " << pos_x << " , " << pos_y << " ]." << endl;
}

void Grid::move()
{
    int my_move;
    while (true)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl
             << "////////// MOVE //////////" << endl
             << endl;
        displayMap();
        cout << "Here are the options you have : " << endl;
        cout << "1 - Up" << endl;
        cout << "2 - Down" << endl;
        cout << "3 - Right" << endl;
        cout << "4 - Left" << endl;
        cout << "Type your choice and press return : ";
        cin >> my_move;
        cout << endl;
        switch (my_move)
        {
        case 1:
            if ((pos_x - 1) < 1)
            {
                cout << "===> Stay inside the map, please TRY AGAIN <===" << endl;
                continue;
            }
            else if (my_grid[pos_x - 1 - 1][pos_y - 1] == nonAccessible)
            {
                cout << "===> You are trying to move to a non Accessible position, please TRY AGAIN <===" << endl;
                continue;
            }
            pos_x--;
            cout << "Moving complete. Your new position is [ " << pos_x << " , " << pos_y << " ]" << endl;
            break;
        case 2:
            if ((pos_x + 1) > 6)
            {
                cout << "===> Stay inside the map, please TRY AGAIN <===" << endl;
                continue;
            }
            else if (my_grid[pos_x + 1 - 1][pos_y - 1] == nonAccessible)
            {
                cout << "===> You are trying to move to a non Accessible position, please TRY AGAIN <===" << endl;
                continue;
            }
            pos_x++;
            cout << "Moving complete. Your new position is [ " << pos_x << " , " << pos_y << " ]" << endl;
            break;
        case 3:
            if ((pos_y + 1) > 6)
            {
                cout << "===> Stay inside the map, please TRY AGAIN <===" << endl;
                continue;
            }
            else if (my_grid[pos_x - 1][pos_y + 1 - 1] == nonAccessible)
            {
                cout << "===> You are trying to move to a non Accessible position, please TRY AGAIN <===" << endl;
                continue;
            }
            pos_y++;
            cout << "Moving completed. Your new position is [ " << pos_x << " , " << pos_y << " ]" << endl;
            break;
        case 4:
            if ((pos_y - 1) < 1)
            {
                cout << "===> Stay inside the map, please TRY AGAIN <===" << endl;
                continue;
            }
            else if (my_grid[pos_x - 1][pos_y - 1 - 1] == nonAccessible)
            {
                cout << "===> You are trying to move to a non Accessible position, please TRY AGAIN <===" << endl;
                continue;
            }
            pos_y--;
            cout << "Moving completed. Your new position is [ " << pos_x << " , " << pos_y << " ]" << endl;
            break;
        default:
            cout << "===> Your input was wrong, please TRY AGAIN <===" << endl;
            continue;
        }
        break;
    }
    cout << endl;
    if (my_grid[pos_x - 1][pos_y - 1] == 2)
    {
        if (!ChanceToFight())
        {
            cout << "No monsters found at your new position." << endl;
            return;
        }
        else
        {
            Fight();
        }
    }
}

void Grid::createMarket()
{
    // List of Weapons
    ifstream WeaponsFile;
    WeaponsFile.open("weapons.txt");
    if (!WeaponsFile)
    {
        cerr << "Unable to open file weapons.txt";
        exit(1);
    }
    WeaponNode w_struct;
    while (WeaponsFile >> w_struct.name >> w_struct.price >> w_struct.base_level >> w_struct.damage >> w_struct.hands)
        WeaponList.push_back(w_struct);
    WeaponsFile.close();
    // List of Armors
    ifstream ArmorsFile;
    ArmorsFile.open("armors.txt");
    if (!ArmorsFile)
    {
        cerr << "Unable to open file armors.txt";
        exit(1);
    }
    ArmorNode a_struct;
    while (ArmorsFile >> a_struct.name >> a_struct.price >> a_struct.base_level >> a_struct.dmg_reduction)
        ArmorList.push_back(a_struct);
    ArmorsFile.close();
    // List of Potions
    ifstream PotionsFile;
    PotionsFile.open("potions.txt");
    if (!PotionsFile)
    {
        cerr << "Unable to open file potion.txt";
        exit(1);
    }
    PotionsNode p_struct;
    while (PotionsFile >> p_struct.name >> p_struct.price >> p_struct.base_level >> p_struct.boost >> p_struct.type)
        PotionsList.push_back(p_struct);
    PotionsFile.close();
    // List of Spells
    ifstream SpellsFile;
    SpellsFile.open("spells.txt");
    if (!SpellsFile)
    {
        cerr << "Unable to open file spells.txt";
        exit(1);
    }
    SpellsNode s_struct;
    while (SpellsFile >> s_struct.name >> s_struct.price >> s_struct.base_level >> s_struct.dmg_var >> s_struct.mana >> s_struct.reduction >> s_struct.type)
        SpellsList.push_back(s_struct);
    SpellsFile.close();
}

void Grid::show_market()
{
    cout << "/////////////// MARKET ////////////////" << endl
         << endl;
    //Weapons
    int j = 0;
    cout << "Weapons you can BUY: " << endl;
    cout << " Name || Price || Level Requirement || Damage || How many hands " << endl;
    for (list<WeaponNode>::iterator it = WeaponList.begin(); it != WeaponList.end(); ++it)
    {
        j++;
        cout << j << " - " << (*it).name << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).damage << "     ||     " << (*it).hands << endl;
    }
    cout << endl;
    //Armors
    cout << "Armors you can BUY: " << endl;
    cout << " Name || Price || Level Requirement || Damage Reduction " << endl;
    for (list<ArmorNode>::iterator it = ArmorList.begin(); it != ArmorList.end(); ++it)
    {
        j++;
        cout << j << " - " << (*it).name << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).dmg_reduction << " %" << endl;
    }
    cout << endl;
    //Potions
    for (list<PotionsNode>::iterator it = PotionsList.begin(); it != PotionsList.end(); ++it)
    {
        j++;
        if ((*it).type == "strength")
        {
            cout << "Strength Potions you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Strength Boost " << endl;
        }
        if ((*it).type == "dexterity")
        {
            cout << endl;
            cout << "Dexterity Potions you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Dexterity Boost " << endl;
        }
        if ((*it).type == "agility")
        {
            cout << endl;
            cout << "Agility Potions you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Agility Boost " << endl;
        }
        cout << j << " - " << (*it).name << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << int((*it).boost * 100) << " %" << endl;
    }
    cout << endl;
    //Spells
    for (list<SpellsNode>::iterator it = SpellsList.begin(); it != SpellsList.end(); ++it)
    {
        j++;
        if ((*it).type == "ice")
        {
            cout << "Ice Spells you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Base Damage || Mana || Base Damage Reduction " << endl;
        }
        if ((*it).type == "fire")
        {
            cout << endl;
            cout << "Fire Spells you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Base Damage || Mana || Defense Reduction " << endl;
        }
        if ((*it).type == "lighting")
        {
            cout << endl;
            cout << "Lighting Spells you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Base Damage || Mana || Dodge Possibility Reduction " << endl;
        }
        cout << j << " - " << (*it).name << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).dmg_var << "     ||     " << (*it).mana << "     ||     " << (*it).reduction << " %" << endl;
    }
    cout << endl;
}

void Grid::createHero()
{
    int hero_type;
    string hero_name;
    string more_heroes;
    Hero *hero_ptr;
    while (true)
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl
             << "////////// HERO CREATION //////////" << endl
             << endl
             << "Here are the options you have : " << endl
             << "1 - Create a Warrior" << endl
             << "2 - Create a Sorcerer" << endl
             << "3 - Create a Paladin" << endl
             << "Type your choice and press return : ";
        cin >> hero_type;
        cout << endl;
        switch (hero_type)
        {
        case 1:
            cout << "What do you want your Warrior to be called ? : ";
            cin >> hero_name;
            cout << endl;
            hero_ptr = new Warrior(hero_name, 1, 70, 70, 0.2, 0.2, 0.2, 100, 100);
            my_heroes.push_back(hero_ptr);
            break;
        case 2:
            cout << "What do you want your Sorcerer to be called ? : ";
            cin >> hero_name;
            cout << endl;
            hero_ptr = new Sorcerer(hero_name, 1, 70, 70, 0.2, 0.2, 0.2, 100, 100);
            my_heroes.push_back(hero_ptr);
            break;
        case 3:
            cout << "What do you want your Paladin to be called ? : ";
            cin >> hero_name;
            cout << endl;
            hero_ptr = new Paladin(hero_name, 1, 70, 70, 0.2, 0.2, 0.2, 100, 100);
            my_heroes.push_back(hero_ptr);
            break;
        default:
            cout << "==> Your input was wrong, please TRY AGAIN <==" << endl;
            continue;
        }
        cout << hero_name << " has been created." << endl;
        while (true)
        {
            cout << endl
                 << "Do you want to create more Heroes ? (yes|no) : ";
            cin >> more_heroes;
            cout << endl;
            if (more_heroes == "yes")
            {
                if (my_heroes.size() == 3)
                {
                    cout << "Sorry, you can't create any more Heroes :(" << endl;
                    break;
                }
                createHero();
                break;
            }
            else if (more_heroes == "no")
            {
                break;
            }
            else
            {
                cout << "==> Your input was wrong, please TRY AGAIN <==" << endl;
                continue;
            }
        }
        break;
    }
}

void Grid::createMonsters()
{
    int monsters_to_create = rand() % my_heroes.size() + 1;
    int multiplier = 1 + 0.2 * (my_heroes[0]->getLevel() - 1);
    Monster *monster_ptr;
    for (int i = 0; i < monsters_to_create; i++)
    {
        int monster_type = rand() % 3 + 1;
        switch (monster_type)
        {
        case 1:
            monster_ptr = new Dragon("kurios_fwtias", my_heroes[0]->getLevel(), 70 * multiplier, 11, 10 * multiplier, 0.2);
            for (int k = 0; k < my_monsters.size(); k++)
            {
                if (my_monsters[k]->get_name() == "kurios_fwtias")
                {
                    i--;
                    delete monster_ptr;
                    continue;
                }
            }
            cout << "====> A Dragon has been found! <====" << endl;
            my_monsters.push_back(monster_ptr);
            break;
        case 2:
            monster_ptr = new Exoskeleton("kurios_kokkalakias", my_heroes[0]->getLevel(), 70 * multiplier, 11, 10 * multiplier, 0.2);
            for (int k = 0; k < my_monsters.size(); k++)
            {
                if (my_monsters[k]->get_name() == "kurios_kokkalakias")
                {
                    i--;
                    delete monster_ptr;
                    continue;
                }
            }
            cout << "====> An Exoskeleton has been found! <====" << endl;
            my_monsters.push_back(monster_ptr);
            break;
        case 3:
            monster_ptr = new Spirit("kurios_pneumonas", my_heroes[0]->getLevel(), 70 * multiplier, 11, 10 * multiplier, 0.2);
            for (int k = 0; k < my_monsters.size(); k++)
            {
                if (my_monsters[k]->get_name() == "kurios_pneumonas")
                {
                    i--;
                    delete monster_ptr;
                    continue;
                }
            }
            cout << "====> A Spirit has been found! <====" << endl;
            my_monsters.push_back(monster_ptr);
            break;
        }
    }
}

void Grid::Menu()
{
    createHero();
    int input;
    while (true)
    {
        cout << endl
             << "////////// MENU //////////" << endl
             << endl
             << "Here are the options you have : " << endl
             << "1 - Display the Map" << endl
             << "2 - Check the Inventory" << endl
             << "3 - Display the stats of your Hero(s)" << endl
             << "4 - Sell an Item from your Inventory" << endl
             << "5 - Move your Hero(s)" << endl
             << "6 - Buy an item or a spell from the market" << endl
             << "7 - Show the Market" << endl
             << "8 - Equip an item" << endl
             << "9 - Display Equipment" << endl
             << "10 - Quit the Game" << endl
             << "11 - Use a Potion" << endl
             << "12 - Display owned Spells" << endl
             << "Type your choice and press return : ";
        cin >> input;
        cout << endl;
        switch (input)
        {
        case 1:
            displayMap();
            break;
        case 2:
            for (int i = 0; i < my_heroes.size(); i++)
                my_heroes[i]->show_inventory();
            break;
        case 3:
            displayHeroStats();
            break;
        case 4:
            SelltoMarket();
            break;
        case 5:
            move();
            break;
        case 6:
            BuyFromMarket();
            break;
        case 7:
            show_market();
            break;
        case 8:
            HeroToEquip();
            break;
        case 9:
            for (int i = 0; i < my_heroes.size(); i++)
                my_heroes[i]->displayEquipment();
            break;
        case 10:
            cout << "It was fun while it lasted. GGWP :D" << endl;
            exit(0);
        case 11:
            HeroToUsePotion();
            break;
        case 12:
            for (int i = 0; i < my_heroes.size(); i++)
                my_heroes[i]->show_spells();
            break;
        default:
            cout << "Your input was wrong. Please TRY AGAIN." << endl;
            break;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

void Grid::HeroToEquip()
{
    int hero_number = 0;
    if (my_heroes.size() > 1)
    {
        string hero_input;
        bool flag = false;
        while (!flag)
        {
            hero_number = 0;
            cout << "Type the name of the hero you want to equip an Item:";
            cin >> hero_input;
            cout << endl;
            for (int i = 0; i < my_heroes.size(); i++)
            {
                if (hero_input == my_heroes[i]->getName())
                {
                    flag = true;
                    break;
                }
                hero_number++;
            }
            if (flag == false)
                cout << endl
                     << "There is no Hero named this way, please TRY AGAIN" << endl;
        }
    }
    my_heroes[hero_number]->Equip();
}

void Grid::HeroToUsePotion()
{
    int hero_number = 0;
    if (my_heroes.size() > 1)
    {
        string hero_input;
        bool flag = false;
        while (!flag)
        {
            hero_number = 0;
            cout << "Type the name of the hero you want to use a Potion on:";
            cin >> hero_input;
            cout << endl;
            for (int i = 0; i < my_heroes.size(); i++)
            {
                if (hero_input == my_heroes[i]->getName())
                {
                    flag = true;
                    break;
                }
                hero_number++;
            }
            if (flag == false)
                cout << endl
                     << "There is no Hero named this way, please TRY AGAIN" << endl;
        }
    }
    my_heroes[hero_number]->usePotion();
}

void Grid::displayHeroStats()
{
    for (int i = 0; i < my_heroes.size(); i++)
    {
        my_heroes[i]->displayStats();
    }
}

void Grid::displayMonsterStats()
{
    for (int i = 0; i < my_monsters.size(); i++)
    {
        my_monsters[i]->displayStats();
    }
}

void Grid::BuyFromMarket()
{
    if (my_grid[pos_x - 1][pos_y - 1] != 1)
    {
        cout << "You are not at Market position!" << endl;
        return;
    }
    int hero_number = 0;
    if (my_heroes.size() > 1)
    {
        string hero_input;
        bool flag = false;
        while (!flag)
        {
            hero_number = 0;
            cout << "Type the name of the hero you want the transaction to happen:";
            cin >> hero_input;
            cout << endl;
            for (int i = 0; i < my_heroes.size(); i++)
            {
                if (hero_input == my_heroes[i]->getName())
                {
                    flag = true;
                    break;
                }
                hero_number++;
            }
            if (flag == false)
                cout << endl
                     << "There is no Hero named this way, please TRY AGAIN" << endl;
        }
    }
    show_market();
    int input;
    while (true)
    {
        int i;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Select an Item or a Spell you want to buy (type 0 to cancel the transaction) : ";
        if (cin >> input)
        {
            if (input <= 5)
            {
                i = 1;
                for (list<WeaponNode>::iterator it = WeaponList.begin(); it != WeaponList.end(); ++it)
                {
                    if (input == i)
                    {
                        if ((*it).price > my_heroes[hero_number]->getMoney())
                        {
                            cout << endl
                                 << "Sorry you don't have enough rubles for this purchase." << endl;
                            break;
                        }
                        if ((*it).base_level > my_heroes[hero_number]->getLevel())
                        {
                            cout << endl
                                 << "Sorry the required level is higher than yours." << endl;
                            break;
                        }
                        Item *weapon_ptr = new Weapon((*it).name, (*it).price, (*it).base_level, (*it).damage, (*it).hands);
                        //my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                        bool added = my_heroes[hero_number]->add_inventoryItem(weapon_ptr);
                        if (added)
                        {
                            my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                            cout << endl
                                 << (*it).name << " has been added to " << my_heroes[hero_number]->get_name() << "'s inventory." << endl;
                        }
                        break;
                    }
                    i++;
                }
                break;
            }
            else if (input == 0)
            {
                return;
            }
            else if (input <= 10)
            {
                i = 6;
                for (list<ArmorNode>::iterator it = ArmorList.begin(); it != ArmorList.end(); ++it)
                {
                    if (input == i)
                    {
                        if ((*it).price > my_heroes[hero_number]->getMoney())
                        {
                            cout << endl
                                 << "Sorry you don't have enough rubles for this purchase." << endl;
                            break;
                        }
                        if ((*it).base_level > my_heroes[hero_number]->getLevel())
                        {
                            cout << endl
                                 << "Sorry the required level is higher than yours." << endl;
                            break;
                        }
                        Item *armor_ptr = new Armor((*it).name, (*it).price, (*it).base_level, (*it).dmg_reduction);
                        //my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                        bool added = my_heroes[hero_number]->add_inventoryItem(armor_ptr);
                        if (added)
                        {
                            my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                            cout << endl
                                 << (*it).name << " has been added to " << my_heroes[hero_number]->get_name() << "'s inventory." << endl;
                        }
                        break;
                    }
                    i++;
                }
                break;
            }
            else if (input <= 25)
            {
                i = 11;
                for (list<PotionsNode>::iterator it = PotionsList.begin(); it != PotionsList.end(); ++it)
                {
                    if (input == i)
                    {
                        if ((*it).price > my_heroes[hero_number]->getMoney())
                        {
                            cout << endl
                                 << "Sorry you don't have enough money for this purchase." << endl;
                            break;
                        }
                        if ((*it).base_level > my_heroes[hero_number]->getLevel())
                        {
                            cout << endl
                                 << "Sorry the required level is higher than yours." << endl;
                            break;
                        }
                        Item *potion_ptr;
                        if ((*it).type == "strength" or (*it).type == "//strength")
                            potion_ptr = new StrengthPotion((*it).name, (*it).price, (*it).base_level, (*it).boost);
                        else if ((*it).type == "dexterity" or (*it).type == "//dexterity")
                            potion_ptr = new DexterityPotion((*it).name, (*it).price, (*it).base_level, (*it).boost);
                        else
                            potion_ptr = new AgilityPotion((*it).name, (*it).price, (*it).base_level, (*it).boost);
                        //my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                        bool added = my_heroes[hero_number]->add_inventoryItem(potion_ptr);
                        if (added)
                        {
                            my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                            cout << endl
                                 << (*it).name << " has been added to " << my_heroes[hero_number]->get_name() << "'s inventory." << endl;
                        }
                        break;
                    }
                    i++;
                }
                break;
            }
            else if (input <= 40)
            {
                i = 26;
                for (list<SpellsNode>::iterator it = SpellsList.begin(); it != SpellsList.end(); ++it)
                {
                    if (input == i)
                    {
                        if ((*it).price > my_heroes[hero_number]->getMoney())
                        {
                            cout << endl
                                 << "Sorry you don't have enough money for this purchase." << endl;
                            break;
                        }
                        if ((*it).base_level > my_heroes[hero_number]->getLevel())
                        {
                            cout << endl
                                 << "Sorry the required level is higher than yours." << endl;
                            break;
                        }
                        Spell *spell_ptr;
                        if ((*it).type == "ice" or (*it).type == "//ice")
                            spell_ptr = new IceSpell((*it).name, (*it).price, (*it).base_level, (*it).dmg_var, (*it).mana, (*it).reduction);
                        else if ((*it).type == "fire" or (*it).type == "//fire")
                            spell_ptr = new FireSpell((*it).name, (*it).price, (*it).base_level, (*it).dmg_var, (*it).mana, (*it).reduction);
                        else
                            spell_ptr = new LightingSpell((*it).name, (*it).price, (*it).base_level, (*it).dmg_var, (*it).mana, (*it).reduction);
                        //my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                        bool added = my_heroes[hero_number]->add_inventorySpell(spell_ptr);
                        if (added)
                        {
                            my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                            cout << endl
                                 << (*it).name << " has been added to " << my_heroes[hero_number]->get_name() << "'s Spells List." << endl;
                        }
                        break;
                    }
                    i++;
                }
                break;
            }
            else
            {
                cout << "This Item or Spell is not listed on the Market. Please TRY AGAIN." << endl;
                continue;
            }
        }
        cout << "Your input was wrong. Please TRY AGAIN." << endl;
    }
}

void Grid::SelltoMarket()
{
    if (my_grid[pos_x - 1][pos_y - 1] != 1)
    {
        cout << "You are not at Market position!" << endl;
        return;
    }
    int hero_number = 0;
    if (my_heroes.size() > 1)
    {
        string hero_input;
        bool flag = false;
        while (!flag)
        {
            hero_number = 0;
            cout << "Type the name of the hero you want the transaction to happen:";
            cin >> hero_input;
            cout << endl;
            for (int i = 0; i < my_heroes.size(); i++)
            {
                if (hero_input == my_heroes[i]->getName())
                {
                    flag = true;
                    break;
                }
                hero_number++;
            }
            if (flag == false)
                cout << endl
                     << "There is no Hero named this way, please TRY AGAIN" << endl;
        }
    }
    my_heroes[hero_number]->remove_inventoryItem();
}

bool Grid::ChanceToFight()
{
    int chance = rand() % 100 + 1;
    if (chance <= 35)
        return true;
    else
        return false;
}

void Grid::FightMenu(Hero *hero_ptr)
{
    int input;
    while (true)
    {
        cout << endl
             << "////////// FIGHT MENU //////////" << endl
             << endl
             << "=====> Playing with " << hero_ptr->get_name() << " <=====" << endl
             << endl
             << "Here are the options you have : " << endl
             << "1 - Display the Map" << endl
             << "2 - Check the Inventory" << endl
             << "3 - Display the stats of your Hero(s) and the Monsters" << endl
             << "4 - Attack" << endl
             << "5 - Cast Spell" << endl
             << "6 - Use a Potion" << endl
             << "7 - Equip an item" << endl
             << "8 - Display Equipment" << endl
             << "9 - Display owned Spells" << endl
             << "10 - Quit the Game" << endl
             << "Type your choice and press return : ";
        cin >> input;
        cout << endl;
        switch (input)
        {
        case 1:
            displayMap();
            continue;
        case 2:
            hero_ptr->show_inventory();
            continue;
        case 3:
            displayHeroStats();
            displayMonsterStats();
            continue;
        case 4:
            Attack(hero_ptr);
            break;
        case 5:
            if(hero_ptr->getOwnedSpells().size() > 0)
                castSpell(hero_ptr);
            else {
                cout << "You do not own any Spells!" << endl;
                continue;
            }
            break;
        case 6:
        {
            bool potion_flag = false;
            for (int i = 0; i<hero_ptr->getInventory().size(); i++)
            {
                if (hero_ptr->getInventory()[i]->get_type() != weapon && hero_ptr->getInventory()[i]->get_type() != armor)
                {
                    hero_ptr->usePotion();
                    potion_flag = true;
                    break;
                }
            }
            if(!potion_flag) {
                cout << "You have no potion in your inventory!" << endl;
                continue;
            }
        }
        case 7:
            hero_ptr->Equip();
            break;
        case 8:
            hero_ptr->displayEquipment();
            continue;
        case 9:
            hero_ptr->show_spells();
            continue;
        case 10:
            cout << "It was fun while it lasted. GGWP :D" << endl;
            exit(0);
        default:
            cout << "Your input was wrong. Please TRY AGAIN." << endl;
            break;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        break;
    }
}

void Grid::castSpell(Hero *hero_ptr)
{

    int monster_number = 0;
    if (my_monsters.size() > 1)
    {
        string monster_input;
        bool flag = false;
        cout << "Here are the monsters you can attack:" << endl;
        for (int k = 0; k < my_monsters.size(); k++)
            cout << my_monsters[k]->get_name() << endl;
        while (!flag)
        {
            monster_number = 0;
            cout << "Type the name of the Monster you want to Attack:";
            cin >> monster_input;
            cout << endl;
            for (int i = 0; i < my_monsters.size(); i++)
            {
                if (monster_input == my_monsters[i]->get_name() && my_monsters[i]->get_HP() > 0)
                {
                    flag = true;
                    break;
                }
                monster_number++;
            }
            if (flag == false)
                cout << endl
                     << "There is no Monster alive named this way, please TRY AGAIN" << endl;
        }
    }
    hero_ptr->show_spells();
    Spell *selected_spell;
    string spell_input;
    bool spell_found = false;
    while (!spell_found)
    {
        cout << "Type the name of the Spell you want to cast: ";
        cin >> spell_input;
        cout << endl;
        for (int i = 0; i < hero_ptr->getOwnedSpells().size(); i++)
        {
            if (spell_input == hero_ptr->getOwnedSpells()[i]->getName())
            {
                spell_found = true;
                selected_spell = hero_ptr->getOwnedSpells()[i];
                break;
            }
        }
        if (!spell_found)
        {
            cout << "There is no listed Spell named this way. Please TRY AGAIN." << endl;
        }
    }
    int mana_spent = selected_spell->get_mana();
    hero_ptr->setMP(hero_ptr->getMP() - mana_spent);
    int damage = 0;
    //int onLighting_reduction = 1;
    //if(my_monsters[monster_number]->get_onLighting() > 0)
     //   onLighting_reduction = 2;
    if (!((rand() % 100 + 1) <= my_monsters[monster_number]->get_dodge_possibility() * 100.0 ))
    {
        damage = (selected_spell->get_dmg_var() + (rand() % 16)) * (1 + hero_ptr->get_dexterity());
        //if (my_monsters[monster_number]->get_onFire() > 0)
        //    damage = damage - damage * float(my_monsters[monster_number]->get_defense()) * 0.025;
        //else
        damage = damage - damage * float(my_monsters[monster_number]->get_defense()) / 100.0;
        my_monsters[monster_number]->set_HP(my_monsters[monster_number]->get_HP() - damage);
        cout << "====>" << hero_ptr->get_name() << " damaged " << my_monsters[monster_number]->get_name() << " for " << damage << " hit points" << endl;
        if (my_monsters[monster_number]->get_HP() < 0)
            my_monsters[monster_number]->set_HP(0);

        switch (selected_spell->get_type())
        {
        case 5:
            cout << "===> " << hero_ptr->getName() << " reduced the damage width of " << my_monsters[monster_number]->get_name() << " for 3 rounds" << endl;
            my_monsters[monster_number]->set_onIce(3); // Affected for 3 rounds
            my_monsters[monster_number]->set_damage_var(my_monsters[monster_number]->get_damage_var() - my_monsters[monster_number]->get_damage_var() * float(selected_spell->spell_poisoning()) / 100.0);
            break;
        case 6:
            cout << "===> " << hero_ptr->getName() << " reduced the defense of " << my_monsters[monster_number]->get_name() << " for 3 rounds" << endl;
            my_monsters[monster_number]->set_onFire(3);
            my_monsters[monster_number]->set_defense(my_monsters[monster_number]->get_defense() - my_monsters[monster_number]->get_defense() * float(selected_spell->spell_poisoning()) / 100.0);
            break;
        case 7:
            cout << "===> " << hero_ptr->getName() << " reduced the dodge possibility of " << my_monsters[monster_number]->get_name() << " for 3 rounds" << endl;
            my_monsters[monster_number]->set_onLIghting(3);
            my_monsters[monster_number]->set_dodge_possibility(my_monsters[monster_number]->get_dodge_possibility() - my_monsters[monster_number]->get_dodge_possibility() * float(selected_spell->spell_poisoning()) / 100.0);
            break;
        }
        if (my_monsters[monster_number]->get_HP() == 0)
            cout << "===> " << my_monsters[monster_number]->get_name() << " is dead" << endl;
    }
    else
        cout << "====> " << hero_ptr->get_name() << "'s attack was dodged by " << my_monsters[monster_number]->get_name() << endl;
}

void Grid::Attack(Hero *hero_ptr)
{
    int monster_number = 0;
    if (my_monsters.size() > 1)
    {
        string monster_input;
        bool flag = false;
        cout << "Here are the monsters you can attack:" << endl;
        for (int k = 0; k < my_monsters.size(); k++)
            cout << my_monsters[k]->get_name() << endl;
        while (!flag)
        {
            monster_number = 0;
            cout << "Type the name of the Monster you want to Attack:";
            cin >> monster_input;
            cout << endl;
            for (int i = 0; i < my_monsters.size(); i++)
            {
                if (monster_input == my_monsters[i]->get_name() && my_monsters[i]->get_HP() > 0)
                {
                    flag = true;
                    break;
                }
                monster_number++;
            }
            if (flag == false)
                cout << endl
                     << "There is no Monster alive named this way, please TRY AGAIN" << endl;
        }
    }
    int damage;
    int onLighting_reduction = 1;
    //if(my_monsters[monster_number]->get_onLighting() > 0)
     //   onLighting_reduction = 2;
    if (!((rand() % 100 + 1) <= my_monsters[monster_number]->get_dodge_possibility() * 100.0 ))
    {
        if (hero_ptr->getEquipment().hand1 != NULL && hero_ptr->getEquipment().hand2 != NULL)
            damage = (1 + hero_ptr->get_strength()) * (hero_ptr->getEquipment().hand1->get_dmg() + hero_ptr->getEquipment().hand2->get_dmg());
        else if (hero_ptr->getEquipment().hand1 != NULL && hero_ptr->getEquipment().hand2 == NULL)
            damage = (1 + hero_ptr->get_strength()) * (hero_ptr->getEquipment().hand1->get_dmg());
        else if (hero_ptr->getEquipment().hand1 == NULL && hero_ptr->getEquipment().hand2 != NULL)
            damage = (1 + hero_ptr->get_strength()) * (hero_ptr->getEquipment().hand2->get_dmg());
        else if (hero_ptr->getEquipment().hand1 == NULL && hero_ptr->getEquipment().hand2 == NULL) // If Hero fights with his fists
            damage = (1 + hero_ptr->get_strength()) * 10;
        //if (my_monsters[monster_number]->get_onFire() < 0)
        //    my_monsters[monster_number]->set_HP(my_monsters[monster_number]->get_HP() - damage + damage * float(my_monsters[monster_number]->get_defense()) * 0.025);
        //else
        my_monsters[monster_number]->set_HP(my_monsters[monster_number]->get_HP() - damage + damage * float(my_monsters[monster_number]->get_defense()) / 100.0);
        cout << "====>" << hero_ptr->get_name() << " damaged " << my_monsters[monster_number]->get_name() << " for " << damage - damage * float(my_monsters[monster_number]->get_defense()) / 100.0 << " hit points" << endl;
        if (my_monsters[monster_number]->get_HP() < 0)
            my_monsters[monster_number]->set_HP(0);
        if (my_monsters[monster_number]->get_HP() == 0)
            cout << "===> " << my_monsters[monster_number]->get_name() << " is dead" << endl;
    }
    else
        cout << "====> " << hero_ptr->get_name() << "'s attack was dodged by " << my_monsters[monster_number]->get_name() << endl;
}

void Grid::Fight()
{
    createMonsters();
    bool flag_heroes_win = false;
    bool flag_monsters_win = false;
    int monsters_with_hp_0_counter;
    int heroes_with_hp_0_counter;
    for(int z=0; z<my_monsters.size(); z++) {
        my_monsters[z]->set_starting_dmg_var(my_monsters[z]->get_damage_var());
        my_monsters[z]->set_starting_defense(my_monsters[z]->get_defense());
        my_monsters[z]->set_starting_dodge_pos(my_monsters[z]->get_dodge_possibility());
    }

    while (!(flag_heroes_win || flag_monsters_win))
    {
        for (int i = 0; i < my_heroes.size(); i++)
        {
            if (my_heroes[i]->get_HP() > 0)
            {
                FightMenu(my_heroes[i]);
                monsters_with_hp_0_counter = 0;
                for (int j = 0; j < my_monsters.size(); j++)
                {
                    if (my_monsters[j]->get_HP() == 0)
                        monsters_with_hp_0_counter++;
                }
                if (monsters_with_hp_0_counter == my_monsters.size())
                {
                    flag_heroes_win = true;
                    break;
                }
            }
        }
        if (!flag_heroes_win)
        {
            cout << "Now its the monsters's turn" << endl;
            for (int i = 0; i < my_monsters.size(); i++)
            {
                if (my_monsters[i]->get_HP() > 0)
                {
                    int monster_dmg = my_monsters[i]->get_damage_var() + (rand() % 16);
                    //if (my_monsters[i]->get_onIce() > 0)
                    //    monster_dmg = monster_dmg - 5; // If affected from Ice Spell
                    int which_hero_to_attack;
                    while (true)
                    { // So the monster can't pick a hero with 0 hp to attack
                        which_hero_to_attack = rand() % my_heroes.size();
                        if (my_heroes[which_hero_to_attack]->get_HP() != 0)
                            break;
                    }
                    if (!((rand() % 100 + 1) <= my_heroes[which_hero_to_attack]->get_agility() * 100.0))
                    { // Posibility to dodge the monster attack
                        if (my_heroes[which_hero_to_attack]->getEquipment().armor != NULL)
                            monster_dmg = monster_dmg - float(monster_dmg) * (float(my_heroes[which_hero_to_attack]->getEquipment().armor->get_dmg_red()) / 100.0);
                        my_heroes[which_hero_to_attack]->setHP(my_heroes[which_hero_to_attack]->getHP() - monster_dmg);
                        cout << "====> " << my_monsters[i]->get_name() << " damaged " << my_heroes[which_hero_to_attack]->get_name() << " for " << monster_dmg << " hit points" << endl;
                        if (my_heroes[which_hero_to_attack]->getHP() < 0)
                            my_heroes[which_hero_to_attack]->setHP(0);
                        if (my_heroes[which_hero_to_attack]->getHP() == 0)
                            cout << "===> " << my_heroes[which_hero_to_attack]->get_name() << " is dead" << endl;
                    }
                    else
                        cout << "====> " << my_monsters[i]->get_name() << "'s attack was dodged by " << my_heroes[which_hero_to_attack]->get_name() << endl;
                    heroes_with_hp_0_counter = 0;
                    for (int j = 0; j < my_heroes.size(); j++)
                    {
                        if (my_heroes[j]->getHP() == 0)
                            heroes_with_hp_0_counter++;
                    }
                    if (heroes_with_hp_0_counter == my_heroes.size())
                    {
                        flag_monsters_win = true;
                        break;
                    }
                }
            }
        }
        if (!(flag_heroes_win || flag_monsters_win))
        {
            for (int h = 0; h < my_monsters.size(); h++)
            {
                if (my_monsters[h]->get_onIce() > 0)
                    my_monsters[h]->set_onIce(my_monsters[h]->get_onIce() - 1); // When a round ends, the duration of the poisoning of the spells gets reduced
                else
                    my_monsters[h]->set_damage_var(my_monsters[h]->get_starting_dmg_var());
                if (my_monsters[h]->get_onFire() > 0)
                    my_monsters[h]->set_onFire(my_monsters[h]->get_onFire() - 1);
                else
                    my_monsters[h]->set_defense(my_monsters[h]->get_starting_defense());
                if (my_monsters[h]->get_onLighting() > 0)
                    my_monsters[h]->set_onLIghting(my_monsters[h]->get_onLighting() - 1);
                else
                    my_monsters[h]->set_dodge_possibility(my_monsters[h]->get_starting_dodge_pos());
            }
            cout << "Monsters's turn completed" << endl;
            cout << "Heroes and Monsters are getting healed.." << endl;
            for (int j = 0; j < my_heroes.size(); j++)
            {
                if (my_heroes[j]->getHP() != 0)
                {
                    if (my_heroes[j]->get_HP() < 70)
                        cout << "====> " << my_heroes[j]->get_name() << " restored " << 70 * (0.15) << " health power" << endl;
                    my_heroes[j]->setHP(my_heroes[j]->getHP() + 70 * 0.15);
                    if (my_heroes[j]->getHP() > 70)
                        my_heroes[j]->setHP(70);
                    if (my_heroes[j]->getMP() < 70)
                        cout << "====> " << my_heroes[j]->get_name() << " restored " << 70 * (0.15) << " mana" << endl;
                    my_heroes[j]->setMP(my_heroes[j]->getMP() + 70 * 0.15);
                    if (my_heroes[j]->getMP() > 70)
                        my_heroes[j]->setMP(70);
                }
            }
            int multiplier = 1 + 0.2 * (my_heroes[0]->getLevel() - 1);
            for (int j = 0; j < my_monsters.size(); j++)
            {
                if (my_monsters[j]->get_HP() != 0)
                {
                    if (my_heroes[j]->get_HP() < 70 * multiplier)
                        cout << "====> " << my_monsters[j]->get_name() << " restored " << 70 * multiplier * (0.10) << " health power" << endl;
                    my_monsters[j]->set_HP(my_monsters[j]->get_HP() + 70 * multiplier * (0.10));
                    if (my_monsters[j]->get_HP() > 70 * multiplier)
                        my_monsters[j]->set_HP(70 * multiplier);
                }
            }
        }
        else if (flag_monsters_win)
        {
            cout << "Monsters won!" << endl;
            for (int j = 0; j < my_heroes.size(); j++)
            {
                my_heroes[j]->setMoney(my_heroes[j]->getMoney() / 2);
                my_heroes[j]->setHP(70);
                my_heroes[j]->setMP(70);
            }
        }
        else if (flag_heroes_win)
        {
            cout << "Heroes won!" << endl;
            for (int j = 0; j < my_heroes.size(); j++)
            {
                my_heroes[j]->setMoney(my_heroes[j]->getMoney() + my_heroes[0]->get_Level() * 10 + my_monsters.size() * 5);
                my_heroes[j]->setEXP(my_heroes[j]->getEXP() + 25 * my_monsters.size());
                if (my_heroes[j]->get_HP() == 0)
                {
                    my_heroes[j]->setHP(35);
                    my_heroes[j]->setMP(70);
                }
            }
        }
    }
    cout << "The fight is over" << endl;

    int monsters_counter = my_monsters.size();
    for (int i = 0; i < monsters_counter; i++)
    {
        delete my_monsters[i];
    }
    my_monsters.clear();
    for (int j = 0; j < my_heroes.size(); j++)
    {
        for (int i = 1; i <= 5; i++)
        {
            if ((my_heroes[j]->getEXP()) >= 100 * i && (my_heroes[j]->get_Level() < i))
            {
                my_heroes[j]->LevelUp();
            }
        }
    }
}

Grid::~Grid() {}

void welcome()
{
    string input;
    cout << "Welcome to the game!" << endl;
    while (true)
    {
        cout << "Αre you ready to play? (yes|no) : ";
        cin >> input;
        if (input == "no")
        {
            cout << "Take your time!" << endl;
            exit(0);
        }
        else if (input == "yes")
        {
            cout << endl
                 << "Let's play then!" << endl;
            break;
        }
        else
        {
            cout << "Your input was wrong. Please TRY AGAIN." << endl;
            continue;
        }
    }
}
