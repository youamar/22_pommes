#include <iostream>
#include "textView.h"

/**
 * @brief Construct a new Text View object and add itself as an observer to the game.
 *
 * @param game A reference to the Game object.
 */
TextView::TextView(Game& game) : game(game) {
    game.addObserver(this);
}

/**
 * @brief The method to update the Text View. It simply calls the display method.
 */
void TextView::update() {
    display();
}

/**
 * @brief Display the title and rules of the game.
 *
 * This method is static because it doesn't depend on a specific TextView object.
 */
void TextView::displayTitle() {
    std::cout << "  ___  ___    _____   ____  __  __ __  __ ______  _____ \n"
                 " |__ \\|__ \\  |  __ \\ / __ \\|  \\/  |  \\/  |  ____|/ ____|\n"
                 "    ) |  ) | | |__) | |  | | \\  / | \\  / | |__  | (___  \n"
                 "   / /  / /  |  ___/| |  | | |\\/| | |\\/| |  __|  \\___ \\ \n"
                 "  / /_ / /_  | |    | |__| | |  | | |  | | |____ ____) |\n"
                 " |____|____| |_|     \\____/|_|  |_|_|  |_|______|_____/ \n"
                 "                                                         \n"
                 "                                                         \n";
    std::cout << "----------------------------------------------------------------------\n\n";
    std::cout << "Rule : be the first to get exactly 11 green apples and 11 red apples in your baskets or force your opponent to exceed this number !\n\n";
    std::cout << "  ___      _        _                                         _     \n"
                 " / __| ___| |___ __| |_   __ _ __ _ _ __  ___   _ __  ___  __| |___ \n"
                 " \\__ \\/ -_) / -_) _|  _| / _` / _` | '  \\/ -_) | '  \\/ _ \\/ _` / -_)\n"
                 " |___/\\___|_\\___\\__|\\__| \\__, \\__,_|_|_|_\\___| |_|_|_\\___/\\__,_\\___|\n"
                 "                         |___/                                      \n";
    std::cout << "\n";
    std::cout << "----------------------------------------------------------------------\n\n";
    std::cout << "  _       _  _                    _ \n";
    std::cout << " / |     | \\| |___ _ _ _ __  __ _| |\n";
    std::cout << " | |  _  | .` / _ \\ '_| '  \\/ _` | |\n";
    std::cout << " |_| (_) |_||\\\\___/_| |_|_|_\\__,_|_|\n";
    std::cout << "                                     \n";
    std::cout << "\n";

    std::cout << "  ___      __   __                        _   _ _                __ \n"
                 " |_  )     \\ \\ / /__ _ _ __ _ ___ _ _    /_\\ | | |___ _ _  __ _ /_/ \n"
                 "  / /   _   \\ V / -_) '_/ _` / -_) '_|  / _ \\| | / _ \\ ' \\/ _` / -_)\n"
                 " /___| (_)   \\_/\\___|_| \\__, \\___|_|   /_/ \\_\\_|_\\___/_||_\\__, \\___|\n"
                 "                        |___/                             |___/     \n\n";
    std::cout << "----------------------------------------------------------------------\n\n";
}

/**
 * @brief Display the current state of the game board.
 *
 * The method displays the game board grid with column and row numbers.
 * It also shows whose turn it is and how many apples each player has in their basket.
 */
void TextView::display() {
    int rows = game.getRows();
    int cols = game.getCols();
    const std::vector<std::string>& board = game.getBoard();
    std::cout << "\n";

    // Print column numbers
    std::cout << " ";
    for (int j = 0; j < cols; ++j) {
        std::cout << "    " << j;
    }
    std::cout << "\n";

    // Print top line
    std::cout << "  +";
    for (int j = 0; j < cols; ++j) {
        std::cout << "----+";
    }
    std::cout << "\n";
    // Print board contents
    for (int i = 0; i < rows; ++i) {
        std::cout << i << " |";  // Print row number
        for (int j = 0; j < cols; ++j) {
            int currentIdx = i * cols + j;
            std::cout << " ";
            if (currentIdx == game.getHarvester()) {
                std::cout << "H  ";
            } else {
                if (board[currentIdx] == " ") {
                    std::cout << "  ";
                } else {
                    std::cout << board[currentIdx] << " ";
                }
            }
            std::cout << "|";
        }
        std::cout << "\n  +";
        // Print line between rows
        for (int j = 0; j < cols; ++j) {
            std::cout << "----+";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    if (game.getIsPlayer1Turn())
        std::cout << "It's Player 1's turn !" << std::endl;
    else
        std::cout << "It's Player 2's turn !" << std::endl;

    const Player& player1 = game.getPlayer1();
    const Player& player2 = game.getPlayer2();

    std::cout << "Player 1's baskets - Green: " << player1.greenApples << " Red: " << player1.redApples << std::endl;
    std::cout << "Player 2's baskets - Green: " << player2.greenApples << " Red: " << player2.redApples << std::endl;
}
