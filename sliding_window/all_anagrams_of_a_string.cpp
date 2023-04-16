#include "header.h"

class Solution {
public:
    bool isAnagram(int *countp, int *counts) {
        for (int i = 0; i < 26; i++) {
            if (countp[i] != counts[i]) {
                return false;
            }
            // cout << char('a' + i) << ": " << countp[i] << " " << counts[i] << endl;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        if (s.length() < p.length()) {
            return vector<int>();
        }
        int countp[26] = {};
        int counts[26] = {};
        vector<int> ans;
        for (int i = 0; i < p.length(); i++) {
            countp[p[i] - 'a']++;
        }
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            // to make window length same as p length in the initial loop call
            while (r-l < p.length()) {
                counts[s[r] - 'a']++;
                r++;
            }
            if (isAnagram(countp, counts)) {
                ans.push_back(l);
            }
            counts[s[l] - 'a']--;
            l++;
            r--; // to compensate r++ of while loop. for loop is going to add r
        }
        return ans;
    }
};
