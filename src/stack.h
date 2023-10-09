#pragma once

#include <memory>

template <typename E>
class Stack {
    std::unique_ptr<E[]> stack;
    int capacity;
    int size;
public:

    class StackEmpty {};
    class StackFull {};

    Stack(int cap) {
        stack = std::make_unique<E[]>(cap);
        capacity = cap;
        size = 0;
    }
    int getSize() const {
        return size;
    }
    bool isEmpty() const {
        return size == 0;
    }
    const E& top() {
        if (isEmpty()) {
            throw StackEmpty();
        }
        return stack[size - 1];
    }
    void push(const E& e) {
        if (size == capacity) {
            throw StackFull();
        }
        stack[size++] = e;
    }
    E pop() {
        if (isEmpty()) {
            throw StackEmpty();
        }
        E e = top();
        size--;
        return e;
    }
};
