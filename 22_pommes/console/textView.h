#ifndef TEXTVIEW_H
#define TEXTVIEW_H

#include "../core/observer.h"
#include "../core/game.h"

/**
 * @class TextView
 * @brief A class that represents the text view of the game.
 *
 * TextView class provides a text-based representation of the game state to the players.
 * It implements the Observer interface, updating the displayed state when the game state changes.
 */
class TextView : public Observer {
private:
    /**
     * @brief Reference to the Game instance this TextView is observing.
     */
    Game& game;

public:
    /**
     * @brief Constructs a TextView object associated with a Game instance.
     *
     * The constructor takes a reference to a Game object to observe. When the game's
     * state changes, the TextView object updates its display accordingly.
     *
     * @param game Reference to the Game instance to be observed.
     */
    TextView(Game& game);

    /**
     * @brief Updates the TextView display.
     *
     * This method is called when the state of the observed Game instance changes.
     * It refreshes the display to match the current game state.
     */
    void update();

    /**
     * @brief Displays the current state of the game.
     *
     * This method prints the current state of the game to standard output, including
     * the game board, current player, and the state of the players' baskets.
     */
    void display();

    /**
     * @brief Displays the game title and instructions.
     *
     * This static method prints the game title and instructions to standard output.
     * It's declared static because it doesn't depend on a specific TextView instance.
     */
    static void displayTitle();
};

#endif // TEXTVIEW_H
