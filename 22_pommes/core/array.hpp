#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>
#include <stdlib.h>

/**
 * This class models a standard array with basic operations
 * of setting, getting and swapping elements.
 * <p>
 * The template parameter is the type of the datas stored in the array.
 * <p>
 * These arrays can be built up by specifying their initial size, in
 * which case while momory is allocated for the elements to stored, their value
 * is indetermined. On the other hand, it is possible to specify both the size
 * of the array, as well as the elements to store, by specifying a memory space
 * to copy from. Finally, it is also possible to instanciate an array using the
 * initialiser list.
 * <p>
 * For example, one can create an array using one of the following ways :<br>
 * <code>Array<int> ar(4);</code><br><br>
 * <code>int t[] = {1,2,3,4};</code><br>
 * <code>Array<int> ar2(4,t);</code><br><br>
 * <code>Array<int> ar3 = {1,2,3,4};</code><br>
 * <p>
 * Getting elements from arrays can be done using the [] operator, while setting
 * them is only possible by using the Array<T>::set(int,T) member function. This
 * choice is made based on academic reasons : since the purpose of this class is
 * to be observed, it is necessary to prevent a single function (the [] operator)
 * to be able to perform an action (set) than cannot be traced.
 * @brief This class simply models an array.
 * @tparam T The type of the stored datas
 */
template<class T>
class Array
{
    int n;
    T * array;

    public:
        /**
         * Builds up an empty array with <code>n</code> elements.
         * <p>
         * Note that initially, the allocated memory is not set to any
         * kind of specific value. Hence, getting unset elements from
         * this allocated memory may result in unpredictable values.
         * @brief Builds up an empty array with <code>n</code> elements.
         * @param n the number of elements of the underlying array.
         * @throw std::invalid_argument if the size of the array is negative.
         */
        Array(int n);

        /**
         * Builds up an array with <code>n</code> elements copied from
         * a specified memory space.
         * <p>
         * Note that no particular bound control is made in this specifid
         * constructor. Hence, reading too many elements from a memoty space
         * too tiny may result in unpredictable results, such as random values
         * or segmentation faults.
         * @brief Builds up an array with <code>n</code> elements copied
         * from a specified memory space.
         * @param n the number of elements to copy from memory.
         * @param array the adress of the memory space to cpy elements
         * from.
         * @throw std::invalid_argument if the size of the array is negative.
         */
        Array(int n, T * array);

        /**
         * Builds up an array from an initialiser list.
         * <p>
         * For example, an array can be created using the following sample :<br>
         * <code>
         * Array<int> ar = {1, 2, 3, 4};
         * </code>
         * @brief Builds up an array from an initialiser list.
         * @param list the initialiser list provided by instanciation.
         */
        Array(std::initializer_list<T> list);

        /**
         * Standard copy constructor for the underlying array.
         * <p>
         * Every single element of the array to build is affected
         * to the elements of the specified array.
         * @brief Standard copy constructor for the underlying array.
         * @param array the array to copy.
         */
        Array(const Array<T>& array);

        /**
         * Standard destructor for the underlying array.
         * <p>
         * Memory allocated by instanciation is set free by this call.
         * @brief ~Array Standard destructor for the underlying array.
         */
        virtual ~Array();

        /**
         * Standard affectation operator for the underlying array.
         * <p>
         * Firstly, memory allocated by instanciation of the underlying
         * array is set free by this call. Then, every single element of
         * the array to build is affected to the elements of the specified
         * array.
         * <p>
         * Note that no affectation is done if the specified array is the same
         * (by adress) as the underlying array.
         * @brief operator = Standard affectation operator for the underlying
         * array.
         * @param array the array to affect.
         * @return a reference to the underlying array after affectation.
         */
        virtual Array<T>& operator =(const Array<T>& array);

        /**
         * This operator simply returns the element indexed at the specified
         * position in the underlying array.
         * <p>
         * Note that this operator returns a constant reference to the returned
         * element, in order to deliberately prevent the user from setting an
         * element in the array through this call. This
         * choice is made based on academic reasons : since the purpose of this
         * class is to be observed, it is necessary to prevent a single function
         * (the [] operator) to be able to perform an action (set) than cannot be
         * traced.
         * @brief This operator simply returns the element indexed at the specified
         * position in the underlying array.
         * @param i the index of the element to get
         * @return the element indexed at the specified position in the underlying
         * array.
         */
        inline virtual const T& operator[] (int i) const;

        /**
         * Sets the element indexed at the specified index to the given value.
         * @brief Sets the element indexed at the specified index to the given
         * value.
         * @param i the index of the element to set
         * @param data the element to set
         */
        virtual void set(int i, T data);

        /**
         * Swaps two elements indexed at the specified positions.
         * @brief Swaps two elements indexed at the specified positions.
         * @param i the index of the first element to swap
         * @param j the index of the second element to swap
         */
        virtual void swap(int i, int j);

        /**
         * Returns the size of the underlying array.
         * @brief Returns the size of the underlying array.
         * @return the size of the underlying array.
         */
        inline virtual int size() const;

    private:
        //check if index i lies within range of the underlying array
        inline void rangeCheck(int i) const;
};

template<class T>
Array<T>::Array(int n) : n(n)
{
    if(n < 0)
        throw std::invalid_argument("Size cannot be negative");

    //yeah, I know, it's ugly
    //I don't want to call the default constructor of T
    //I also don't wanna flag allocated elements for performance issues
    array = static_cast<T*>(malloc(n * sizeof(T)));
}

template<class T>
Array<T>::Array(int n, T * array) : Array(n)
{
    for(int i = 0; i < n; i++)
        this->array[i] = array[i];
}

template<class T>
Array<T>::Array(std::initializer_list<T> list) : Array(list.size())
{
    int i = 0;
    for(auto t : list)
    {
        this->array[i] = t;
        i++;
    }
}

template<class T>
Array<T>::Array(const Array<T> &array) : Array(array.size())
{
    for(int i = 0; i < n; i++)
        this->array[i] = array[i];
}

template<class T>
Array<T>::~Array()
{
    //I allocated with malloc...
    free(array);
}

template<class T>
Array<T>& Array<T>::operator =(const Array<T>& array)
{
    if(this != &array)
    {
        free(this->array);//I allocated with malloc

        n = array.size();

        //I don't wanna call the default constuctor of T
        //or flag allocated elements
        this->array = (T*)malloc(n * sizeof(T));
        for(int i = 0; i < n; i++)
            this->array[i] = array[i];
    }
    return *this;
}

template<class T>
const T& Array<T>::operator [](int i) const
{
    rangeCheck(i);

    return array[i];
}

template<class T>
void Array<T>::set(int i, T data)
{
    rangeCheck(i);

    array[i] = data;
}

template<class T>
void Array<T>::swap(int i, int j)
{
    rangeCheck(i);
    rangeCheck(j);

    T tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

template<class T>
int Array<T>::size() const
{
    return n;
}

template<class T>
void Array<T>::rangeCheck(int i) const
{
    if(i < 0 || i >= n)
        throw std::out_of_range("Index out of range");
}

#endif // ARRAY_H
