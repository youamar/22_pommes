/**
 * @file mainwindow.h
 * @brief Main window of the game.
 *
 * This file defines the MainWindow class, which is the main graphical user interface of the game.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "../core/game.h" // include the game class

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief The MainWindow class provides the GUI for the game.
 *
 * It includes all of the widgets needed to display and interact with the game.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for MainWindow.
     *
     * @param parent The parent widget. Defaults to nullptr.
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Destructor for MainWindow.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Sets up the next round of the game.
     */
    void nextRound();

    /**
     * @brief Handles the cell click event.
     *
     * @param row The row number of the clicked cell.
     * @param col The column number of the clicked cell.
     */
    void cellClicked(int row, int col);

private:
    Ui::MainWindow *ui; ///< User interface setup for MainWindow.
    Game game; ///< Instance of the game.

    QLabel *player1GreenApplesLabel; ///< Label to display Player 1's green apple count.
    QLabel *player1RedApplesLabel; ///< Label to display Player 1's red apple count.
    QLabel *player2GreenApplesLabel; ///< Label to display Player 2's green apple count.
    QLabel *player2RedApplesLabel; ///< Label to display Player 2's red apple count.

    /**
     * @brief Updates the game grid.
     */
    void updateGrid();

    /**
     * @brief Checks who the winner is and displays the result.
     */
    void checkWinnerAndShowResult();

    bool isVergerAllongeMode; ///< Mode of the game: true for Verger Allonge mode, false for normal mode.
};


#endif // MAINWINDOW_H
