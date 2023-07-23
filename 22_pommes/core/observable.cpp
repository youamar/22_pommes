#include "observable.h"

#include <iostream>

/**
 * @brief Add an observer to the Observable object's list of observers.
 *
 * @param observer Pointer to the observer to be added.
 */
void Observable::addObserver(Observer* observer) {
    observers.push_back(observer);
}

/**
 * @brief Remove an observer from the Observable object's list of observers.
 *
 * @param observer Pointer to the observer to be removed.
 */
void Observable::removeObserver(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

/**
 * @brief Notify all observers in the Observable object's list of observers.
 * This function calls the update method of all registered observers.
 */
void Observable::notifyObservers() {
    for (Observer* observer : observers) {
        observer->update();
    }
}
