#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>

#include "iObserver.h"
#include "board.h"

Board::Board() :
    SIZE {BoardSize},
    score {Score()},
    currentPlayer (1),
    playersAmount (2) {
    this->playersBoard = new
        std::array<std::array<int, BoardSize>, BoardSize>;
}

Board::~Board() {
    for ( int i = 0; i < this->SIZE; i++ ) {
        for ( int j = 0; j < this->SIZE; j++ ) {
            if (this->grid.at(i).at(j) != nullptr) {
                delete this->grid.at(i).at(j);
            }
        }
    }
}

void Board::init() {

}

void Board::nextPlayer() {
    this->currentPlayer = ((this->currentPlayer + 1) >
                           this->playersAmount) ? 1 : this->currentPlayer + 1;
    this->notify("currentPlayer", &currentPlayer);
}

std::array<std::array<int, BoardSize>, BoardSize> *

Board::getPlayersBoard() {
    for ( int i = 0; i < this->SIZE; i++ ) {
        for ( int j = 0; j < this->SIZE; j++ ) {
            if (this->grid.at(i).at(j) != nullptr) {
                playersBoard->at(i).at(j) = this->grid.at(i).at(j)->getPlayer();
            }
            else {
                playersBoard->at(i).at(j) = -1;
            }
        }
    }
    return playersBoard;
}

bool Board::isInBounds(Position coord) {

    if (coord.getX() >= BoardSize || coord.getY() >= BoardSize) {
        return false;
    }

    int shift = 4;
    int lowerShift = 0;
    int toCheckX = coord.getX();
    int toCheckY = coord.getY();

    for ( int i = 0; i < BoardSize; i++ ) {
        int p = 0;
        for ( int j = 0; j < BoardSize; j++ ) {
            bool toCheck = i == toCheckX && j == toCheckY;
            if (lowerShift > 0 && (j + lowerShift) == BoardSize + p) {
                ++p;
                //invalide
                //important de mettre ici le if pour ++p
                if (toCheck) {
                    return false;
                }
            }
            else if (j < shift && toCheck) {
                //invalide
                return false;
            }
            else if (toCheck) {
                //valide
                return true;
            }
        }
        shift--;
        if (shift < 0) {
            lowerShift++;
        }
    }
    return false;
}

bool Board::isMovable(Position coord, eDirection direction) {

}

void Board::move(Position coord, const eDirection direction) {

}

bool Board::isWon() {
    auto highestPlayer = this->score.getPlayerHighestScore();
    auto scoreHighestPlayer = this->score.getScore(*highestPlayer);
    return scoreHighestPlayer >= 6;
}

int Board::getScorePlayer(const int player) {
    return this->score.getScore(player);
}

int * Board::getPlayerHighestScore() {
    return this->score.getPlayerHighestScore();
}

void Board::addObserver(iObserver * observer) {
    observers.push_back(observer);
    this->score.addObserver(observer);
}

void Board::removeObserver(iObserver * observer) {
    observers.remove(observer);
    this->score.removeObserver(observer);
}

void Board::notify(std::string name, void * object) {
    for (iObserver * o : observers) {
        o->update(name, object);
    }
}
