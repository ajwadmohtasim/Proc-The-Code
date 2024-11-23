#include <iostream>
using namespace std;
const int max_size = 100;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* topx; 
    int length; 

public:
    Stack();            
    ~Stack();          
    Node* init(T);      
    Stack& push(T);     
    bool pop();         
    T top();            
    bool isFull();    
    bool isEmpty();   
    void print();      
};

template <typename T>
Stack<T>::Stack() : topx(nullptr), length(0) {}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
typename Stack<T>::Node* Stack<T>::init(T n) {
    Node* newnode = new Node;
    newnode->data = n;
    newnode->next = nullptr;
    return newnode;
}

template <typename T>
Stack<T>& Stack<T>::push(T n) {
    if (isFull()) {
        cout << "Stack is full\n";
        return *this;
    }
    Node* newnode = init(n);
    newnode->next = topx;
    topx = newnode;
    length++;
    return *this;
}

template <typename T>
bool Stack<T>::pop() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return false;
    }
    Node* temp = topx;
    topx = topx->next;
    delete temp; 
    length--;
    return true;
}

template <typename T>
T Stack<T>::top() {
    if (isEmpty()) {
        throw runtime_error("Stack is empty");
    }
    return topx->data;
}

template <typename T>
bool Stack<T>::isEmpty() {
    return topx == nullptr;
}

template <typename T>
bool Stack<T>::isFull() {
    return length == max_size;
}

template <typename T>
void Stack<T>::print() {
    cout << "Current Stack: ";
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = topx;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Stack<int> stack;
    stack.push(10).push(20).push(30);
    stack.print();
    stack.pop();
    stack.print();
    return 0;
}
