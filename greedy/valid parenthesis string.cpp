#include "header.h"

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0; // left open paranthesis

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                leftMin++;
                leftMax++;
            } else if (s[i] == ')') {
                leftMin--;
                leftMax--;
            } else {
                leftMin--; // if * is considered to be )
                leftMax++; // if * is considered to be (
            }
            if (leftMax < 0) {
                return false;
            }
            if (leftMin < 0) {
                leftMin = 0;
            }
        }

        return leftMin == 0;
    }
};