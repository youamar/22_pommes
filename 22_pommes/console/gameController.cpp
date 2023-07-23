#include <iostream>
#include "gameController.h"

/**
 * @brief Construct a new Game Controller:: Game Controller object.
 *
 * This constructor initializes the game and view objects, with the
 * isVergerAllonge flag passed to the Game object's constructor.
 *
 * @param isVergerAllonge A boolean value indicating the game mode. If set to true, the game is in Verger Allonge mode.
 */
GameController::GameController(bool isVergerAllonge) : game(isVergerAllonge), view(game) {}

/**
 * @brief Run the game loop until it ends.
 *
 * This method runs the main game loop. It keeps asking the current player for a move
 * until the game ends. When a move is made, the method checks whether it is valid.
 * If the move is valid, it will be made on the game board. After each move, the method
 * checks whether the game has ended. If so, it breaks out of the loop. Finally, the method
 * determines the winner and announces them.
 */
void GameController::play() {
    int row, col;
    view.update();
    while (true) {
        std::cout << "\nEnter row and column: ";
        std::cin >> row >> col;
        if (game.isMoveValid(row, col)) {
            game.makeMove(row, col);
            if (game.checkEndGame()) {
                std::cout << "\nThe game has ended.\n";
                break;
            }
        } else {
            std::cout << "\nInvalid move" << std::endl;
        }
    }

    const Player& player1 = game.getPlayer1();
    const Player& player2 = game.getPlayer2();
    std::cout << "\n";

    int player1Diff = std::abs(player1.redApples - 11) + std::abs(player1.greenApples - 11);
    int player2Diff = std::abs(player2.redApples - 11) + std::abs(player2.greenApples - 11);

    if (player1Diff < player2Diff)
        std::cout << "Player 1 wins !\n";
    else if (player2Diff < player1Diff)
        std::cout << "Player 2 wins !\n";
    else
        std::cout << "It's a draw !\n";
}
