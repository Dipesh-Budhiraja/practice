#include "header.h"


class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int ans = -1;
        unordered_map<char, int> count;
        int l = 0;
        
        for (int r = 0; r < s.length(); r++) {
            count[s[r]]++;
            
            if (count.size() == k) {
                ans = max(ans, r - l + 1);
            } else if (count.size() > k) {
                if (count[s[l]] == 1) {
                    count.erase(s[l]);
                } else {
                    count[s[l]]--;
                }
                l++;
            }
        }
        
        return ans;
    }
};