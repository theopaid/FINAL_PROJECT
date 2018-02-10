#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Interface.h"

using namespace std;

int main() {
    welcome();
    Grid *my_grid = new Grid(6, 6, 3);
    my_grid->Menu();
    return 0;
}