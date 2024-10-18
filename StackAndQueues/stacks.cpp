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

        void printStack(){
            Node* temp = top;
            while(top) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getTop(){
            cout << "Top is: " << top << endl;
        }

        void getheight(){
            cout << "Height is: " << height << endl;
        }

};

int main() {

}