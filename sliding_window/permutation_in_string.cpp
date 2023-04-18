#include "header.h"

class Solution {
public:
    bool isEqualCount(int *countS, int *countT) {
        for (int i = 0; i < 26; i++) {
            if (countS[i] != countT[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s, string t) {
        int countS[26] = {};
        int countT[26] = {};

        for (int i = 0; i < s.length(); i++) {
            countS[s[i] - 'a']++;
        }

        bool ans = false;

        int l = 0;
        for (int r = 0; r < t.length(); r++) {
            // to make window length same as p length in the initial loop call
            while (r-l < s.length() && r < t.length()) {
                countT[t[r] - 'a']++;
                r++;
            }
            if (isEqualCount(countS, countT)) {
                ans = true;
                break;
            }
            countT[t[l] - 'a']--;
            l++;
            r--;
        }


        return ans;

    }
};