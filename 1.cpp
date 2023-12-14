#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position < 1) {
            std::cerr << "Invalid position. Position should be >= 1.\n";
            return;
        }

        Node* newNode = new Node(value);

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            std::cerr << "Invalid position. Position exceeds the size of the list.\n";
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void removeFromBeginning() {
        if (isEmpty()) {
            std::cerr << "List is empty. Cannot remove from the beginning.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeFromPosition(int position) {
        if (isEmpty()) {
            std::cerr << "List is empty. Cannot remove from the specified position.\n";
            return;
        }

        if (position < 1) {
            std::cerr << "Invalid position. Position should be >= 1.\n";
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        for (int i = 1; i < position && current != nullptr; ++i) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cerr << "Invalid position. Position exceeds the size of the list.\n";
            return;
        }

        prev->next = current->next;
        delete current;
    }

    Node* search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    SinglyLinkedList sll;

    sll.insertAtBeginning(10);
    sll.insertAtBeginning(5);
    sll.insertAtPosition(20, 2);
    sll.insertAtPosition(30, 4);

    std::cout << "Singly Linked List: ";
    sll.display();

    sll.removeFromBeginning();
    sll.removeFromPosition(2);

    std::cout << "Singly Linked List after removal: ";
    sll.display();

    Node* searchResult = sll.search(20);
    if (searchResult != nullptr) {
        std::cout << "Element 20 found at address: " << searchResult << std::endl;
    } else {
        std::cout << "Element 20 not found.\n";
    }

    return 0;
}
