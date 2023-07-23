/**
 * @file mainwindow.cpp
 * @brief This file contains the main window of the game.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTimer>
#include <QFontMetrics>

/**
 * @brief Constructor for MainWindow.
 *
 * @param parent The parent widget. Defaults to nullptr.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), game(false) // game initialization
{
    ui->setupUi(this);

    // Set the main layout to the central widget
    this->centralWidget()->setLayout(ui->mainLayout);

    // Set stretch factors. The first argument is the index of the item, the second is the stretch factor
    ui->mainLayout->setStretchFactor(ui->gameGridLayout, 1);

    // Create QMessageBox for game mode selection
    QMessageBox gameModeSelection(this);
    gameModeSelection.setWindowTitle("Select Game Mode");
    gameModeSelection.setText("Which game mode do you want to play?");
    QPushButton* normalModeButton = gameModeSelection.addButton("Normal", QMessageBox::YesRole);
    QPushButton* vergerAllongeeModeButton = gameModeSelection.addButton("Verger Allongee", QMessageBox::NoRole);
    gameModeSelection.exec();

    if(gameModeSelection.clickedButton() == normalModeButton) {
        // start game in normal mode
        game = Game(false); // Initialize game with normal mode
        isVergerAllongeMode = false; // Store the game mode
    } else if(gameModeSelection.clickedButton() == vergerAllongeeModeButton) {
        // start game in verger allongee mode
        game = Game(true); // Initialize game with verger allongee mode
        isVergerAllongeMode = true; // Store the game mode
    }
    nextRound();
}

/**
 * @brief Destructor for MainWindow.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Updates the game grid. Clears all widgets from the layout,
 *        creates and sets a new push button for each cell.
 */
void MainWindow::updateGrid() {
    // first, clear all widgets from the layout
    QLayoutItem *item;
    while ((item = ui->gameGridLayout->takeAt(0)) != 0) {
        delete item->widget();
        delete item;
    }

    for (int i = 0; i < game.getRows(); ++i) {
        for (int j = 0; j < game.getCols(); ++j) {
            // create a push button
            QPushButton *cellButton = new QPushButton(this);

            QString cellValue = QString::fromStdString(game.getBoard()[i*game.getCols() + j]);

            // update the button text based on the game state
            cellButton->setText(cellValue);

            // color code based on cellValue
            QString backgroundColor;

            if(cellValue.endsWith('R')) {
                backgroundColor = "red";
                cellButton->setStyleSheet("background-color: " + backgroundColor + ";" + "color: white;");
            } else if(cellValue.endsWith('G')) {
                backgroundColor = "green";
                cellButton->setStyleSheet("background-color: " + backgroundColor + ";" + "color: white;");
            } else if(cellValue == "H") {
                backgroundColor = "#D2B48C"; // light brown in hexadecimal
                cellButton->setStyleSheet("background-color: " + backgroundColor + ";");
            } else if(cellValue == "X") {
                backgroundColor = "transparent"; // make the background disappear
                cellButton->setEnabled(false); // make the button non-clickable
            }

            if(backgroundColor.isEmpty()) {
                cellButton->setStyleSheet("background-color: " + backgroundColor + ";");
            }

            // set size policy to make the button expandable
            cellButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

            // connect the button click to the cellClicked slot
            connect(cellButton, &QPushButton::clicked, [this, i, j] { cellClicked(i, j); });
            // add the button to the grid layout
            ui->gameGridLayout->addWidget(cellButton, i, j);
        }
        ui->gameGridLayout->setRowStretch(i, 1);
    }
    for (int j = 0; j < game.getCols(); ++j) {
        ui->gameGridLayout->setColumnStretch(j, 1);
    }
}

/**
 * @brief Sets up the next round of the game.
 *
 * It updates the turn indicator, game grid, and players' apple counts.
 */
void MainWindow::nextRound() {
    // update the turn indicator
    ui->turnIndicatorLabel->setText(game.getIsPlayer1Turn() ? "Player 1's turn !" : "Player 2's turn !");

    // update the game grid
    updateGrid();

    // update the player's apples count
    const Player& player1 = game.getPlayer1();
    const Player& player2 = game.getPlayer2();
    ui->player1GreenApplesLabel->setText(QString::number(player1.greenApples));
    ui->player1RedApplesLabel->setText(QString::number(player1.redApples));
    ui->player2GreenApplesLabel->setText(QString::number(player2.greenApples));
    ui->player2RedApplesLabel->setText(QString::number(player2.redApples));
}

/**
 * @brief Checks who the winner is and shows the result.
 *
 * It calculates the difference of each player's red and green apples from 11,
 * determines the winner or if there's a draw, and displays the result.
 * Then it starts a new game.
 */
void MainWindow::checkWinnerAndShowResult() {
    const Player& player1 = game.getPlayer1();
    const Player& player2 = game.getPlayer2();

    int player1Diff = std::abs(player1.redApples - 11) + std::abs(player1.greenApples - 11);
    int player2Diff = std::abs(player2.redApples - 11) + std::abs(player2.greenApples - 11);

    QString message;
    if (player1.redApples > 11 || player1.greenApples > 11)
        message = "Player 2 wins !";
    else if (player2.redApples > 11 || player2.greenApples > 11)
        message = "Player 1 wins !";
    else if (player1Diff < player2Diff)
        message = "Player 1 wins !";
    else if (player2Diff < player1Diff)
        message = "Player 2 wins !";
    else
        message = "It's a draw !";

    QMessageBox::information(this, "Game Over", message);

    game = Game(isVergerAllongeMode); // Create a new game
    nextRound();   // Refresh the board and the UI
}

/**
 * @brief Handles the cell click event.
 *
 * It validates the move, makes the move, updates the grid, and starts the next round if the move is valid.
 * Otherwise, it shows an "Invalid move" message.
 *
 * @param row The row number of the clicked cell.
 * @param col The column number of the clicked cell.
 */
void MainWindow::cellClicked(int row, int col) {
    if(game.isMoveValid(row, col)) { // Check if move is valid
        game.makeMove(row, col); // If valid, make the move
        updateGrid(); // Update the grid
        nextRound(); // Automatically start the next round
        if(game.checkEndGame()) { // Check if game has ended
            checkWinnerAndShowResult();
        }
    } else {
        ui->statusbar->setStyleSheet("color: red"); // set text color to red
        ui->statusbar->showMessage("Invalid move !"); // display message in the status bar
        QTimer::singleShot(1000, [this]() { // clear message and reset color after 1 second
            ui->statusbar->clearMessage();
            ui->statusbar->setStyleSheet("color: black"); // reset text color to black
        });
    }
}
