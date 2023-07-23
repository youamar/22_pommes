#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "../core/game.h"
#include "textView.h"

/**
 * @class GameController
 * @brief Main controller class for the game.
 *
 * GameController class acts as a bridge between the game logic (contained in Game class)
 * and the view layer (represented by TextView class). It initializes the game based on
 * the selected mode and orchestrates the gameplay.
 */
class GameController {
private:
    /**
     * @brief Instance of the game.
     */
    Game game;

    /**
     * @brief Instance of the view.
     */
    TextView view;

public:
    /**
     * @brief Constructs a GameController object.
     *
     * This constructor initializes the game object based on the selected game mode
     * and creates a TextView object tied to the game. If isVergerAllonge is true,
     * the game is initialized with "Verger Allongé" rules.
     *
     * @param isVergerAllonge Boolean indicating if the game is to be played
     *                        in "Verger Allongé" mode (default: false).
     */
    GameController(bool isVergerAllonge = false);

    /**
     * @brief Starts and manages the game.
     *
     * The play method is responsible for game progression. It starts the game,
     * continues to prompt the player(s) for input and makes moves until the game ends.
     * Upon completion of the game, it declares the winner or announces a draw.
     */
    void play();
};

#endif // GAMECONTROLLER_H
