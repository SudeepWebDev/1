#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr; // If dequeued the last element, update rear
        }
    }

    T getFront() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty. No front element.\n";
            throw std::out_of_range("Queue is empty.");
        }
        return front->data;
    }

    T getRear() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty. No rear element.\n";
            throw std::out_of_range("Queue is empty.");
        }
        return rear->data;
    }
};

int main() {
    Queue<int> myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element: " << myQueue.getFront() << std::endl;
    std::cout << "Rear element: " << myQueue.getRear() << std::endl;

    myQueue.dequeue();

    std::cout << "Front element after dequeue: " << myQueue.getFront() << std::endl;

    return 0;
}
