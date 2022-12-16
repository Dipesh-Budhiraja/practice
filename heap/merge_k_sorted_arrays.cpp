#include "header.h"
using namespace std;
class Node {
public:
    int data;
    int i;
    int j;
    
    Node(int data, int i, int j) {
        this->data = data;
        this->i = i;
        this->j = j;
    }
};

class compare {
public:
    bool operator()(Node* a, Node *b) {
        return a->data > b->data;
    }    
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    
    // step1: push first elements into minHeap
    for (int i = 0; i < k; i++) {
        Node* temp = new Node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }
    
    // step2
    while(minHeap.size() > 0) {
        Node* topEle = minHeap.top();
        minHeap.pop();
        ans.push_back(topEle->data);
        
        if (topEle->j + 1 < kArrays[topEle->i].size()) {
            Node* temp = new Node(kArrays[topEle->i][topEle->j + 1], topEle->i, topEle->j + 1);
            minHeap.push(temp);
        }
    }
    
    return ans;
}
