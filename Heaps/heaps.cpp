#include <iostream>
#include <vector>

using namespace std;

class Heap {
    private:
        vector<int> heap;

        int leftChild(int index) {
            return 2 * index + 1;
        }

        int rightChild(int index) {
            return 2 * index + 2;
        }

        int parent(int index) {
            return (index - 1) / 2;
        }

        void swap(int index1, int index2) {
            int temp = heap[index1];
            heap[index1] = heap[index2];
            heap[index2] = temp;
        }

    public:
        void insert(int value) {
            heap.push_back(value);
            int current = heap.size() - 1;
            
            while (current > 0 && heap[current] > heap[parent(current)]) {
                swap(current, parent(current));
                current = parent(current);
            }
        }

        void printHeap() {
            cout << "\n[";
            for (size_t i = 0; i < heap.size(); i++) {
                cout << heap[i];
                if (i < heap.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "]";
        }

        void sinkDown(int index) {
            int maxIndex = index;
            while (true) {
                int leftIndex = leftChild(index);
                int rightIndex = rightChild(index);
                if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex]) {
                    maxIndex = leftIndex;
                }

                if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]) {
                    maxIndex = rightIndex;
                }

                if (maxIndex != index) {
                    swap(index, maxIndex);
                    index = maxIndex;
                } else {
                    return;
                }
            }
        }

        int remove() {
            if (heap.empty()) {
                return INT_MIN;
            }
            int maxValue = heap.front();

            if (heap.size() == 1) {
                heap.pop_back();
            } else {
                heap[0] = heap.back();
                heap.pop_back();
                sinkDown(0);
            }
            return maxValue;
        }
};

int main() {
    // Creating a new Heap:
    Heap* myHeap = new Heap();

    // Inserting indices to the Heap:
    myHeap->insert(99);
    myHeap->insert(72);
    myHeap->insert(61);
    myHeap->insert(58);

    // Display the Heap:
    cout << "First Heap: " << endl;
    myHeap->printHeap();

    // Testing insert Function:
    myHeap->insert(100);
    myHeap->printHeap();

    myHeap->insert(75);
    myHeap->printHeap();

    // Creating a Second Heap:
    Heap* myHeap2 = new Heap();

    myHeap2->insert(96);
    myHeap2->insert(75);
    myHeap2->insert(80);
    myHeap2->insert(58);
    myHeap2->insert(60);
    myHeap2->insert(50);
    myHeap2->insert(65);

    // Display the Heap:
    cout << "\n\nSecond Heap: " << endl;
    myHeap2->printHeap();

    // Test remove Function:
    myHeap2->remove();
    myHeap2->printHeap();

    myHeap2->remove();
    myHeap2->printHeap();
        

}