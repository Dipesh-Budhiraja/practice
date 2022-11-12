#include "header.h"
using namespace std;

class Solution {
public:
    void solve(int n, int op, int cl, string cur, vector<string> &ans) {
        if (op > n || cl > n) {
            return;
        }
        
        if (cl > op) {
            return;
        }
        
        if (op == n && cl == n) {
            ans.push_back(cur);
            return;
        }
        
        cur += '(';
        solve(n, op+1, cl, cur, ans);
        cur.erase(cur.length()-1);
        
        cur += ')';
        solve(n, op, cl+1, cur, ans);
        cur.erase(cur.length()-1);
    }

    void better_solve(int n, int op, int cl, string cur, vector<string> &ans) {
        if (cur.length() == 2*n) {
            ans.push_back(cur);
            return;
        }
        
        if (op < n) {
            solve(n, op+1, cl, cur+'(', ans);
        }
        if (cl < op) {
            solve(n, op, cl+1, cur+')', ans);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int op = 0;
        int cl = 0;
        
        string cur = "";
        vector<string> ans;
        
        solve(n, op, cl, cur, ans);
        
        return ans;
    }
};