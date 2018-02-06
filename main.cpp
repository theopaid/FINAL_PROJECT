#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Interface.h"

using namespace std;

int main() {
    Grid *my_grid = new Grid(6, 6, 3);
    Hero* my_hero = new Warrior("picachu", 1,1,1,1,1,1,1,1);
    my_hero->LevelUp();
    welcome();
    my_grid->Menu();
    return 0;
}