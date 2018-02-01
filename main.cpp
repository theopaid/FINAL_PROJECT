#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Interface.h"

using namespace std;

int main() {
    Grid *my_grid = new Grid(4, 4, 3);
    my_grid->show_market();
    Hero* my_hero = new Warrior("picachu", 1,1,1,1,1,1,1,1);
    my_hero->LevelUp();
    return 0;
}