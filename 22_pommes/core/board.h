/*!
* \file board.h
*
* \brief board class definition
*
*/
#ifndef BOARD_H
#define BOARD_H

#include <list>
#include <tuple>
#include <string>
#include <iostream>
#include <vector>
#include <array>

#include "config.h"
#include "token.h"
#include "position.h"
#include "score.h"
#include "direction.h"
#include "iObservable.h"

/*!
* \brief This class contains Tokens positions, the players scores and functions to move the Tokens
*/
class Board : public iObservable {
private:
    /*!
     * \brief Size of the board.
    */
    const int SIZE;

    /*!
     * \brief The initial positions of all tokens on the board
     */
   // const std::array<std::tuple<Position, int>, 28> initalPosition = {
        //std::make_tuple(Position(0, 4), 1),
       // std::make_tuple(Position(1, 5), 1),
        //std::make_tuple(Position(1, 6), 1),
      //  std::make_tuple(Position(8, 4), 2)
    //};

    /*!
     * \brief A multidimensional array that contains the player number position instead of tokens
     */
    std::array<std::array<int, BoardSize>, BoardSize> * playersBoard;

    /*!
     * \brief The players scores
    */
    Score score;

    /*!
     * \brief Checks if a coord is in bounds
     *
     * Returns true if the coord is inside the array and inside the board
     *
     * \param coord the coord that needs checking
     *
    */
    bool isInBounds(Position coord);

    /*!
     * \brief The observers list
     */
    std::list<iObserver *> observers;

    /*!
     * \brief changes who's turn it is
     */
    void nextPlayer();

protected:
    /*!
     * \brief The tokens Array of the board
    */
    std::vector<std::vector<Token *>> grid;

    /*!
     * \brief Initalize a new board
    */
    void init();

    /*!
     * \brief Id of the current player who's turn it is.
    */
    int currentPlayer;

    /*!
     * \brief The amount of players that play the game
    */
    int playersAmount;

    /*!
     * \brief Checks if a move is legal for a token
     *
     * Check if the selected token can move on the direction before the real move
     *
     * \param coordinate the token point to check
     * \param direction the direction to move on the grid
     *
    */
    bool isMovable(Position coord, eDirection direction);

    /*!
     * \brief Returns an array of token color
     *
     * transform the Tokens grid in a 2D array of ANSI color for the console view
     *
    */
    std::array<std::array<int, BoardSize>, BoardSize> * getPlayersBoard();

    /*!
     * \brief Moves a token selected by a point to another point
     *
     * \param coordinate the token point to move
     * \param direction the direction to move on the grid
     *
    */
    void move(Position coord, eDirection direction);

    /*!
     * \brief Checks if a player has won
    */
    bool isWon();

    /*!
     * \brief Returns the current score of a player by ID
     *
     * \param player the player id to check
     *
    */
    int getScorePlayer(int player);

    /*!
     * \brief Returns the player with the highscore
    */
    int * getPlayerHighestScore();

public:
    /*!
     * \brief constructor
     *
     * Initialize the grid with the constant SIZE and the score for each player
     *
    */
    Board();

    /*!
    * \brief Deconstructor of the Board, used to deallocate all tokens.
    */
    ~Board();

    /*!
     * \brief Add an observer on Board
     * \param observer the observer to add
     */
    virtual void addObserver(iObserver * observer);

    /*!
     * \brief Remove an observer on Board
     * \param observer the observer to remove
     */
    virtual void removeObserver(iObserver * observer);

    /*!
     * \brief Notify all observers
     */
    virtual void notify(std::string name, void * object);
};

#endif // BOARD_H
