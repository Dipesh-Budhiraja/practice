#include "header.h"

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() <= 10) {
            return vector<string>();
        } 
        vector<string> ans;

        unordered_set<string> myset;
        unordered_set<string> ansset;

        for (int i = 0; i <= s.length() - 10; i++) {
            string curstring = s.substr(i, 10);

            if (myset.find(curstring) != myset.end()) {
                ansset.insert(curstring);
            } else {
                myset.insert(curstring);
            }
        }
        
        ans.assign(ansset.begin(), ansset.end());
        return ans;
    }
};