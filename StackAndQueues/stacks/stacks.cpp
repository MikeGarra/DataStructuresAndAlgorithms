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

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop() {
            if (height == 0) { 
                cout << "Stack is empty";
                return INT_MIN;
                }

            Node* temp = top;
            int poppedValue = top->value;
            top = top->next;
            delete temp;
            height--;
            
            cout << poppedValue;
            return poppedValue;
        }
};

int main() {
    Stack* myStack = new Stack(6);

    myStack->getTop();
    myStack->getHeight();
    myStack->printStack();

    // Pushing a new Node to top of Stack:
    cout << "\nPushing new Node: " << endl;
    myStack->push(32);
    myStack->printStack();

    // Popping Node to get to previous Node:
    cout << "\nPopping new Node: " << endl;
    myStack->pop();

    cout << "\nPopping new Node: " << endl;
    myStack->pop();

    cout << "\nPopping new Node: " << endl;
    myStack->pop();

}