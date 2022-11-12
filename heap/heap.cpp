#include "header.h"
using namespace std;

class Heap {
    public: 
        int arr[100];
        int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        while(index > 1) {
            int parentIndex = index/2;
            if (arr[parentIndex] < arr[index]) {
                swap(arr[parentIndex], arr[index]);
                index = parentIndex;
            } else {
                return;
            }
        }
    }

    void print() {
        for (int i=1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap() {
        if (size == 0) {
            cout << "nothing to delete" << endl;
            return;
        }

        // step1: swap with last node
        swap(arr[1], arr[size]);

        // remove last node 
        size--;

        // put root in the correct place
        int i = 1;
        while(i < size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if (leftIndex <= size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if (rightIndex <= size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i) { //  O(logn)
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if (left <=n && arr[largest] < arr[left]) {
        largest = left;
    }
    if (right <=n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n;
    while(size > 1) { // last element is in correct position
        // step1: swap root with last 
        swap(arr[1], arr[size]);

        // step2: decrement size
        size--;

        // move root to right position
        heapify(arr, size, 1);
    }
}

int main() {
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();


    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // buildHeap
    for (int i = n/2; i>0; i--) { // build heap(O(n))
        heapify(arr, n, i);
    }
    cout << "printing the array after heapify: " << endl;
    for (int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    heapSort(arr, n);
    cout << "printing the array after heapSort: " << endl;
    for (int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}