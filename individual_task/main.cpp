#include <iostream>
#include <stack>
#include <queue>
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
        cout << reversed.top();
        reversed.pop();

        if (!reversed.empty())
            cout << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    stack<int> original;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        original.push(number);
        pq.push(number);
    }

    stack<int> reversed = reverse_copy(original);

    print_bottom_to_top(original);
    print_bottom_to_top(reversed);

    while (!pq.empty()) {
        cout << pq.top();
        pq.pop();

        if (!pq.empty())
            cout << " ";
    }
    cout << endl;

    return 0;
}
