#include <iostream>

using namespace std;

class Node {
    public: 
        int value;
        Node* next;
        Node* prev;

    Node(int value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

    void printList() {
        Node* temp = head;
        if(temp == nullptr) {
                cout << "empty" << endl;;
            } else{
            while (temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
    }

    void getHead() {
        cout << "Head: " << head->value << endl;
    }

    void getTail() {
        cout << "Tail: " << tail->value << endl;
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            tail = newNode;
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteLast() {
        if (length == 0) return;
        Node* temp = tail;
        if ( length == 1) {
            tail = nullptr;
            head = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void deleteFirst() {

    }
};

int main () {
    // Creating a Doubly Linked List:
    DoublyLinkedList* myDLL = new DoublyLinkedList(5);
    myDLL->printList();

    // Append new Node at the end of DLL:
    myDLL->append(12);
    cout << endl << "Appended DLL:" << endl;
    myDLL->printList();

    // Prepend new Node at the front of DLL:
    myDLL->prepend(23);
    cout << endl << "Prepended DLL:" << endl;
    myDLL->printList();

    // Removing the last node in the DLL: 
    myDLL->deleteLast();
    cout << "\nDLL after first deleteLast function:\n";
    myDLL->printList();
    
    myDLL->deleteLast();
    cout << "\nDLL after second deleteLast function:\n";
    myDLL->printList();

    myDLL->deleteLast();
    cout << "\nDLL after third deleteLast function:\n";
    myDLL->printList();
}