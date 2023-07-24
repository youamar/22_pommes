#include "player.h"

/**
 * @brief Adds a number of red apples to the player's count.
 * @param nb the number of apples to add.
 */
void Player::addRedApple(int nb) {
    redApples += nb;
}

/**
 * @brief Adds a number of green apples to the player's count.
 * @param nb the number of apples to add.
 */
void Player::addGreenApple(int nb) {
    greenApples += nb;
}

/**
 * @brief Gets the number of red apples the player has.
 * @return The number of red apples the player has.
 */
int Player::getRedApples() const {
    return redApples;
}

/**
 * @brief Gets the number of green apples the player has.
 * @return The number of green apples the player has.
 */
int Player::getGreenApples() const {
    return greenApples;
}
