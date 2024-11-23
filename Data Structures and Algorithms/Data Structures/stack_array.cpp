#include <iostream>
using namespace std;
#define MAXSIZE 100

template<typename T>
class STACK_ARRAY {
    T stack[MAXSIZE];
    int top;
public:
    STACK_ARRAY() : top(-1) {}
    STACK_ARRAY& push(T);
    void pop();
    void print();
    bool isFull();
    bool isEmpty();
};
template<typename T>
bool STACK_ARRAY<T>::isFull() {
    return top == MAXSIZE-1;
}
template<typename T>
bool STACK_ARRAY<T>::isEmpty() {
    return top == -1;
}
template<typename T>
STACK_ARRAY<T>& STACK_ARRAY<T>::push(T value) {
    if (isFull()) {
        cout << "Stack Full\n";
        return *this;
    }
    stack[++top] = value;
    return *this;
}
template<typename T>
void STACK_ARRAY<T>::pop() {
    if (isEmpty()) {
        cout << "Stack Empty\n";
        return;
    }
    stack[top--];
}
template<typename T>
void STACK_ARRAY<T>::print() {
    if (isEmpty()) {
        cout << "Stack Empty\n";
        return;
    }
    cout << "STACK : ";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << "\n";
}

int main() {
    STACK_ARRAY<int> stk;
    stk.push(10).push(20).push(30);
    stk.print();
    stk.pop();
    stk.print();
}
