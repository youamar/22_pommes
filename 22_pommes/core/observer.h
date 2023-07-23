#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief The Observer class is the base class for any observer objects in an implementation of the Observer design pattern.
 *
 * This class includes a virtual destructor and a pure virtual method for updating the state of the Observer.
 */
class Observer {
public:
    /**
     * @brief Virtual default destructor.
     *
     * It is a good practice to always add a virtual destructor in the base class, even if it does nothing. This allows an object of a derived class to be deleted properly using a pointer to the base class.
     */
    virtual ~Observer() = default;

    /**
     * @brief Updates the state of this Observer.
     *
     * This method is called when the Observable object it is registered to changes state. It must be implemented in any derived classes.
     */
    virtual void update() = 0;
};

#endif // OBSERVER_H
