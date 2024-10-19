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

class Queue {
    private:
        Node* first;
        Node* last;
        int length;
    public:
        Queue(int value) {
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }


    void printQueue() {
        Node* temp = first;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    void getFirst() {
        cout << "First: " << first->value << endl;
    }

    void getLast() {
        cout << "Last: " << last->value << endl;
    }

    void getLenght() {
        cout <<"Length: " << length << endl;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            first = newNode;
            last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    int dequeue() {
        if (length == 0) {
            cout << "Queue is empty." << endl;
            return INT_MIN;
        }
        Node* temp = first;
        int dequeueValue = first->value;
        cout << "Dequeued value: " << dequeueValue << endl;
        if (length == 1) {
            first = nullptr;
            last = nullptr;
        } else {
            first = first->next;
        }
        delete temp;
        length--;
        return dequeueValue;
    }
};

int main() {
    Queue* myQueue = new Queue(12);

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLenght();

    myQueue->printQueue();

    // Adding a new Node to the Queue with enqueue function:
    myQueue->enqueue(43);
    myQueue->printQueue();

    // Removing a node fromt the Queue with dequeue function:
    cout << "Removing Node from Queue:" << endl;
    myQueue->dequeue();
    myQueue->printQueue();

    cout << "Removing Node from Queue:" << endl;
    myQueue->dequeue();
    myQueue->printQueue();
    
    cout << "Removing Node from Queue:" << endl;
    myQueue->dequeue();
    myQueue->printQueue();
}