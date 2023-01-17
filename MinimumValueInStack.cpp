#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int minVal;

void push(int x) {
    if (s.empty()) {
        s.push(x);
        minVal = x;
    }
    else {
        if (x < minVal) {
            s.push(2*x - minVal);
            minVal = x;
        }
        else {
            s.push(x);
        }
    }
}

void pop() {
    if (s.empty()) {
        cout << "Error: Stack is empty" << endl;
        return;
    }
    int temp = s.top();
    s.pop();
    if (temp < minVal) {
        minVal = 2*minVal - temp;
    }
}

int getMin() {
    return minVal;
}

int main() {
    push(3);
    push(5);
    push(2);
    push(1);
    push(1);
    push(4);
    cout << "Minimum value: " << getMin() << endl;
    pop();
    cout << "Minimum value: " << getMin() << endl;
    pop();
    cout << "Minimum value: " << getMin() << endl;
    return 0;
}
