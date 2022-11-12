#include "header.h"
using namespace std;

class Solution {
public:
    vector<vector<string> > ans;
    
    bool isPalin(string s) {
        int n = s.length();
        for (int i=0; i<n/2; i++) {
            if (s[i] != s[n-i-1]) {
                return false;
            }
        }
        
        return true;
    }
    
    void solve(string s, vector<string> &curans) {
        if (s.length() == 0) {
            ans.push_back(curans);
            return;
        }
        
        for (int i = 0; i < s.length(); i++) {
            string prefix = s.substr(0, i+1);
            if (isPalin(prefix)) {
                curans.push_back(prefix);
                string suffix = s.substr(i+1, s.length() - i - 1);
                solve(suffix, curans);
                curans.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> curans;
        solve(s, curans);
        
        return ans;    
    }
};