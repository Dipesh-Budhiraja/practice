#include "header.h"
using namespace std;

class kQueue {
    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freespot;
        int *next;

        kQueue(int n, int k) {
            this->n = n;
            this->k = k;
            front = new int[k];
            rear = new int[k];
            next = new int[n];
            arr = new int[n];
            freespot = 0;

            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
        }

        void enQueue(int data, int qn) {
            //overflow
            if (freespot == -1) {
                cout << "No empty space is present" << endl;
                return;
            }

            // find first free index
            int index = freespot;

            // update freespot
            freespot = next[index];

            // if first element
            if (front[qn-1] == -1) {
                front[qn-1] = index;
            } else {
                // link new element to the previous element
                next[rear[qn-1]] = index;
            }

            // update next
            next[index] = -1; // signifies end of qn or spot is taken
            
            // update rear
            rear[qn-1] = index;
            
            // insert data
            arr[index] = data;
        }

        int deQueue(int qn) {
            // underflow
            if (front[qn-1] == -1) {
                cout << "Queue Underflow" << endl;
                return -1;
            }

            // find index to pop
            int index = front[qn-1];

            // front ko aage badhao
            front[qn-1] = next[index];

            // freeslots ko manage karo
            next[index] = freespot;
            freespot = index;

            return arr[index];
        }
};

int main() {
    kQueue kq(10, 3);

    kq.enQueue(10,1);
    kq.enQueue(15,1);
    kq.enQueue(20,2);
    kq.enQueue(5,1);

    cout << kq.deQueue(1) << endl;
    cout << kq.deQueue(2) << endl;
    cout << kq.deQueue(1) << endl;
    cout << kq.deQueue(1) << endl;
    cout << kq.deQueue(1) << endl;


    return 0;
}