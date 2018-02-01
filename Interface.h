#include <string>
#include <vector>
#include <list>

using namespace std;

//enum next_move;
//enum square_type;

struct PotionsNode
{
    string name;
    int price;
    int base_level;
    float boost;
};

struct SpellsNode {
    string name;
    int price;
    int base_level;
    int dmg_var;
    int mana;
    int reduction;
};

struct WeaponNode
{
    string name;
    int price;
    int base_level;
    int damage;
    int hands;
    string can_be_sold;
};

struct ArmorNode {
    string name;
    int price;
    int base_level;
    int dmg_reduction;
    string can_be_sold;
};

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

class Item
{

  private:
    string name;
    int price, base_level;

  public:
    Item(string _name, int _price, int _base_level);
    virtual float get_boost() = 0;
    virtual void use_the_potion() = 0;
    virtual ~Item();
};

class Weapon : public Item
{
  private:
    int damage, hands;

  public:
    Weapon(string _name, int _price, int _base_level, int _damage, int _hands);
    ~Weapon();
};

class Armor : public Item
{
  private:
    int dmg_reduction;

  public:
    Armor(string _name, int _price, int _base_level, int _dmg_reduction);
    ~Armor();
};

class StrengthPotion : public Item
{
  private:
    float boost;

  public:
    StrengthPotion(string _name, int _price, int _base_level, float _boost);
    float get_boost() const;
    //void use_the_potion(&Hero my_hero);
    ~StrengthPotion();
};

class DexterityPotion : public Item
{
  private:
    float boost;

  public:
    DexterityPotion(string _name, int _price, int _base_level, float _boost);
    float get_boost() const;
    //void use_the_potion(&Hero my_hero);
    ~DexterityPotion();
};

class AgilityPotion : public Item
{
  private:
    float boost;

  public:
    AgilityPotion(string _name, int _price, int _base_level, float _boost);
    float get_boost() const;
    //void use_the_potion(&Hero my_hero);
    ~AgilityPotion();
};

class Spell
{
  private:
    string name;
    int price, base_level, dmg_var, mana;

  public:
    Spell(string _name, int _price, int _base_level, int _dmg_var, int _mana);
    ~Spell();
};

class IceSpell : public Spell
{
  private:
    int dmg_var_reduction; //damage variety reduction

  public:
    IceSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dmg_var_reduction);
    ~IceSpell();
};

class FireSpell : public Spell
{
  private:
    int armor_reduction;

  public:
    FireSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _armor_reduction);
    ~FireSpell();
};

class LightingSpell : public Spell
{
  private:
    int dodge_reduction;

  public:
    LightingSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dodge_reduction);
    ~LightingSpell();
};

class Living
{
  private:
    string name;
    int level, healthPower;

  public:
    Living(string _name, int _level, int _healthPower);
    string get_name() const;
    ~Living();
};

class Hero : public Living
{
  protected:
    int magicPower, money, experience;
    float strength, dexterity, agility;
    vector<Item *> inventory_items;
    vector<Spell *> inventory_spells;

  public:
    Hero(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience);
    virtual void LevelUp() = 0;
    float get_strength() const;
    void set_strength(float new_strength);
    float get_agility() const;
    void set_agility(float new_agility);
    float get_dexterity() const;
    void set_dexterity(float new_dexterity);
    void use_potion(Item *my_potion);
    void add_boost_to_strength(float boost);
    void add_boost_to_dexterity(float boost);
    void add_boost_to_agility(float boost);
    ~Hero();
};

class Warrior : public Hero
{
  private:
    static const float strength_boost = 20.0 / 100.0;
    static const float agility_boost = 15.0 / 100.0;

  public:
    Warrior(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience);
    void LevelUp();
    ~Warrior();
};

class Sorcerer : public Hero
{
  private:
    static const float dexterity_boost = 20.0 / 100.0;
    static const float agility_boost = 15.0 / 100.0;

  public:
    Sorcerer(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience);
    void LevelUp();
    ~Sorcerer();
};

class Paladin : public Hero
{
  private:
    static const float strength_boost = 20.0 / 100.0;
    static const float dexterity_boost = 15.0 / 100.0;

  public:
    Paladin(string _name, int _level, int _healthPower, int _magicPower, float _strength, float _dexterity, float _agility, int _money, int _experience);
    void LevelUp();
    ~Paladin();
};

class Monster : public Living
{
  private:
    int damage_var, defense;
    float dodge_possibility;

  public:
    Monster(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility);
    int get_damage_var() const;
    void set_damage_var(int new_dmgvar);
    int get_defense() const;
    void set_defense(int new_defence);
    float get_dodge_possibility() const;
    void set_dodge_possibility(float new_dodgepos);
    ~Monster();
};

class Dragon : public Monster
{
  private:
    static const int dmg_var_boost = 20.0 / 100.0;

  public:
    Dragon(string _name, int _level, int _healthPower, int _damage_var, int _defense, int _dodge_possibility);
    ~Dragon();
};

class Exoskeleton : public Monster
{
  private:
    static const int defense_boost = 20.0 / 100.0;

  public:
    Exoskeleton(string _name, int _level, int _healthPower, int _damage_var, int _defense, int _dodge_possibility);
    ~Exoskeleton();
};

class Spirit : public Monster
{
  private:
    static const float dodge_pos_boost = 20.0 / 100.0;

  public:
    Spirit(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility);
    ~Spirit();
};

class Grid
{
  private:
    int x, y, heroes_count;
    vector<square_type> row;
    vector<vector<square_type> > my_grid;
    list<PotionsNode> PotionsList;
    list<SpellsNode> SpellsList;
    list<WeaponNode> WeaponList;
    list<ArmorNode> ArmorList;

  public:
    Grid(int _x, int _y, int _heroes_count);
    void displayMap();
    void move(next_move my_move);
    void show_market();
    ~Grid();
};