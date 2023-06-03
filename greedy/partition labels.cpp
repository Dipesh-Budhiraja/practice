#include "header.h"

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]] = i;
        }

        vector<int> ans;
        int size = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            size++;
            int lastIndex = m[s[i]];
            if (lastIndex > end) {
                end = lastIndex;
            }

            if (i == end) {
                ans.push_back(size);
                size = 0;
            }
        }
        return ans;
    }
};