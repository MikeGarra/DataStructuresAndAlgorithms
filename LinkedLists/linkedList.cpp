#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        // Constructor
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        // Deconstructor
        ~LinkedList() {
            Node* temp = head;
            while(head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        // Prints the nodes in the LL
        void printList() {
            Node* temp = head;
            if(temp == nullptr) {
                cout << "empty" << endl;;
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp-> next;
                    if (temp != nullptr)
                        cout << " -> ";
                }
                cout << endl;
            }
        }

        Node* getHead() {
            return head;
            cout << endl;
        }

        Node* getTail() {
            return tail;
            cout << endl;
        }

        int getLength() {
            return length;
            cout << endl;
        }

        // Adds a new node to the LL in the end 
        // Creates new tail
        void append(int value) {
            Node* newNode = new Node(value);
            if(length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        // Adds a new node to the LL in the front 
        // Creates new head
        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        // Location of the index for a certain Node
        Node* get(int index) {
            if(index < 0|| index >= length) {
                return nullptr;
            }
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }

        // Change of a specific node's value
        bool set(int index, int value) {
            Node* temp = get(index);
            if (temp) {
                temp->value = value;
                return true;
            }
            return false;
        }

        // Inserting a new node at a specific location in the LL
        bool insert(int index, int value) {
            if (index < 0 || index >= length) return false;
            if (index == 0) {
                prepend(value);
                return true;
            }
            if ( index == length) {
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }

        // Deletes the last node and moves the tail to the previous node in the LL
        void deleteLast() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node* pre = head;
                while (temp->next != nullptr) {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }            
            delete temp;
            length--;
        }

        // Deletes the first node and moves the head to the next node in the LL
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }

        // Delete a Node at any location in the LL
        void deleteNode(int index) {
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst();
            if (index == length - 1) return deleteLast();
            
            Node* prev = get(index - 1);
            Node* temp = prev->next;

            prev->next = temp->next;
            delete temp;
            length--;
        }

        // Reverses the flow of the LL changing the Head and Tail locations
        void reverse() {
            Node* temp = head;
            head = tail;
            tail = temp;
            Node* after = temp->next;
            Node* before = nullptr;

            for (int i = 0; i < length; i++) {
                after = temp->next;
                temp->next = before;
                // Needed due to the above two lines cutting the connection in the LL
                before = temp;
                temp = after;
            }
        }
};

int main() {

    LinkedList* myLinkedList = new LinkedList(38);
    // Print LL function:
    myLinkedList->printList();

    // append function:
    myLinkedList->append(24);
    myLinkedList->printList();

    myLinkedList->append(32);
    myLinkedList->printList();

    // prepend function:
    myLinkedList->prepend(14);
    myLinkedList->printList();

    // Print of Get functions:
    cout << "Head: " << myLinkedList->getHead()->value << endl;;
    cout << "Tail: "<< myLinkedList->getTail()->value << endl;
    cout << "Length: "<< myLinkedList->getLength() << endl;
    cout << "Index: "<< myLinkedList->get(2)->value << endl;

    // Reverse of the LL function:
    cout << endl;
    cout << "LL in Reverse: " << endl;
    myLinkedList->reverse();
    myLinkedList->printList();
    cout << endl;

    // Intitalization of set function and print of changes:
    myLinkedList->set(1, 60);
    cout << "New Linked List: " << endl;
    myLinkedList->printList();

    // Insert of a new node in the LL:
    myLinkedList->insert(3, 99);
    cout << "New Node Inserted to the LL: " << endl;
    myLinkedList->printList();

    // deleteNode function:
    myLinkedList->deleteNode(2);
    cout << "Node deleted: " << endl;
    myLinkedList->printList();

    cout << "LL Before deleteLast(): \n";
    myLinkedList->printList();

    // deleteLast functions:
    myLinkedList->deleteLast();
    cout << "\nLL after first deleteLast():\n";
    myLinkedList->printList();

    myLinkedList->deleteLast();
    cout << "\nLL after second deleteLast():\n";
    myLinkedList->printList();

    // deleteLast functions:
    myLinkedList->deleteFirst();
    cout << "\nLL after first deleteFirst():\n";
    myLinkedList->printList();

    myLinkedList->deleteFirst();
    cout << "\nLL after second deleteFirst():\n";
    myLinkedList->printList();

    delete myLinkedList;

}