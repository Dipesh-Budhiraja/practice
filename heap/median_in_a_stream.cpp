#include<queue>
#include<cmath>
using namespace std;


double avg(int a, int b) {
    return floor((a+b)/2);
}

int signum(int a, int b) {
  if (a > b) return 1;
  if (a < b) return -1;
  return 0;
}

int call_median(int &element, 
                priority_queue<int, vector<int>, greater<int>> &minHeap, 
                priority_queue<int> &maxHeap,
                int median) {
    switch(signum(maxHeap.size(), minHeap.size())) {
        case 0: {
                    if (element > median) {
                        minHeap.push(element);
                        median = minHeap.top();
                    } else {
                        maxHeap.push(element);
                        median = maxHeap.top();
                    }
                }
                break;
        case 1: {
                    if (element > median) {
                        minHeap.push(element);
                        median = avg(maxHeap.top(), minHeap.top());
                    } else {
                        minHeap.push(maxHeap.top());
                        maxHeap.pop();
                        maxHeap.push(element);
                        median = avg(maxHeap.top(), minHeap.top());
                    }
                }
                break;
        case -1: {
                     if (element > median) {
                        maxHeap.push(minHeap.top());
                        minHeap.pop();
                        minHeap.push(element);
                        median = avg(maxHeap.top(), minHeap.top());
                    } else {
                        maxHeap.push(element);
                        median = avg(maxHeap.top(), minHeap.top());
                     }
                 }
                break;
    }
    
    return median;
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    
    int median = 0;
    for(int i = 0; i < n; i++) {
        int element = arr[i];
        median = call_median(element, minHeap, maxHeap, median);
        ans.push_back(median);
    }
    return ans;
}
