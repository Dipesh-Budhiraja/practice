#include "header.h"

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() == 0) {
            return "";
        }

        unordered_map<char, int> countT, window;

        for (int i = 0; i < t.length(); i++) {
            countT[t[i]]++;
        }

        int have = 0, need = countT.size();
        int resLen = INT_MAX;
        string ans = "";
        int ansStartPos = -1;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            char curchar = s[r];
            window[curchar]++;

            if (countT.find(curchar) != countT.end() && window[curchar] == countT[curchar]) {
                have++;
            }

            while (have == need) {
                // update the result
                if (resLen > r-l+1) {
                    resLen = r-l+1;
                    ansStartPos = l;
                }

                window[s[l]]--;
                if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        if (resLen < INT_MAX) {
            ans = s.substr(ansStartPos, resLen);
        }

        return ans;
    }
};