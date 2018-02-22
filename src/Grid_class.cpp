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

// Class Grid
Grid::Grid(int _x, int _y)
    : x(_x), y(_y), row(_x, common), my_grid(_y, row)
{
    pos_x = 1;
    pos_y = 1;
    cout << "The map is getting rendered!" << endl;
    createMap(x, y);
    cout << "Now the market is being created!" << endl;
    my_market = new Market();
}

void Grid::createMap(int x, int y)
{
    int my_square;
    ifstream MapFile;
    MapFile.open("map.txt"); // Our map is static
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
                my_grid[i][j] = common; // Using the enumerations
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
    cout << "Your position is : [ " << pos_x << " , " << pos_y << " ]." << endl; //pos_x and pos_y contain the position of our Heroes
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
        if (!ChanceToFight()) // Every time our Heroes move to a new location, theres a chance they encounter some monsters
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
        bool same_name = false;
        switch (hero_type)
        {
        case 1:
        {
            while (true)
            {
                same_name = false;
                cout << "What do you want your Warrior to be called ? : ";
                cin >> hero_name; // We give the option to the player to name his Heroes
                cout << endl;
                for (int k = 0; k < my_heroes.size(); k++)
                {
                    if (my_heroes[k]->getName() == hero_name)
                    {
                        cout << "There is already a Hero named this way!" << endl;
                        same_name = true;
                        break;
                    }
                }
                if (!same_name)
                    break;
            }
            if (!same_name)
            {
                hero_ptr = new Warrior(hero_name, 1, 70, 70, 0.2, 0.2, 0.2, 100, 100);
                my_heroes.push_back(hero_ptr);
            }
            else
                continue; // If the same name is given, we restart the action to name a Hero
            break;
        }
        case 2:
        {
            while (true)
            {
                same_name = false;
                cout << "What do you want your Sorcerer to be called ? : ";
                cin >> hero_name;
                cout << endl;
                for (int k = 0; k < my_heroes.size(); k++)
                {
                    if (my_heroes[k]->getName() == hero_name)
                    {
                        cout << "There is already a Hero named this way!" << endl;
                        same_name = true;
                        break;
                    }
                }
                if (!same_name)
                    break;
            }
            if (!same_name)
            {
                hero_ptr = new Sorcerer(hero_name, 1, 70, 70, 0.2, 0.2, 0.2, 100, 100);
                my_heroes.push_back(hero_ptr);
            }
            else
                continue;
            break;
        }
        case 3:
        {
            while (true)
            {
                same_name = false;
                cout << "What do you want your Paladin to be called ? : ";
                cin >> hero_name;
                cout << endl;
                for (int k = 0; k < my_heroes.size(); k++)
                {
                    if (my_heroes[k]->getName() == hero_name)
                    {
                        cout << "There is already a Hero named this way!" << endl;
                        same_name = true;
                        break;
                    }
                }
                if (!same_name)
                    break;
            }
            if (!same_name)
            {
                hero_ptr = new Paladin(hero_name, 1, 70, 70, 0.2, 0.2, 0.2, 100, 100); // All the Hero's constructor get the same input value,
                my_heroes.push_back(hero_ptr); // and the adjustions happen inside the constructors
            }
            else
                continue;
            break;
        }
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
    float multiplier = 1.0 + 0.2 * float(my_heroes[0]->getLevel() - 1);
    Monster *monster_ptr;
    bool deleted;
    for (int i = 0; i < monsters_to_create; i++)
    {
        deleted = false;
        int monster_type = rand() % 3 + 1;
        switch (monster_type) // We dont want the same type of monsters to be created
        {
        case 1:
            monster_ptr = new Dragon("kurios_fwtias", my_heroes[0]->getLevel(), 70.0 * multiplier, 11, 10.0 * multiplier, 0.2);
            for (int k = 0; k < my_monsters.size(); k++)
            {
                if (my_monsters[k]->get_name() == "kurios_fwtias")
                {
                    i--;
                    delete monster_ptr;
                    deleted = true;
                    break;
                }
            }
            if (!deleted)
            {
                cout << "====> A Dragon has been found! <====" << endl;
                my_monsters.push_back(monster_ptr);
            }
            break;
        case 2:
            monster_ptr = new Exoskeleton("kurios_kokkalakias", my_heroes[0]->getLevel(), 70.0 * multiplier, 11, 10.0 * multiplier, 0.2);
            for (int k = 0; k < my_monsters.size(); k++)
            {
                if (my_monsters[k]->get_name() == "kurios_kokkalakias")
                {
                    i--;
                    delete monster_ptr;
                    deleted = true;
                    break;
                }
            }
            if (!deleted)
            {
                cout << "====> An Exoskeleton has been found! <====" << endl;
                my_monsters.push_back(monster_ptr);
            }
            break;
        case 3:
            monster_ptr = new Spirit("kurios_pneumonas", my_heroes[0]->getLevel(), 70.0 * multiplier, 11, 10.0 * multiplier, 0.2);
            for (int k = 0; k < my_monsters.size(); k++)
            {
                if (my_monsters[k]->get_name() == "kurios_pneumonas")
                {
                    i--;
                    delete monster_ptr;
                    deleted = true;
                    break;
                }
            }
            if (!deleted)
            {
                cout << "====> A Spirit has been found! <====" << endl;
                my_monsters.push_back(monster_ptr);
            }
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
             << "2 - Move your Hero(es)" << endl
             << "3 - Display the stats of your Hero(s)" << endl
             << "4 - Display Equipment" << endl
             << "5 - Check the Inventory" << endl
             << "6 - Display owned Spells" << endl
             << "7 - Show the Market" << endl
             << "8 - Buy an item or a spell from the market" << endl
             << "9 - Sell an Item from your Inventory" << endl
             << "10 - Sell an owned Spell" << endl
             << "11 - Equip an item" << endl
             << "12 - Use a Potion" << endl
             << "13 - Quit the Game" << endl
             << "Type your choice and press return : ";
        cin >> input;
        cout << endl;
        switch (input)
        {
        case 1:
            displayMap();
            break;
        case 5:
            for (int i = 0; i < my_heroes.size(); i++)
                my_heroes[i]->show_inventory();
            break;
        case 3:
            displayHeroStats();
            break;
        case 9:
            SelltoMarket();
            break;
        case 2:
            move();
            break;
        case 8:
            BuyFromMarket();
            break;
        case 7:
            my_market->show_market();
            break;
        case 11:
            HeroToEquip();
            break;
        case 4:
            for (int i = 0; i < my_heroes.size(); i++)
                my_heroes[i]->displayEquipment();
            break;
        case 13:
            cout << "It was fun while it lasted. GGWP :D" << endl;
            exit(0);
        case 12:
            HeroToUsePotion();
            break;
        case 6:
            for (int i = 0; i < my_heroes.size(); i++)
                my_heroes[i]->show_spells();
            break;
        case 10:
            sellSpells();
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
    list<WeaponNode> weapons_list;
    list<ArmorNode> armors_list;
    list<SpellsNode> spells_list;
    list<PotionsNode> potions_list;
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
    my_market->show_market(); // Display the options of what the player can buy
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
                weapons_list = my_market->get_weapons();
                                   i = 1;
                for (list<WeaponNode>::iterator it = weapons_list.begin(); it != weapons_list.end(); ++it)
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
                armors_list = my_market->get_armors();
                                  i = 6;
                for (list<ArmorNode>::iterator it = armors_list.begin(); it != armors_list.end(); ++it)
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
                potions_list = my_market->get_potions();
                                   i = 11;
                for (list<PotionsNode>::iterator it = potions_list.begin(); it != potions_list.end(); ++it) // Reading the elements of the list.
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
                        bool added = my_heroes[hero_number]->add_inventoryItem(potion_ptr);
                        if (added) // True is given, if the action was successful
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
                spells_list = my_market->get_spells();
                i = 26;
                for (list<SpellsNode>::iterator it = spells_list.begin(); it != spells_list.end(); ++it)
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

void Grid::sellSpells()
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
    my_heroes[hero_number]->remove_inventorySpell();
}

bool Grid::ChanceToFight()
{
    int chance = rand() % 100 + 1;
    if (chance <= 45) // 45% chance to fight
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
             << "3 - Display the stats of your Hero(es) and the Monsters" << endl
             << "4 - Display Equipment" << endl
             << "5 - Display owned Spells" << endl
             << "6 - Attack" << endl
             << "7 - Cast Spell" << endl
             << "8 - Use a Potion" << endl
             << "9 - Equip an item" << endl
             << "10 - Quit the Game" << endl
             << "Type your choice and press return : ";
        cin >> input;
        cout << endl;
        switch (input) // continue; for the options that dont count as a round for the player and break; for those tat count
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
        case 6:
            Attack(hero_ptr);
            break;
        case 7:
            if (hero_ptr->getOwnedSpells().size() > 0)
                castSpell(hero_ptr);
            else
            {
                cout << "You do not own any Spells!" << endl;
                continue;
            }
            break;
        case 8:
        {
            bool potion_flag = false;
            for (int i = 0; i < hero_ptr->getInventory().size(); i++)
            {
                if (hero_ptr->getInventory()[i]->get_type() != weapon && hero_ptr->getInventory()[i]->get_type() != armor)
                {
                    hero_ptr->usePotion();
                    potion_flag = true;
                    break;
                }
            }
            if (!potion_flag)
            {
                cout << "You have no potion in your inventory!" << endl;
                continue;
            }
            break;
        }
        case 9:
            hero_ptr->Equip();
            break;
        case 4:
            hero_ptr->displayEquipment();
            continue;
        case 5:
            hero_ptr->show_spells();
            continue;
        case 10:
            cout << "It was fun while it lasted. GGWP :D" << endl;
            exit(0);
        default:
            cout << "Your input was wrong. Please TRY AGAIN." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
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
    if (!((rand() % 100 + 1) <= my_monsters[monster_number]->get_dodge_possibility() * 100.0))
    {
        damage = (selected_spell->get_dmg_var() + (rand() % 16)) * (1 + hero_ptr->get_dexterity());
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
    if (!((rand() % 100 + 1) <= my_monsters[monster_number]->get_dodge_possibility() * 100.0)) // If attack is not dodged
    {
        if (hero_ptr->getEquipment().hand1 != NULL && hero_ptr->getEquipment().hand2 != NULL)
            damage = (1 + hero_ptr->get_strength()) * (hero_ptr->getEquipment().hand1->get_dmg() + hero_ptr->getEquipment().hand2->get_dmg());
        else if (hero_ptr->getEquipment().hand1 != NULL && hero_ptr->getEquipment().hand2 == NULL)
            damage = (1 + hero_ptr->get_strength()) * (hero_ptr->getEquipment().hand1->get_dmg());
        else if (hero_ptr->getEquipment().hand1 == NULL && hero_ptr->getEquipment().hand2 != NULL)
            damage = (1 + hero_ptr->get_strength()) * (hero_ptr->getEquipment().hand2->get_dmg());
        else if (hero_ptr->getEquipment().hand1 == NULL && hero_ptr->getEquipment().hand2 == NULL) // If Hero fights with his fists
            damage = (1 + hero_ptr->get_strength()) * 10;
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
    for (int z = 0; z < my_monsters.size(); z++)
    {
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
        if (!flag_heroes_win) // If fight is not over and heroes turn is completed
        {
            cout << "Now its the monsters's turn" << endl;
            for (int i = 0; i < my_monsters.size(); i++)
            {
                if (my_monsters[i]->get_HP() > 0)
                {
                    int monster_dmg = my_monsters[i]->get_damage_var() + (rand() % 16);
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
        if (!(flag_heroes_win || flag_monsters_win)) // If fight is not over and monsters turn is completed
        {
            for (int h = 0; h < my_monsters.size(); h++)
            {
                if (my_monsters[h]->get_onIce() > 0)
                    my_monsters[h]->set_onIce(my_monsters[h]->get_onIce() - 1); // When a round ends, the duration of the poisoning of the spells gets reduced
                else
                    my_monsters[h]->set_damage_var(my_monsters[h]->get_starting_dmg_var());// Return to the starting values, before the Spell was casted
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
                    if (my_monsters[j]->get_HP() < 70 * multiplier)
                        cout << "====> " << my_monsters[j]->get_name() << " restored " << 70 * multiplier * (0.10) << " health power" << endl;
                    my_monsters[j]->set_HP(my_monsters[j]->get_HP() + 70 * multiplier * (0.10));
                    if (my_monsters[j]->get_HP() > 70 * multiplier)
                        my_monsters[j]->set_HP(70 * multiplier);
                }
            }
        }
        else if (flag_monsters_win) // If Monsters won
        {
            cout << "Monsters won!" << endl;
            for (int j = 0; j < my_heroes.size(); j++)
            {
                my_heroes[j]->setMoney(my_heroes[j]->getMoney() / 2);
                my_heroes[j]->setHP(70);
                my_heroes[j]->setMP(70);
            }
        }
        else if (flag_heroes_win) // If Heros won
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

Grid::~Grid()
{
    for (int i = 0; i < my_heroes.size(); i++)
    {
        delete my_heroes[i];
    }
}

void welcome()
{
    string input;
    cout << endl
         << "*** Welcome to the game! ***" << endl
         << endl
         << " * You must kill all the monsters you encounter while you explore the map." << endl
         << endl
         << " * Winning fights grants you more money and access to more powerful Items and Spells in the Market, " << endl
         << "    so you can expand your Stash." << endl
         << endl
         << " * TIP: Your fists don't deal a lot of damage, so rush to a Market and buy Weapons." << endl
         << endl
         << " * Every time you move to a Common position, theres a chance your footsteps wake up the Monsters that live there." << endl
         << "    You will have to fight them, to move on to your journey." << endl
         << endl
         << " * To be successful in this Game, you have to pray to RNJesus." << endl
         << endl
         << " Good Luck Traveler!" << endl
         << endl;
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