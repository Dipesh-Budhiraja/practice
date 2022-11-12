#include <iostream>
#include <vector>
using namespace std;

 // } Driver Code Ends


int leftBS(int arr[], int beg, int end, int k) {
    if (beg > end) {
        return -1;
    }
    
    int mid = (beg+end)/2;
    if(arr[mid] == k) {
        int temp = leftBS(arr, beg, mid-1, k);
        if(temp == -1) {
            return mid;
        }
        return temp;
    } else if (arr[mid] < k) {
        return leftBS(arr, mid+1, end, k);
    }
}

int rightBS(int arr[], int beg, int end, int k) {
    if (beg > end) {
        return -1;
    }
    
    int mid = (beg+end)/2;
    if(arr[mid] == k) {
        int temp = rightBS(arr, mid+1, end, k);
        if(temp == -1) {
            return mid;
        }
        return temp;
    } else if (arr[mid] > k) {
        return rightBS(arr, beg, mid-1, k);
    }
}

int bs(int arr[], int beg, int end, int k) {
    if (beg > end) {
        return -1;
    }
    
    int mid = (beg+end)/2;
    
    if(arr[mid] == k) {
        return mid;
    } else if (arr[mid] > k) {
        return bs(arr, beg, mid-1, k);
    } else {
        return bs(arr, mid + 1, end, k);
    }
}

vector<int> find(int arr[], int n , int k )
{
    // code here
    
    int midIndex = bs(arr, 0, n-1, k);
    
    if(midIndex == -1) {
        return vector<int> {-1, -1};
    }
    
    int leftOccurence = leftBS(arr, 0, midIndex-1, k);
    int rightOccurence = rightBS(arr, midIndex+1, n-1, k);
    
    vector<int> ans;
    
    if(leftOccurence == -1) {
        ans.push_back(midIndex);
    } else {
        ans.push_back(leftOccurence);
    }
    
    if(rightOccurence == -1) {
        ans.push_back(midIndex);
    } else {
        ans.push_back(rightOccurence);
    }
    
    return ans;
}



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends