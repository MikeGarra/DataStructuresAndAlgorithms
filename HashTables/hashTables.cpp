#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        string key;
        int value;
        Node* next;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

    public:

        ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }

        void printTable() {
            for (int i = 0; i < SIZE; i++) {
                cout << i << ":" << endl;
                if (dataMap[i]) {
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "  {" << temp->key << ", " << temp->value << "}" << endl;
                        temp = temp->next;
                    }
                }
            }
        }

        int hash(string key) {
            int hash = 0;
            for ( int i = 0; i < key.length(); i++) {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue * 23) % SIZE;
            }
            return hash;
        }

        void set(string key, int value) {
            int index = hash(key);
            Node* newNode = new Node(key, value);
            
            if (dataMap[index] == nullptr) {
                dataMap[index] = newNode;
            } else {
                Node* temp = dataMap[index];
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        int get(string key) {
            int index = hash(key);
            Node* temp = dataMap[index];
            while (temp !=nullptr) {
                if (temp->key == key) return temp->value;
                temp = temp->next;
            }
            return 0;
        }

        vector<string> keys() {
            vector<string> allKeys;
            for (int i = 0; i < SIZE; i++) {
                Node* temp = dataMap[i];
                while (temp != nullptr) {
                    allKeys.push_back(temp->key);
                    temp = temp->next;
                }
            }
            return allKeys;
    }
};

int main() {
    // Creation of hashtable - myHashTable
    HashTable* myHashTable = new HashTable();

    // Setting keys and values in the hashtable:
    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    myHashTable->set("bolts", 200);
    myHashTable->set("screws", 140);

    // Print the hashtable:
    myHashTable->printTable();

    // Get the values of the indicated key:
    cout << "\nLumber: " << myHashTable->get("lumber") << endl;
    // Not a key value pair in hashtable
    cout << "Pipe: " << myHashTable->get("pipe") << endl;

    // Display of all keys in the vector of the hashtable:
    vector<string> myKeys = myHashTable->keys();
    for (auto key : myKeys) {
        cout << key << " ";
    }
}