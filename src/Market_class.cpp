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

// Class Market
Market::Market()
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

void Market::show_market()
{
    cout << "/////////////// MARKET ////////////////" << endl
         << endl;
    //Weapons
    int j = 0;
    cout << "Weapons you can BUY: " << endl;
    string s = "Name";
    s.resize(13, ' ');
    cout << "         " << s << "|| Price || Level Requirement || Damage || How many hands " << endl;
    for (list<WeaponNode>::iterator it = WeaponList.begin(); it != WeaponList.end(); ++it)
    {
        j++;
        string k = (*it).name;
        k.resize(13, ' ');
        cout << j << " - " << k << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).damage << "     ||     " << (*it).hands << endl;
    }
    cout << endl;
    //Armors
    cout << "Armors you can BUY: " << endl;
    s = "Name";
    s.resize(12, ' ');
    cout << "          " << s << "|| Price || Level Requirement || Damage " << endl;
    for (list<ArmorNode>::iterator it = ArmorList.begin(); it != ArmorList.end(); ++it)
    {
        j++;
        string k = (*it).name;
        if(k == "Aegis_Shield")
            k.resize(12, ' ');
        else
            k.resize(13, ' ');
        cout << j << " - " << k << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).dmg_reduction << " %" << endl;
    }
    cout << endl;
    //Potions
    for (list<PotionsNode>::iterator it = PotionsList.begin(); it != PotionsList.end(); ++it)
    {
        j++;
        if ((*it).type == "strength")
        {
            cout << "Strength Potions you can BUY: " << endl;

            cout << "           " << s << "|| Price || Level Requirement || Strength Boost " << endl;
        }
        if ((*it).type == "dexterity")
        {
            cout << endl;
            cout << "Dexterity Potions you can BUY: " << endl;
            cout << "          " << s << "|| Price || Level Requirement || Dexterity Boost " << endl;
        }
        if ((*it).type == "agility")
        {
            cout << endl;
            cout << "Agility Potions you can BUY: " << endl;
            cout << "          " << s << "|| Price || Level Requirement || Agility Boost " << endl;
        }
        string k = (*it).name;
        k.resize(12, ' ');
        if((*it).price < 10)
            cout << j << " - " << k << "     ||     " << (*it).price << "      ||     " << (*it).base_level << "     ||     " << int((*it).boost * 100) << " %" << endl;
        else
            cout << j << " - " << k << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << int((*it).boost * 100) << " %" << endl;
    }
    cout << endl;
    //Spells
    for (list<SpellsNode>::iterator it = SpellsList.begin(); it != SpellsList.end(); ++it)
    {
        j++;
        if ((*it).type == "ice")
        {
            cout << "Ice Spells you can BUY: " << endl;
            cout << "          " << s << "|| Price || Level Requirement || Base Damage || Mana || Base Damage Reduction " << endl;
        }
        if ((*it).type == "fire")
        {
            cout << endl;
            cout << "Fire Spells you can BUY: " << endl;
            cout << "          " << s << "|| Price || Level Requirement || Base Damage || Mana || Defense Reduction " << endl;
        }
        if ((*it).type == "lighting")
        {
            cout << endl;
            cout << "Lighting Spells you can BUY: " << endl;
            cout << "          " << s << "|| Price || Level Requirement || Base Damage || Mana || Dodge Possibility Reduction " << endl;
        }
        string k = (*it).name;
        k.resize(12, ' ');
        cout << j << " - " << k << "     ||     " << (*it).price << "     ||     " << (*it).base_level << "     ||     " << (*it).dmg_var << "     ||     " << (*it).mana << "     ||     " << (*it).reduction << " %" << endl;
    }
    cout << endl;
}

list<PotionsNode> Market::get_potions()
{
    return PotionsList;
}

list<SpellsNode> Market::get_spells()
{
    return SpellsList;
}

list<WeaponNode> Market::get_weapons()
{
    return WeaponList;
}

list<ArmorNode> Market::get_armors()
{
    return ArmorList;
}

Market::~Market()
{
}