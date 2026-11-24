//
// Created by Katya on 24.11.2026.
//
#include <iostream>
#include <stack>
using namespace std;

stack<int> reverse_copy(stack<int> s) {
    stack<int> result;

    while (!s.empty()) {
        result.push(s.top());
        s.pop();
    }

    return result;
}

void print_bottom_to_top(stack<int> s) {
    stack<int> reversed = reverse_copy(s);

    while (!reversed.empty()) {
        cout << reversed.top() << " ";
        reversed.pop();
    }

    cout << endl;
}

int main() {
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    stack<int> reversed = reverse_copy(s);

    print_bottom_to_top(s);
    print_bottom_to_top(reversed);

    return 0;
}