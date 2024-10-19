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

class Stack {
    private:
        Node* top;
        int height;
    
    public:
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void printStack() {
            Node* temp = top;
            while(temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getTop(){
            cout << "Top is: " << top->value << endl;
        }

        void getHeight(){
            cout << "Height is: " << height << endl;
        }

};

int main() {
    Stack* myStack = new Stack(6);

    myStack->getTop();
    myStack->getHeight();
    myStack->printStack();


}