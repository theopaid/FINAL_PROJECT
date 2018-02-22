#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Interface.h"

using namespace std;

int main() {
    srand(time(NULL));
    welcome();
    Grid *my_grid = new Grid(6, 6); // Size of Grid
    my_grid->Menu();
    return 0;
}