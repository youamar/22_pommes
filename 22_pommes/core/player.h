#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief The Player class represents a player in the game.
 *
 * Each player has a count of red apples and green apples they have collected during the game.
 */
class Player {
public:
    /**
     * @brief The number of red apples the player has.
     */
    int redApples = 0;

    /**
     * @brief The number of green apples the player has.
     */
    int greenApples = 0;
};

#endif // PLAYER_H
