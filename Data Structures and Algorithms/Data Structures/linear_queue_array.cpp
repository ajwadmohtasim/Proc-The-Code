#include <iostream>
using namespace std;

template <typename T>
class LinearQueue {
private:
    int front, rear, capacity;
    T* queue;

public:
    LinearQueue(int size) : front(-1), rear(-1), capacity(size) {
        queue = new T[size];
    }

    ~LinearQueue() {
        delete[] queue;
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return rear == capacity - 1;
    }

    void enqueue(T data) {
        if (isFull()) {
            cout << "Queue full!\n";
            return;
        }
        if (isEmpty()) {
            front++;
        }
        queue[++rear] = data;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue Empty!\n";
            return T();
        }
        T temp = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return temp;
    }

    T peek() const {
        if (isEmpty()) {
            cout << "Queue Empty!\n";
            return T();
        }
        return queue[front];
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue Empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    LinearQueue<int> intQueue(5);
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.display();
    cout << "Peek: " << intQueue.peek() << "\n";
    intQueue.dequeue();
    intQueue.display();

    LinearQueue<string> stringQueue(3);
    stringQueue.enqueue("Alice");
    stringQueue.enqueue("Bob");
    stringQueue.enqueue("Charlie");
    stringQueue.display();
    cout << "Peek: " << stringQueue.peek() << "\n";
    stringQueue.dequeue();
    stringQueue.display();

    return 0;
}
