#include "Stack.hpp"

#define INITIAL_CAPACITY 100

template<typename T>
Stack<T>::Stack() {
    items = new T[INITIAL_CAPACITY];
    top = 0;
    capacity = INITIAL_CAPACITY;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] items;
}

template<typename T>
Stack<T>::Stack(const Stack &rhs) {
    top = rhs.top;
    capacity = rhs.capacity;
    items = new T[rhs.capacity];
    std::copy(rhs.items, rhs.items + rhs.top, items);
}

template<typename T>
size_t Stack<T>::size() const {
    return top;
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return top == 0;
}

template<typename T>
bool Stack<T>::push(const T &newItem) {
    if (top + 1 >= capacity) {
        capacity *= 2;
        T *temp = new T[capacity];
        std::copy(items, items + top, temp);
        delete[] items;
        items = temp;
    }
    items[top] = newItem;
    top++;
    return true;
}

template<typename T>
bool Stack<T>::pop() {
    if (!isEmpty()) {
        top--;
        return true;
    }
    return false;
}

template<typename T>
const T &Stack<T>::peek() const throw(std::range_error) {
    if (isEmpty()) {
        throw std::range_error("Empty Stack");
    }
    return items[top - 1];
}

template<typename T>
void Stack<T>::clear() {
    top = 0;
}