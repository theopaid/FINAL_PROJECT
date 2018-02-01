#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Interface.h"

using namespace std;

int main() {
    Grid *my_grid = new Grid(4, 4, 3);
    Hero* my_hero = new Warrior("picachu", 1,1,1,1,1,1,1,1);
    my_hero->LevelUp();
    my_grid->Menu();
    return 0;
}