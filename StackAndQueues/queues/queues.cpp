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

};

int main() {
    Queue* myQueue = new Queue(12);

    myQueue->getFirst();
    myQueue->getLast();
    myQueue->getLenght();

    myQueue->printQueue();
}