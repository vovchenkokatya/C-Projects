#pragma once
#include <cstddef>
#include <stdexcept>
#include <utility>

namespace lab18 {

template <class T>
class Stack
{
    struct Node {
        T value;
        Node* next;
        Node(const T& value_, Node* next_ = nullptr) : value(value_), next(next_) {}
    };
    Node* head;
    std::size_t count;

    void clear() {
        while (head != nullptr) {
            Node* old = head;
            head = head->next;
            delete old;
        }
        count = 0;
    }

public:
    Stack() : head(nullptr), count(0) {}

    Stack(const Stack& other) : head(nullptr), count(0) {
        Node** tail = &head;
        try {
            for (Node* p = other.head; p != nullptr; p = p->next) {
                *tail = new Node(p->value);
                tail = &(*tail)->next;
                ++count;
            }
        } catch (...) {
            clear();
            throw;
        }
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            Stack copy(other);
            std::swap(head, copy.head);
            std::swap(count, copy.count);
        }
        return *this;
    }

    ~Stack() { clear(); }
    bool empty() const { return head == nullptr; }
    std::size_t size() const { return count; }

    void push(const T& value) {
        head = new Node(value, head);
        ++count;
    }

    const T& top() const {
        if (empty()) throw std::underflow_error("Stack is empty.");
        return head->value;
    }

    T pop() {
        if (empty()) throw std::underflow_error("Stack is empty.");
        T result = head->value;
        Node* old = head;
        head = head->next;
        delete old;
        --count;
        return result;
    }
};

}
