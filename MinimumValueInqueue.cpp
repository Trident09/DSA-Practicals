#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

void enqueue(int x) {
    q.push(x);
}

void dequeue() {
    if (q.empty()) {
        cout << "Error: Queue is empty" << endl;
        return;
    }
    q.pop();
}

int frontValue() {
    if (q.empty()) {
        cout << "Error: Queue is empty" << endl;
        return -1;
    }
    return q.top();
}

int getMin() {
    return q.top();
}

int main() {
    enqueue(5);
    enqueue(3);
    enqueue(2);
    enqueue(4);
    cout << "Minimum value: " << getMin() << endl
