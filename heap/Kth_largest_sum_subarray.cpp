#include <algorithm>
#include<queue>
using namespace std;
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
    
    /*
    // inefficient solution
    vector<int> sumStore;
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        
        for (int j=i; j<n; j++) {
            sum += arr[j];
            sumStore.push_back(sum);
        }
    }
    
    sort(sumStore.begin(), sumStore.end());
    
    return sumStore[sumStore.size() - k];
    */
    
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        
        for (int j=i; j<n; j++) {
            sum += arr[j];
            
            if (minHeap.size() < k) {
                minHeap.push(sum);
            } else {
                if (minHeap.top() < sum) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }
    
    return minHeap.top();
    
}