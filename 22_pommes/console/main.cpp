#include <iostream>
#include "gameController.h"

using namespace std;

int main() {
    TextView::displayTitle();
    int mode;
    std::cin >> mode;
    GameController gameController(mode==2);
    gameController.play();
    return 0;
}
