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

Weapon::~Weapon() {}

// Class Armor
Armor::Armor(string _name, int _price, int _base_level, int _dmg_reduction)
    : Item(_name, _price, _base_level), dmg_reduction(_dmg_reduction)
{
    Item::set_type(armor);
}

int Armor::getHands() {}

float Armor::get_boost() {}

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

Spell::~Spell() {}

// Class IceSpell
IceSpell::IceSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dmg_var_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), dmg_var_reduction(_dmg_var_reduction)
{
    Spell::set_type(ice_spell);
}

IceSpell::~IceSpell() {}

// Class FireSpell
FireSpell::FireSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _armor_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), armor_reduction(_armor_reduction)
{
    Spell::set_type(fire_spell);
}

FireSpell::~FireSpell() {}

// Class LightingSpell
LightingSpell::LightingSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dodge_reduction)
    : Spell(_name, _price, _base_level, _dmg_var, _mana), dodge_reduction(_dodge_reduction)
{
    Spell::set_type(lighting_spell);
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

int Living::get_HP()
{
    return healthPower;
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
void Hero::add_inventoryItem(Item *my_item)
{
    inventory_items.push_back(my_item);
}
void Hero::add_inventorySpell(Spell *my_spell)
{
    inventory_spells.push_back(my_spell);
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
                cout << item_name << " has been sold for " << money << "." << endl;
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

void Hero::displayStats()
{
    cout << getName() << "'s Stats:" << endl
         << "Health Power : " << getHP() << endl
         << "Magic Power : " << magicPower << endl
         << "Strength : " << strength << endl
         << "Dexterity : " << dexterity << endl
         << "Agility : " << agility << endl
         << "Money balance : " << getMoney() << endl
         << "Level : " << getLevel() << endl
         << "Experience : " << experience << endl
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
    for(int i=0; i<inventory_items.size(); i++) {
        if(inventory_items[i]->get_type() == 0 || inventory_items[i]->get_type() == 1) {
            itemflag = true;
            break;
        }
    }
    if(!itemflag) {
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
    for(int i=0; i<inventory_items.size(); i++) {
        if(inventory_items[i]->get_type() == 2 || inventory_items[i]->get_type() == 3 || inventory_items[i]->get_type() == 4) {
            potionflag = true;
            break;
        }
    }
    if(!potionflag) {
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
                    if(inventory_items[i]->get_type() == 2) {
                        strength = strength * (1 + inventory_items[i]->get_boost());
                        cout << "Hurray! You used all of the Strength Potion." << endl;
                        delete inventory_items[i];
                        inventory_items.erase(inventory_items.begin() + i);
                    }
                    else if(inventory_items[i]->get_type() == 3) {
                        dexterity = dexterity * (1 + inventory_items[i]->get_boost());
                        cout << "Hurray! You used all of the Strength Potion." << endl;
                        delete inventory_items[i];
                        inventory_items.erase(inventory_items.begin() + i);
                    }
                    else if(inventory_items[i]->get_type() == 4) {
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
    strength = strength + strength * (15.0 / 100.0);
    agility = agility + agility * (10.0 / 100.0);
    dexterity = dexterity + dexterity * (5.0 / 100.0);
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
    cout << Living::get_name() << " is leveling Up!" << endl;
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
            cout << "Moving complete. Your new position is [ " << pos_x << " , " << pos_y << " ]" << endl;
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
            cout << "Moving complete. Your new position is [ " << pos_x << " , " << pos_y << " ]" << endl;
            break;
        default:
            cout << "===> Your input was wrong, please TRY AGAIN <===" << endl;
            continue;
        }
        break;
    }
    cout << endl;
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
        cout << j << " - " << (*it).name << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).dmg_reduction << endl;
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
        cout << j << " - " << (*it).name << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).boost << endl;
    }
    cout << endl;
    //Spells
    for (list<SpellsNode>::iterator it = SpellsList.begin(); it != SpellsList.end(); ++it)
    {
        j++;
        if ((*it).type == "ice")
        {
            cout << "Ice Spells you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Damage Variety || Mana || Damage Variety Reduction " << endl;
        }
        if ((*it).type == "fire")
        {
            cout << endl;
            cout << "Fire Spells you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Damage Variety || Mana || Armor Reduction " << endl;
        }
        if ((*it).type == "lighting")
        {
            cout << endl;
            cout << "Lighting Spells you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Damage Variety || Mana || Dodge Possibility Reduction " << endl;
        }
        cout << j << " - " << (*it).name << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).dmg_var << "     ||     " << (*it).mana << "     ||     " << (*it).reduction << endl;
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
            hero_ptr = new Warrior(hero_name, 1, 1, 1, 1, 1, 1, 100, 1);
            my_heroes.push_back(hero_ptr);
            break;
        case 2:
            cout << "What do you want your Sorcerer to be called ? : ";
            cin >> hero_name;
            cout << endl;
            hero_ptr = new Sorcerer(hero_name, 1, 1, 1, 1, 1, 1, 100, 1);
            my_heroes.push_back(hero_ptr);
            break;
        case 3:
            cout << "What do you want your Paladin to be called ? : ";
            cin >> hero_name;
            cout << endl;
            hero_ptr = new Paladin(hero_name, 1, 1, 1, 1, 1, 1, 100, 1);
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
        cout << "Select an Item or a Spell you want to buy : ";
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
                                 << "Sorry you don't have enough money for this purchase." << endl;
                            break;
                        }
                        if ((*it).base_level > my_heroes[hero_number]->getLevel())
                        {
                            cout << endl
                                 << "Sorry the required level is higher than yours." << endl;
                            break;
                        }
                        Item *weapon_ptr = new Weapon((*it).name, (*it).price, (*it).base_level, (*it).damage, (*it).hands);
                        my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                        my_heroes[hero_number]->add_inventoryItem(weapon_ptr);
                        cout << endl
                             << (*it).name << " has been added to " << my_heroes[hero_number]->get_name() << "'s inventory." << endl;

                        break;
                    }
                    i++;
                }
                break;
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
                                 << "Sorry you don't have enough money for this purchase." << endl;
                            break;
                        }
                        if ((*it).base_level > my_heroes[hero_number]->getLevel())
                        {
                            cout << endl
                                 << "Sorry the required level is higher than yours." << endl;
                            break;
                        }
                        Item *armor_ptr = new Armor((*it).name, (*it).price, (*it).base_level, (*it).dmg_reduction);
                        my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                        my_heroes[hero_number]->add_inventoryItem(armor_ptr);
                        cout << endl
                             << (*it).name << " has been added to " << my_heroes[hero_number]->get_name() << "'s inventory." << endl;
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
                        my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                        my_heroes[hero_number]->add_inventoryItem(potion_ptr);
                        cout << endl
                             << (*it).name << " has been added to " << my_heroes[hero_number]->get_name() << "'s inventory." << endl;
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
                        my_heroes[hero_number]->setMoney(my_heroes[hero_number]->getMoney() - (*it).price);
                        my_heroes[hero_number]->add_inventorySpell(spell_ptr);
                        cout << endl
                             << (*it).name << " has been added to " << my_heroes[hero_number]->get_name() << "'s inventory." << endl;
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
