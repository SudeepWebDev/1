#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    ~CircularLinkedList() {
        if (!isEmpty()) {
            Node* current = head->next;
            while (current != head) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            delete head;
        }
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            head->next = head; // Circular link to itself
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            last->next = newNode;
            newNode->next = head;
        }
    }

    void remove(int value) {
        if (isEmpty()) {
            std::cerr << "List is empty. Cannot remove.\n";
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        // Traverse the list to find the node with the specified value
        do {
            if (current->data == value) {
                break;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        // If the value is found, remove the node
        if (current != head) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                // If the first node is the one to be removed, update head
                head = head->next;
            }
            delete current;
        } else {
            std::cerr << "Element not found in the list.\n";
        }
    }

    Node* search(int value) {
        if (isEmpty()) {
            std::cerr << "List is empty. Cannot search.\n";
            return nullptr;
        }

        Node* current = head;

        // Traverse the list to find the node with the specified value
        do {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        } while (current != head);

        std::cerr << "Element not found in the list.\n";
        return nullptr;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(10);
    cll.insert(20);
    cll.insert(30);

    Node* searchResult = cll.search(20);
    if (searchResult != nullptr) {
        std::cout << "Element 20 found at address: " << searchResult << std::endl;
    }

    cll.remove(20);

    searchResult = cll.search(20);
    if (searchResult == nullptr) {
        std::cout << "Element 20 not found after removal.\n";
    }

    return 0;
}
