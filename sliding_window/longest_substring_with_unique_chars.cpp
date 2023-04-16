#include "header.h"
#define mp(x, y) make_pair(x, y)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0){
            return 0;
        }

        int i = 0, j = 1;
        unordered_set<int> uset;
        uset.insert(s[0]);
        int ans = 1;

        while (j < s.length()) {
            if (uset.find(s[j]) == uset.end()) {
                uset.insert(s[j]);

                ans = max(ans, j-i+1);
                j++;
            } else {
                while (s[i] != s[j]) {
                    uset.erase(s[i]);
                    i++;
                }
                i++;
                j++;
            }

        }

        return ans;
    }
};