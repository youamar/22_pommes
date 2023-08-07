#include <algorithm>
#include <ctime>
#include <random>

#include "game.h"
#include "config.h"

/**
 * @brief Construct a new Game object.
 *
 * @param isVergerAllonge If true, the game is initialized with the "Verger Allonge" mode.
 */
Game::Game(bool isVergerAllonge) : rows(DEFAULT_ROWS), cols(DEFAULT_COLS), board(INITIAL_BOARD_CONFIGURATION) {
    // Create a random device
    std::random_device rd;

    // Using the random device to seed the Mersenne twister engine (good quality random number generator)
    std::mt19937 g(rd());

    if (isVergerAllonge) {
        rows = VERGER_ALLONGE_ROWS;
        cols = VERGER_ALLONGE_COLS;
        // Resize the board for the "Verger Allonge" mode
        board.resize(rows * cols, " "); // All new cells are empty
    } else {
        board.resize(rows * cols - 1); // Ensure correct size for the normal mode (-1 for the harvester)
    }

    // Shuffle the board
    std::shuffle(board.begin(), board.end(), g);

    harvester = g() % (rows * cols);  // harvester is placed randomly on the board regardless of the mode

    // Insert the harvester in the board at the random index
    board.insert(board.begin() + harvester, "H");

    isPlayer1Turn = g() % 2;
}

/**
 * @brief Check if a move is valid by comparing the target position with the harvester's position.
 *
 * @param row The row of the target cell.
 * @param col The column of the target cell.
 * @return true if the move is valid.
 * @return false if the move is not valid.
 */
bool Game::validMove(int row, int col) {
    int harvesterRow = harvester / cols;
    int harvesterCol = harvester % cols;
    return row == harvesterRow || col == harvesterCol;
}

/**
 * @brief Check if a move is valid and the target cell is not marked as visited.
 *
 * @param row The row of the target cell.
 * @param col The column of the target cell.
 * @return true if the move is valid and the target cell is not visited.
 * @return false otherwise.
 */
bool Game::isMoveValid(int row, int col) {
    int targetCell = row * cols + col;
    // check if targetCell equals harvester, if true it's not valid
    if(targetCell == harvester) {
        return false;
    }
    return validMove(row, col) && board[targetCell] != "X ";
}

/**
 * @brief Make a move and update the game state.
 *
 * @param row The row of the target cell.
 * @param col The column of the target cell.
 */
void Game::makeMove(int row, int col) {
    if(!isMoveValid(row, col)) {
        return; // Do not proceed if move is not valid
    }
    std::string value = board[row * cols + col];

    int oldHarvester = harvester;
    harvester = row * cols + col;

    Player& currentPlayer = isPlayer1Turn ? player1 : player2;

    if (value != "X ") {  // Add this check to ensure 'X' is not counted as an apple
        if (value[1] == 'G') {
            currentPlayer.addGreenApple((value[0] - '0'));
        } else {
            currentPlayer.addRedApple((value[0] - '0'));
        }
    }

    isPlayer1Turn = !isPlayer1Turn;

    // Mark the old harvester cell with "X"
    board[oldHarvester] = "X ";

    // Set the new harvester cell to "H"
    board[harvester] = "H";

    notifyObservers();
}

/**
 * @brief Check if the game has ended.
 *
 * @return true if the game has ended.
 * @return false otherwise.
 */
bool Game::checkEndGame() {
    // Check if any player has exactly 11 apples of each color
    if ((player1.getRedApples() == 11 && player1.getGreenApples() == 11) || (player2.getRedApples() == 11 && player2.getGreenApples() == 11))
        return true;
    // Check if any player has more than 11 apples of one color
    else if ((player1.getRedApples() > 11 || player1.getGreenApples() > 11) || (player2.getRedApples() > 11 || player2.getGreenApples() > 11))
        return true;

    // Check if no more valid moves available
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (isMoveValid(row, col)) {
                // There is at least one valid move, so the game has not ended
                return false;
            }
        }
    }
    // If we reach here, there are no valid moves left, so the game has ended
    return true;
}

/**
 * @brief Get the Player 1 object
 *
 * @return const Player&
 */
const Player& Game::getPlayer1() const {
    return player1;
}

/**
 * @brief Get the Player 2 object
 *
 * @return const Player&
 */
const Player& Game::getPlayer2() const {
    return player2;
}

/**
 * @brief Get the Board object
 *
 * @return const std::vector<std::string>&
 */
const std::vector<std::string>& Game::getBoard() const {
    return board;
}

/**
 * @brief Get the Harvester's position
 *
 * @return int
 */
int Game::getHarvester() const {
    return harvester;
}

/**
 * @brief Get the Is Player 1 Turn flag
 *
 * @return true if it's Player 1's turn.
 * @return false otherwise.
 */
bool Game::getIsPlayer1Turn() const {
    return isPlayer1Turn;
}

/**
 * @brief Get the number of Rows in the board
 *
 * @return int
 */
int Game::getRows() const {
    return rows;
}

/**
 * @brief Get the number of Columns in the board
 *
 * @return int
 */
int Game::getCols() const {
    return cols;
}
