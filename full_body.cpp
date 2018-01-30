#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

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

/*enum ItemType
{

}

struct WeaponNode {
    string name;
    int price, base_level, damage, hands;
}

struct Armor {
    string name;
    int price, base_level, dmg_reduction;
}

struct */

class Item
{

  private:
    string name;
    int price, base_level;

  public:
    Item(string _name, int _price, int _base_level)
        : name(_name), price(_price), base_level(_base_level) {}
    virtual float get_boost() = 0;
    virtual void use_the_potion() = 0;

    virtual ~Item() {}
};

class Weapon : public Item
{

  private:
    int damage, hands;

  public:
    Weapon(string _name, int _price, int _base_level, int _damage, int _hands)
        : Item(_name, _price, _base_level), damage(_damage), hands(_hands) {}

    ~Weapon() {}
};

class Armor : public Item
{

  private:
    int dmg_reduction;

  public:
    Armor(string _name, int _price, int _base_level, int _dmg_reduction)
        : Item(_name, _price, _base_level), dmg_reduction(_dmg_reduction) {}

    ~Armor() {}	
};

/*class Potion : public Item
{
  public:
}*/

class StrengthPotion : public Item
{
  private:
    float boost;

  public:
    StrengthPotion(string _name, int _price, int _base_level, float _boost)
        : Item(_name, _price, _base_level), boost(_boost) {}
    float get_boost() const
    {
        return boost;
    }
    /*void use_the_potion(&Hero my_hero) {
        my_hero.add_boost_to_strength(boost);
    }*/
    ~StrengthPotion()
    {
        cout << "Hurray! You used all of the Strength Potion." << endl;
    }
};

class DexterityPotion : public Item
{
  private:
    float boost;

  public:
    DexterityPotion(string _name, int _price, int _base_level, float _boost)
        : Item(_name, _price, _base_level), boost(_boost) {}
    float get_boost() const
    {
        return boost;
    }
    /*void use_the_potion(&Hero my_hero) {
        my_hero.add_boost_to_strength(boost);
    }*/
    ~DexterityPotion()
    {
        cout << "Hurray! You used all of the Dexterity Potion." << endl;
    }
};

class AgilityPotion : public Item
{
  private:
    float boost;

  public:
    AgilityPotion(string _name, int _price, int _base_level, float _boost)
        : Item(_name, _price, _base_level), boost(_boost) {}
    float get_boost() const
    {
        return boost;
    }
    /*void use_the_potion(&Hero my_hero) {
        my_hero.add_boost_to_strength(boost);
    }*/
    ~AgilityPotion()
    {
        cout << "Hurray! You used all of the Agility Potion." << endl;
    }
};

class Spell
{
  private:
    string name;
    int price, base_level, dmg_var, mana;

  public:
    Spell(string _name, int _price, int _base_level, int _dmg_var, int _mana)
        : name(_name), price(_price), base_level(_base_level), dmg_var(_dmg_var), mana(_mana) {}

    ~Spell() {}
};

class IceSpell : public Spell
{
  private:
    int dmg_var_reduction; //damage variety reduction

  public:
    IceSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dmg_var_reduction)
        : Spell(_name, _price, _base_level, _dmg_var, _mana), dmg_var_reduction(_dmg_var_reduction) {}

    ~IceSpell() {}
};

class FireSpell : public Spell
{
  private:
    int armor_reduction;

  public:
    FireSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _armor_reduction)
        : Spell(_name, _price, _base_level, _dmg_var, _mana), armor_reduction(_armor_reduction) {}

    ~FireSpell() {}
};

class LightingSpell : public Spell
{
  private:
    int dodge_reduction;

  public:
    LightingSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dodge_reduction)
        : Spell(_name, _price, _base_level, _dmg_var, _mana), dodge_reduction(_dodge_reduction) {}

    ~LightingSpell() {}
};

class Living
{
  private:
    string name;
    int level, healthPower;

  public:
    Living(string _name, int _level, int _healthPower)
        : name(_name), level(_level), healthPower(_healthPower) {}

    string get_name() const{
        return name;
    }
    ~Living() {}
};

class Hero : public Living
{
  protected:
    int magicPower,  money, experience;
    float strength, dexterity, agility;
    vector<Item *> inventory_items;
    vector<Spell *> inventory_spells;

  public:
    Hero(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience)
        : Living(_name, _level, _healthPower), magicPower(_magicPower), strength(_strength), dexterity(_dexterity), agility(_agility), money(_money), experience(_experience) {}
    virtual void LevelUp() = 0;
    float get_strength() const 
    {
        return strength;
    }
    void set_strength(float new_strength) 
    {
        strength = new_strength;
    }
    float get_agility() const
    {
        return agility;
    }
    void set_agility(float new_agility)  
    {
        agility = new_agility;
    } 
    float get_dexterity() const
    {
        return dexterity;
    }
    void set_dexterity(float new_dexterity) 
    {
        dexterity = new_dexterity;
    }
    /*void use_potion(Item *my_potion)
    {
        my_potion->use_the_potion(this);
    }*/
    void add_boost_to_strength(float boost)
    {
        strength += strength * boost;
    }
    void add_boost_to_dexterity(float boost)
    {
        dexterity += dexterity * boost;
    }
    void add_boost_to_agility(float boost)
    {
        agility += agility * boost;
    }

    ~Hero() {}
};

class Warrior : public Hero
{
  private:
    static const float strength_boost = 20.0 / 100.0;
    static const float agility_boost = 15.0 / 100.0;

  public:
    Warrior(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience)
        : Hero(_name, _level, _healthPower, _magicPower, _strength, _dexterity, _agility, _money, _experience)
    {
        Hero::set_strength(Hero::get_strength() * (1 + strength_boost));
        Hero::set_agility(Hero::get_agility() * (1 + agility_boost));
    }
    void LevelUp()
    {
        cout << Living::get_name() << " is leveling Up!" << endl;
        strength = strength + strength * (15.0 / 100.0);
        agility = agility + agility * (10.0 / 100.0);
        dexterity = dexterity + dexterity * (5.0 / 100.0);
    }

    ~Warrior() {}
};

class Sorcerer : public Hero
{
  private:
    static const float dexterity_boost = 20.0 / 100.0;
    static const float agility_boost = 15.0 / 100.0;

  public:
    Sorcerer(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience)
        : Hero(_name, _level, _healthPower, _magicPower, _strength, _dexterity, _agility, _money, _experience)
    {
        Hero::set_dexterity(Hero::get_dexterity() * (1 + dexterity_boost));
        Hero::set_agility(Hero::get_agility() * (1 + agility_boost));
    }
    void LevelUp()
    {
        strength = strength + strength * (5.0 / 100.0);
        agility = agility + agility * (10.0 / 100.0);
        dexterity = dexterity + dexterity * (15.0 / 100.0);
    }

    ~Sorcerer() {}
};

class Paladin : public Hero
{
  private:
    static const float strength_boost = 20.0 / 100.0;
    static const float dexterity_boost = 15.0 / 100.0;

  public:
    Paladin(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience)
        : Hero(_name, _level, _healthPower, _magicPower, _strength, _dexterity, _agility, _money, _experience)
    {
        Hero::set_strength(Hero::get_strength() * (1 + strength_boost));
        Hero::set_dexterity(Hero::get_dexterity() * (1 + dexterity_boost));
    }
    void LevelUp()
    {
        strength = strength + strength * (15.0 / 100.0);
        agility = agility + agility * (5.0 / 100.0);
        dexterity = dexterity + dexterity * (10.0 / 100.0);
    }

    ~Paladin() {}
};

class Monster : public Living
{
  private:
    int damage_var, defense;
    float dodge_possibility;

  public:
    Monster(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility)
        : Living(_name, _level, _healthPower), damage_var(_damage_var), defense(_defense), dodge_possibility(_dodge_possibility) {}
    int get_damage_var() const 
    {
        return damage_var;
    }
    void set_damage_var(int new_dmgvar)
    {
        damage_var = new_dmgvar;
    }
    int get_defense() const 
    {
        return defense;
    }
    void set_defense(int new_defence) 
    {
        defense = new_defence;
    }
    float get_dodge_possibility() const
    {
        return dodge_possibility;
    }
    void set_dodge_possibility(float new_dodgepos)
    {
        dodge_possibility = new_dodgepos;
    }

    ~Monster() {}
};

class Dragon : public Monster
{
  private:
    static const int dmg_var_boost = 20.0 / 100.0;

  public:
    Dragon(string _name, int _level, int _healthPower, int _damage_var, int _defense, int _dodge_possibility)
        : Monster(_name, _level, _healthPower, _damage_var, _defense, _dodge_possibility)
    {
        Monster::set_damage_var(Monster::get_damage_var() * (1 + dmg_var_boost));
    }

    ~Dragon() {}
};

class Exoskeleton : public Monster
{
  private:
    static const int defense_boost = 20.0 / 100.0;

  public:
    Exoskeleton(string _name, int _level, int _healthPower, int _damage_var, int _defense, int _dodge_possibility)
        : Monster(_name, _level, _healthPower, _damage_var, _defense, _dodge_possibility)
    {
        Monster::set_defense(Monster::get_defense() * (1 + defense_boost));
    }

    ~Exoskeleton() {}
};

class Spirit : public Monster
{
  private:
    static const float dodge_pos_boost = 20.0 / 100.0;

  public:
    Spirit(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility)
        : Monster(_name, _level, _healthPower, _damage_var, _defense, _dodge_possibility)
    {
        Monster::set_dodge_possibility(Monster::get_dodge_possibility() * (1 + dodge_pos_boost));
    }

    ~Spirit() {}
};

class Grid
{
  private:
    int x, y, heroes_count;
    vector<square_type> row;
    vector<vector<square_type> > my_grid;

  public:
    Grid(int _x, int _y, int _heroes_count)
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
    void displayMap()
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
    }
    void move(next_move my_move)
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

    ~Grid() {}
};

/*class Matrix_square_type{
    private:
        bool not_accessible, 

    public:

};*/

int main()
{

    Grid *my_grid = new Grid(4, 4, 3);
    my_grid->displayMap();
    Hero* my_hero = new Warrior("picachu", 1,1,1,1,1,1,1,1);
    my_hero->LevelUp();
    return 0;
}
