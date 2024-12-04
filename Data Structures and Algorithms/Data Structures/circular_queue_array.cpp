#include <iostream>
using namespace std;

template <typename T>
class CircularQueue {
private:
    int front, rear, length;
    T* queue;

    void resize() {
        T* temp = new T[length * 2];
        int i = 0;
        int j = front;
        do {
            temp[i++] = queue[j];
            j = (j + 1) % length;
        } while (j != front);
        front = 0;
        rear = length - 1;
        length *= 2;
        delete[] queue;
        queue = temp;
        cout << "Resized\n";
    }

public:
    CircularQueue(int size) : front(-1), rear(-1), length(size) {
        queue = new T[size];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (rear + 1) % length == front;
    }

    void enqueue(T data) {
        if (isFull())
            resize();
        if (isEmpty())
            front++;
        rear = (rear + 1) % length;
        queue[rear] = data;
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
            front = (front + 1) % length;
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
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % length;
        } while (i != (rear + 1) % length);
        cout << "\n";
    }
};

int main() {
    CircularQueue<int> intQueue(2);
    intQueue.enqueue(10);
    intQueue.display();
    intQueue.enqueue(20);
    intQueue.display();
    intQueue.enqueue(30);
    intQueue.display();
    cout << "Peek: " << intQueue.peek() << "\n";
    intQueue.dequeue();
    intQueue.display();

    CircularQueue<string> stringQueue(3);
    stringQueue.enqueue("Alice");
    stringQueue.enqueue("Bob");
    stringQueue.enqueue("Charlie");
    stringQueue.display();
    cout << "Peek: " << stringQueue.peek() << "\n";
    stringQueue.dequeue();
    stringQueue.display();

    return 0;
}
