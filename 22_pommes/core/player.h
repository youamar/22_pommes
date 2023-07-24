#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief The Player class represents a player in the game.
 *
 * Each player has a count of red apples and green apples they have collected during the game.
 */
class Player {
private:
    /**
     * @brief The number of red apples the player has.
     */
    int redApples = 0;

    /**
     * @brief The number of green apples the player has.
     */
    int greenApples = 0;

public:

    /**
     * @brief Adds a number of red apples to the player's count.
     * @param nb The number of red apples to add.
     */
    void addRedApple(int nb);

    /**
     * @brief Adds a number of green apples to the player's count.
     * @param nb The number of green apples to add.
     */
    void addGreenApple(int nb);

    /**
     * @brief Gets the number of red apples the player has.
     * @return The number of red apples the player has.
     */
    int getRedApples() const;

    /**
     * @brief Gets the number of green apples the player has.
     * @return The number of green apples the player has.
     */
    int getGreenApples() const;

};

#endif // PLAYER_H
