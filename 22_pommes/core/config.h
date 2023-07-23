#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <string>

/**
 * @brief Defines the initial configuration of the game board.
 *
 * This configuration includes the amount and type of apples
 * (represented by strings like "5G" for 5 green apples)
 * that will be placed on the board at the start of the game.
 */
const std::vector<std::string> INITIAL_BOARD_CONFIGURATION = {
    "5G", "5G", "5G", "5G",  // 4x 5 green apples
    "3G", "3G", "3G",        // 3x 3 green apples
    "2G", "2G",              // 2x 2 green apples
    "1G", "1G", "1G",        // 3x 1 green apple
    "5R", "5R", "5R", "5R",  // 4x 5 red apples
    "3R", "3R", "3R",        // 3x 3 red apples
    "2R", "2R",              // 2x 2 red apples
    "1R", "1R", "1R"         // 3x 1 red apple
};

/**
 * @brief Default number of rows in the game board.
 */
const int DEFAULT_ROWS = 5;

/**
 * @brief Default number of columns in the game board.
 */
const int DEFAULT_COLS = 5;

/**
 * @brief Number of rows in the elongated orchard variant of the game.
 */
const int VERGER_ALLONGE_ROWS = 3;

/**
 * @brief Number of columns in the elongated orchard variant of the game.
 */
const int VERGER_ALLONGE_COLS = 8;

#endif // CONFIG_H
