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

/*void StrengthPotion::use_the_potion(&Hero my_hero)
{
    my_hero.add_boost_to_strength(boost);
}*/

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

/*void DexterityPotion::use_the_potion(&Hero my_hero)
{
    my_hero.add_boost_to_strength(boost);
}*/

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

/*void AgilityPotion::use_the_potion(&Hero my_hero)
{
    my_hero.add_boost_to_strength(boost);
}*/

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

string Living::get_name() const
{
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
    while (PotionsFile >> p_struct.name >> p_struct.price >> p_struct.base_level >> p_struct.boost)
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
    while (SpellsFile >> s_struct.name >> s_struct.price >> s_struct.base_level >> s_struct.dmg_var >> s_struct.mana >> s_struct.reduction)
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
    int i = 0;
    for (list<PotionsNode>::iterator it = PotionsList.begin(); it != PotionsList.end(); ++it)
    {
        j++;
        if (i == 0)
        {
            cout << "Strength Potions you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Strength Boost " << endl;
        }
        if (i == 5)
        {
            cout << endl;
            cout << "Dexterity Potions you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Dexterity Boost " << endl;
        }
        if (i == 10)
        {
            cout << endl;
            cout << "Agility Potions you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Agility Boost " << endl;
        }
        cout << j << " - " << (*it).name << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).boost << endl;
        i++;
    }
    cout << endl;
    //Spells
    i = 0;
    for (list<SpellsNode>::iterator it = SpellsList.begin(); it != SpellsList.end(); ++it)
    {
        j++;
        if (i == 0)
        {
            cout << "Ice Spells you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Damage Variety || Mana || Damage Variety Reduction " << endl;
        }
        if (i == 5)
        {
            cout << "Fire Spells you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Damage Variety || Mana || Armor Reduction " << endl;
        }
        if (i == 10)
        {
            cout << "Lighting Spells you can BUY: " << endl;
            cout << " Name || Price || Level Requirement || Damage Variety || Mana || Dodge Possibility Reduction " << endl;
        }
        cout << j << " - " << (*it).name << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).dmg_var << "     ||     " << (*it).mana << "     ||     " << (*it).reduction << endl;
        i++;
    }
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
             << endl;
        cout << "Here are the options you have : " << endl;
        cout << "1 - Create a Warrior" << endl;
        cout << "2 - Create a Sorcerer" << endl;
        cout << "3 - Create a Paladin" << endl;
        cout << "Type your choice and press return : ";
        cin >> hero_type;
        cout << endl;
        switch (hero_type)
        {
        case 1:
            cout << "What do you want your Warrior to be called ? : ";
            cin >> hero_name;
            cout << endl;
            hero_ptr = new Warrior(hero_name, 1, 1, 1, 1, 1, 1, 1, 1);
            my_heroes.push_back(hero_ptr);
            break;
        case 2:
            cout << "What do you want your Sorcerer to be called ? : ";
            cin >> hero_name;
            cout << endl;
            hero_ptr = new Sorcerer(hero_name, 1, 1, 1, 1, 1, 1, 1, 1);
            my_heroes.push_back(hero_ptr);
            break;
        case 3:
            cout << "What do you want your Paladin to be called ? : ";
            cin >> hero_name;
            cout << endl;
            hero_ptr = new Paladin(hero_name, 1, 1, 1, 1, 1, 1, 1, 1);
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
    int input;
    bool gameOn = true;
    while (gameOn)
    {
        cout << endl
             << "////////// MENU //////////" << endl
             << endl;
        cout << "Here are the options you have : " << endl;
        cout << "1 - Display the Map" << endl;
        cout << "2 - Show the Market" << endl;
        cout << "3 - Buy an item from the market" << endl;
        cout << "4 - Sell an Item from your Inventory" << endl;
        cout << "5 - Move your Hero(s)" << endl;
        cout << "6 - Create your Hero(s)" << endl;
        cout << "10 - Quit the Game" << endl;
        cout << "Type your choice and press return : ";
        cin >> input;
        cout << endl;
        switch (input)
        {
        case 1:
            displayMap();
            break;
        case 2:
            show_market();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            move();
            break;
        case 6:
            createHero();
            break;
        case 10:
            cout << "It was fun while it lasted. GGWP :D" << endl;
            exit(0);
        default:
            cout << "Your input was wrong. Please TRY AGAIN." << endl;
            break;
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
}

Grid::~Grid() {}
