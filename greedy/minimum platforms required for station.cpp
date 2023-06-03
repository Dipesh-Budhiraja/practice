#include "header.h"

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int platform = 1;
    	int result = 1;
    	
    	int i = 1;// at t0 1st train has arrived
    	int j = 0;// no train has departed
    	
    	while(i < n && j < n) {
    	    if (arr[i] <= dep[j]) {
    	        platform++;
    	        i++;
    	    } else {
    	        platform--;
    	        j++;
    	    }
    	    result = max(result, platform);
    	}
    	return result;
    }
};