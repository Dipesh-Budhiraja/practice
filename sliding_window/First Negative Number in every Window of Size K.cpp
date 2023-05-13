#include "header.h"

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    
    
    deque<long long> dq;
    vector<long long> ans;
    for (int i = 0; i<K; i++) {
        if (A[i] < 0) {
            dq.push_back(i);
        }
    }
    
    if (dq.size() == 0) {
        ans.push_back(0);
    } else {
        ans.push_back(A[dq.front()]);
    }
    
    for(int i=K; i<N; i++) {
        // remove
        if (!dq.empty() && i - dq.front() >= K) {
            dq.pop_front();
        }
        
        // add 
        if (A[i] < 0) {
            dq.push_back(i);
        }
        
        // make answer
        if (dq.size() == 0) {
            ans.push_back(0);
        } else {
            ans.push_back(A[dq.front()]);
        }
    }
    
    return ans;
}