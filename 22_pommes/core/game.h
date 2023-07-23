#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

#include "observable.h"
#include "player.h"

/**
 * @brief The Game class encapsulates the core logic of the game.
 *
 * The class manages the game state, including the board configuration,
 * the state of players, turn management, and game end conditions.
 */
class Game : public Observable {
private:
    int rows, cols; ///< Dimensions of the game board.
    std::vector<std::string> board; ///< Current state of the game board.
    Player player1, player2; ///< The players participating in the game.
    int harvester; ///< Index position of the harvester on the board.
    bool isPlayer1Turn; ///< Flag indicating if it's player 1's turn.

    /**
     * @brief Checks if a move is valid.
     * @param row Row index for the move.
     * @param col Column index for the move.
     * @return true if the move is valid, false otherwise.
     */
    bool validMove(int row, int col);

public:
    /**
     * @brief Constructs a new Game object.
     * @param isVergerAllonge Determines if the game should be initialized with the elongated orchard configuration.
     */
    Game(bool isVergerAllonge = false);

    /**
     * @brief Executes a move.
     * @param row Row index for the move.
     * @param col Column index for the move.
     */
    void makeMove(int row, int col);

    /**
     * @brief Checks if the game has ended.
     * @return true if the game has ended, false otherwise.
     */
    bool checkEndGame();

    /**
     * @brief Checks if a move is valid.
     * @param row Row index for the move.
     * @param col Column index for the move.
     * @return true if the move is valid, false otherwise.
     */
    bool isMoveValid(int row, int col);

    /**
     * @brief Gets player 1.
     * @return A constant reference to player 1.
     */
    const Player& getPlayer1() const;

    /**
     * @brief Gets player 2.
     * @return A constant reference to player 2.
     */
    const Player& getPlayer2() const;

    /**
     * @brief Gets the current state of the game board.
     * @return A constant reference to the game board.
     */
    const std::vector<std::string>& getBoard() const;

    /**
     * @brief Gets the index position of the harvester on the board.
     * @return The index of the harvester.
     */
    int getHarvester() const;

    /**
     * @brief Checks if it's player 1's turn.
     * @return true if it's player 1's turn, false otherwise.
     */
    bool getIsPlayer1Turn() const;

    /**
     * @brief Gets the number of rows in the game board.
     * @return The number of rows.
     */
    int getRows() const;

    /**
     * @brief Gets the number of columns in the game board.
     * @return The number of columns.
     */
    int getCols() const;
};

#endif // GAME_H
