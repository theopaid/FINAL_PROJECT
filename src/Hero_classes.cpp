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
    my_equipment.hand1 = NULL; // If there is nothing equipped, we can identify it by seeing that its value is NULL
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

void Hero::remove_inventorySpell()
{
    if (inventory_spells.size() == 0)
    {
        cout << "There are no Spells in " << getName() << "'s inventory!" << endl;
        return;
    }
    show_spells();
    string spell_name;
    bool sold = false;
    int money;
    while (!sold)
    {
        cout << endl
             << "Type the name of the Spell you want to sell:";
        cin >> spell_name;
        cout << endl;
        for (int i = 0; i < inventory_spells.size(); i++)
        {
            if (spell_name == inventory_spells[i]->getName())
            {
                money = inventory_spells[i]->getPrice() / 2;
                setMoney(getMoney() + inventory_spells[i]->getPrice() / 2);
                delete inventory_spells[i];
                inventory_spells.erase(inventory_spells.begin() + i);
                cout << spell_name << " has been sold for " << money << " rubles." << endl;
                sold = true;
                break;
            }
        }
        if (!sold)
            cout << "The name of the Spell is not listed. Please TRY AGAIN" << endl;
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
                        if (inventory_items[i] == my_equipment.hand1 || inventory_items[i] == my_equipment.hand2)
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
    for (int i = 0; i < inventory_items.size(); i++)
    {
        delete inventory_items[i];
    }
    for (int i = 0; i < inventory_spells.size(); i++)
    {
        delete inventory_spells[i];
    }
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