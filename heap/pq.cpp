#include "header.h"
using namespace std;

int main() {
    priority_queue<int> pq; // included in <queue>
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "top element " << pq.top() << endl;
    pq.pop();
    cout << "top element " << pq.top() << endl;

    cout << "maxHeap pq size " << pq.size() << endl;

    if (pq.empty()) {
        cout << "pq is empty \n";
    } else {
        cout << "pq is not empty \n";
    }

    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout << "top element " << minHeap.top() << endl;
    minHeap.pop();
    cout << "top element " << minHeap.top() << endl;

    cout << "minHeap pq size " << minHeap.size() << endl;

    if (minHeap.empty()) {
        cout << "minHeap is empty \n";
    } else {
        cout << "minHeap is not empty \n";
    }
    return 0;
}