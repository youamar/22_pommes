#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>

#include "observer.h"

/**
 * @brief The Observable class provides an implementation of the Observable part of the Observer design pattern.
 *
 * This class maintains a list of Observer objects and provides methods to add, remove, and notify them.
 */
class Observable {
private:
    std::vector<Observer*> observers; ///< List of Observer pointers observing this object.

public:
    /**
     * @brief Adds an observer to the list of observers.
     * @param observer Pointer to the Observer object to be added.
     */
    void addObserver(Observer* observer);

    /**
     * @brief Removes an observer from the list of observers.
     * @param observer Pointer to the Observer object to be removed.
     */
    void removeObserver(Observer* observer);

    /**
     * @brief Notifies all observers by calling their update() method.
     */
    void notifyObservers();
};

#endif // OBSERVABLE_H
