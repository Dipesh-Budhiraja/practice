#include "header.h"

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int count[26] = {};
        int l = 0;
        
        for (int r = 0; r < s.length(); r++) {
            count[ s[r] - 'A' ]++;
            
            int majorityElementCount = 0;
            for (int i = 0; i < 26; i++) {
                majorityElementCount = max(majorityElementCount, count[i]);
            }
 
            if ( r-l+1 - majorityElementCount <= k ) {
                res = max(res, r-l+1);
            } else {
                count[ s[l] - 'A']--;
                l++;
            }

        }

        return res;
    }
};