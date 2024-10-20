#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree {    
    // public:
    //     BinarySearchTree(int value) {
    //         Node* newNode = new Node(value);
    //         root = newNode;
    //     } 

    public:
        Node* root;
        BinarySearchTree() {
           root = nullptr; 
        }

    bool insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return true;
        }
        Node* temp = root;
        while (true) {
            if (newNode->value == temp->value) return false;
            if (newNode->value < temp->value) {
                if (temp->left == nullptr){
                temp->left = newNode;
                return true;
            }
            temp = temp->left;         
            } else {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            } 
        }
    }

    bool contains(int value) {
        // not needed due to while loop
        // if (root == nullptr) return false;
        Node* temp = root;
        while ( temp) {
            if (value < temp->value) {
                temp = temp->left;
            } else if (value > temp->value) {
                temp = temp->right;
            } else {                
                return true;
            }
        }
        return false;
    }          
};

int main() {
    // Makes it so that the true and false are said and not shown as 1 or 0
    std::cout << std::boolalpha;

    BinarySearchTree* myBST = new BinarySearchTree();
    
    // prints location of the Root Node
    // cout << "Root: " << myBST->root;

    // Insert of root, parent, and leaf(s) of BST:
    myBST->insert(47); // Root
    myBST->insert(21); // left
    myBST->insert(76); // right
    myBST->insert(18); // left-left
    myBST->insert(52); // right-left
    myBST->insert(82); // right-right

    // Insert of left-right node in the BST: (Test for code above for Insert Fucntion)
    myBST->insert(27);
    cout << myBST->root->left->right->value << endl;

    cout << "Contains 18: " << myBST->contains(18) << endl;
    cout << "Contains 99: " << myBST->contains(99) << endl;
    cout << "Contains 52: " << myBST->contains(52) << endl;
}