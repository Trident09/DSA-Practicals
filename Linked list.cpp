#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    void append(int data) {
        if (head == nullptr) {
            head = new Node(data);
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(data);
    }

    void prepend(int data) {
        Node* newHead = new Node(data);
        newHead->next = head;
        head = newHead;
    }

    void deleteWithValue(int data) {
        if (head == nullptr) {
            return;
        }
        if (head->data == data) {
            head = head->next;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == data) {
                current->next = current->next->next;
                return;
            }
            current = current->next;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.prepend(0);
    list.printList();
    list.deleteWithValue(2);
    list.printList();
    return 0;
}
