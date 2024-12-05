#include <iostream>
using namespace std;

template <typename T>
class CircularQueue {
private:
    T* queue;
    struct node{
        T data;
        node* next;
    };
    node* rear;
    node* front;
    int length;

public:
    
    CircularQueue() : rear(NULL), front(NULL) {}

    void enqueue(T val) {
        node* newnode = new node;
        newnode->data = val;
        newnode->next = NULL;
        if (front == NULL) {
            front = rear = newnode;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue Empty!\n";
            return;
        }
        cout << "Dequeue " << front->data << "\n";
        if (front == rear) {
            delete front;
            front = rear = NULL;
        }
        else {
            node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void display() {
        if (front == NULL) {
            cout << "Queue Empty!\n";
            return;
        }
        cout << "Queue : ";
        node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp!=NULL);
        cout << "\n";
    }
};

int main() {
    CircularQueue<int> q;
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(2);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
