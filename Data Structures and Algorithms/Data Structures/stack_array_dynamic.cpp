//DYNAMIC VARIATION

#include <iostream>
using namespace std;

template<typename T>
class STACK_ARRAY {
    T *stack, top, maxsize;
public:
    STACK_ARRAY(int size);
    ~STACK_ARRAY();
    STACK_ARRAY& push(T);
    void resize(T);
    void pop();
    void print();
    bool isFull();
    bool isEmpty();
};
template<typename T>
STACK_ARRAY<T>::STACK_ARRAY(int size) {
    maxsize = size;
    stack = new int[maxsize];
    top = -1;
}
template<typename T>
STACK_ARRAY<T>::~STACK_ARRAY(){
    delete []stack;
}

template<typename T>
bool STACK_ARRAY<T>::isFull() {
    return top == maxsize-1;
}
template<typename T>
bool STACK_ARRAY<T>::isEmpty() {
    return top == -1;
}
template<typename T>
STACK_ARRAY<T>& STACK_ARRAY<T>::push(T value) {
    if (isFull()) {
        cout << "stack full\n";
        resize(10);
    }
    stack[++top] = value;
    return *this;
}
template<typename T>
void STACK_ARRAY<T>::resize(T size){
    int *tempStack = new int[maxsize + size];
    for (int i = 0; i < maxsize; i++) {
        tempStack[i] = stack[i];
    }
    maxsize += size;
    delete [] stack;
    stack = tempStack;
}
template<typename T>
void STACK_ARRAY<T>::pop() {
    if (isEmpty()) {
        cout << "Stack Empty\n";
        return;
    }
    stack[top] = T();
    top--;
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
    STACK_ARRAY<int> stk(2);
    stk.push(10).push(20).push(30);
    stk.print();
    stk.pop();
    stk.print();
}