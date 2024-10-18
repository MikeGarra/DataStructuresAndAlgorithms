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

    Node* get(int index) {
        if (index <0 ||index >= length) return nullptr; 
        Node* temp = head;
        if (index < length/2) {
            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = length - 1; i > index; i--) {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
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

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;
            if (index == 0) {
                prepend(value);
                return true;
            }
            if (index == length) {
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* before = get (index - 1);
            Node* after = before->next;
            newNode->prev = before;
            newNode->next = after;
            before->next = newNode;
            after->prev = newNode;
            length++;
            return true;
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
        if (length ==0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();
        
        Node* temp = get(index);

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
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

    // Insert of a new node in the DLL:
    cout << "Insert of new Value: " << endl;
    myDLL->insert(1, 99);
    myDLL->printList();

    // Locating an index with Get Function:
    cout << "\nValue at index 2 is: ";
    cout << myDLL->get(2)->value <<endl;

    // Changing a value in the DLL using Set function:
    myDLL->set(1, 55);
    cout << "\nSet Function implemented: " << endl;
    myDLL->printList();

    // Delete a specific Node in DLL:
    cout << "\nDeletion of specific node:" << endl;
    myDLL->deleteNode(3);
    myDLL->printList();

    // Removing the first node in DLL:
    myDLL->deleteFirst();
    cout << "\nDLL after first deleteFirst function:\n";
    myDLL->printList();

    // Removing the last node in DLL: 
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