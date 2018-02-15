#include <string>
#include <vector>
#include <list>

using namespace std;

void welcome();

class Item; // Forward Declaration
class Hero;

struct Equipment
{
    Item *hand1;
    Item *hand2;
    Item *armor;
};

struct PotionsNode
{
    string name;
    int price;
    int base_level;
    float boost;
    string type;
};

struct SpellsNode
{
    string name;
    int price;
    int base_level;
    int dmg_var;
    int mana;
    int reduction;
    string type;
};

struct WeaponNode
{
    string name;
    int price;
    int base_level;
    int damage;
    int hands;
};

struct ArmorNode
{
    string name;
    int price;
    int base_level;
    int dmg_reduction;
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

enum TypeOfItem
{
    weapon,
    armor,
    strength_potion,
    dexterity_potion,
    agility_potion,
    ice_spell,
    fire_spell,
    lighting_spell
};

class Item
{

  private:
    string name;
    int price, base_level;
    TypeOfItem item_type;

  public:
    Item(string _name, int _price, int _base_level);
    TypeOfItem get_type() const;
    void set_type(TypeOfItem);
    string getName();
    int getPrice();
    virtual float get_boost() = 0;
    //virtual void use_the_potion() = 0;
    virtual int getHands() = 0;
    virtual int get_dmg_red();
    virtual int get_dmg();
    virtual ~Item();
};

class Weapon : public Item
{
  private:
    int damage, hands;

  public:
    Weapon(string _name, int _price, int _base_level, int _damage, int _hands);
    virtual float get_boost();
    //virtual void use_the_potion() = 0;
    int getHands();
    int get_dmg();
    ~Weapon();
};

class Armor : public Item
{
  private:
    int dmg_reduction;

  public:
    Armor(string _name, int _price, int _base_level, int _dmg_reduction);
    virtual float get_boost();
    int get_dmg_red();
    int getHands();
    int get_dmg_var();
    ~Armor();
};

class StrengthPotion : public Item
{
  private:
    float boost;

  public:
    StrengthPotion(string _name, int _price, int _base_level, float _boost);
    float get_boost();
    //void use_the_potion(Hero& );
    int getHands();
    ~StrengthPotion();
};

class DexterityPotion : public Item
{
  private:
    float boost;

  public:
    DexterityPotion(string _name, int _price, int _base_level, float _boost);
    float get_boost();
    //void use_the_potion(Hero& );
    int getHands();
    ~DexterityPotion();
};

class AgilityPotion : public Item
{
  private:
    float boost;

  public:
    AgilityPotion(string _name, int _price, int _base_level, float _boost);
    float get_boost();
    //void use_the_potion(Hero& );
    int getHands();
    ~AgilityPotion();
};

class Spell
{
  private:
    string name;
    int price, base_level, dmg_var, mana;
    TypeOfItem item_type;

  public:
    Spell(string _name, int _price, int _base_level, int _dmg_var, int _mana);
    TypeOfItem get_type() const;
    void set_type(TypeOfItem);
    string getName();
    int get_dmg_var();
    int get_mana();
    int getPrice();
    virtual int spell_poisoning() = 0;
    ~Spell();
};

class IceSpell : public Spell
{
  private:
    int dmg_var_reduction; //damage variety reduction

  public:
    IceSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dmg_var_reduction);
    int spell_poisoning();
    ~IceSpell();
};

class FireSpell : public Spell
{
  private:
    int armor_reduction;

  public:
    FireSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _armor_reduction);
    int spell_poisoning();
    ~FireSpell();
};

class LightingSpell : public Spell
{
  private:
    int dodge_reduction;

  public:
    LightingSpell(string _name, int _price, int _base_level, int _dmg_var, int _mana, int _dodge_reduction);
    int spell_poisoning();
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
    int get_Level() const;
    void set_level(int);
    int get_HP();
    void set_HP(int);
    ~Living();
};

class Hero : public Living
{
  protected:
    int magicPower, money, experience;
    float strength, dexterity, agility;
    vector<Item *> inventory_items;
    vector<Spell *> inventory_spells;
    Equipment my_equipment;

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
    bool add_inventoryItem(Item *);
    bool add_inventorySpell(Spell *);
    void remove_inventoryItem();
    void remove_inventorySpell();
    void show_inventory();
    void show_spells();
    int getMoney() const;
    void setMoney(int);
    int getLevel() const;
    string getName() const;
    int getHP();
    void setHP(int);
    int getMP();
    void setMP(int);
    int getEXP();
    void setEXP(int);
    Equipment getEquipment();
    vector<Item *> getInventory();
    vector<Spell *> getOwnedSpells();
    void displayStats();
    void Equip();
    void displayEquipment();
    void usePotion();
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
    int damage_var;
    float dodge_possibility, defense;
    int on_fire, on_ice, on_lighting;
    int starting_dmg_var;
    float starting_defense, starting_dodge_pos;

  public:
    Monster(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility);
    int get_damage_var() const;
    void set_damage_var(int new_dmgvar);
    float get_defense() const;
    void set_defense(float new_defence);
    float get_dodge_possibility() const;
    void set_dodge_possibility(float new_dodgepos);
    int get_onFire();
    int get_onIce();
    int get_onLighting();
    void set_onFire(int);
    void set_onIce(int);
    void set_onLIghting(int);
    int get_starting_dmg_var();
    void set_starting_dmg_var(int);
    float get_starting_defense();
    void set_starting_defense(float);
    float get_starting_dodge_pos();
    void set_starting_dodge_pos(float);
    void displayStats();
    ~Monster();
};

class Dragon : public Monster
{
  private:
    static const float dmg_var_boost = 20.0 / 100.0;

  public:
    Dragon(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility);
    ~Dragon();
};

class Exoskeleton : public Monster
{
  private:
    static const float defense_boost = 20.0 / 100.0;

  public:
    Exoskeleton(string _name, int _level, int _healthPower, int _damage_var, int _defense, float _dodge_possibility);
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

class Market
{
  private:
    list<PotionsNode> PotionsList;
    list<SpellsNode> SpellsList;
    list<WeaponNode> WeaponList;
    list<ArmorNode> ArmorList;

  public:
    Market();
    void show_market();
    list<PotionsNode> get_potions();
    list<SpellsNode> get_spells();
    list<WeaponNode> get_weapons();
    list<ArmorNode> get_armors();
    ~Market();
};

class Grid
{
  private:
    int x, y, heroes_count, pos_x, pos_y;
    vector<square_type> row;
    vector<vector<square_type> > my_grid;
    vector<Hero *> my_heroes;
    vector<Monster *> my_monsters;
    Market* my_market;

  public:
    Grid(int _x, int _y, int _heroes_count);
    void createMap(int, int);
    void displayMap();
    void createHero();
    void createMonsters();
    void move();
    void Menu();
    void BuyFromMarket();
    void SelltoMarket();
    void sellSpells();
    void displayHeroStats();
    void displayMonsterStats();
    void HeroToEquip();
    void HeroToUsePotion();
    bool ChanceToFight();
    void FightMenu(Hero *);
    void Fight();
    void Attack(Hero *);
    void castSpell(Hero *);
    ~Grid();
};