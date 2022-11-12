//{ Driver Code Starts
#include "header.h"
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    queue<char> q;
		    int n = A.size();
		    string ans;
		    bool alphaIndex[26] = {0};
		    bool secondTime[26] = {0};
		   
		    
		    for (int i = 0; i < n; i++) {
		        if (alphaIndex[A[i] - 'a'] == false) {
		            q.push(A[i]);
		            alphaIndex[A[i] - 'a'] = true;
		        } else {
		            secondTime[A[i] - 'a'] = true;
		        }
		        
		        while(!q.empty() && secondTime[q.front() - 'a'] == true) {
		            q.pop();
		        }
		        
		        if (q.size() == 0) {
		            ans += "#";
		        } else {
		            ans += q.front();
		        }
		        
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends