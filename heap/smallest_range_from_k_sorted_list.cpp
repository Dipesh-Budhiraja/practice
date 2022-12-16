#include<queue>
#include<climits>
using namespace std;

class node {
public:
    int data;
    int row;
    int col;
    
    node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX;
    int maxi = INT_MIN;
    priority_queue<node*, vector<node*>, compare> minHeap;
    
    for (int i=0; i<k; i++) {
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }
    
    int ansStart = mini, ansEnd = maxi;
    
    while(!minHeap.empty()) {
        node* temp = minHeap.top();
        minHeap.pop();
        
        
        // update min
        mini = temp->data;
        
        
        // ans update
        if (maxi - mini < ansEnd - ansStart) {
            ansEnd = maxi;
            ansStart = mini;
        }
        
        // check if next element exist
        if (temp->col+1 < n) {
            // update max
            maxi = max(maxi, a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1], temp->row,
                                 temp->col+1));
        } else {
            break;
        }
    }
    
    return ansEnd - ansStart + 1;
}