//{ Driver Code Starts
#include "header.h"
using namespace std;

// } Driver Code Ends
class Solution
{
    void permute(string s, int index, int n, set<string> &mySet) {
        if (index == n) {
            mySet.insert(s);
            return;
        }
        
        for (int i = index; i < n; i++) {
            swap(s[index], s[i]);
            permute(s, index+1, n, mySet);
            swap(s[index], s[i]);
        }
    }
    
	public:
		vector<string>find_permutation(string s)
		{
		    vector<string> ans;
		    set<string> mySet;
		    int n = s.length();
		    permute(s, 0, n, mySet);
		    
		    for (auto it: mySet) {
		        ans.push_back(it);
		    }
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends