#include "header.h"

class Solution {
public:

    bool dfs(int crs, unordered_set<int> &visited, unordered_map<int, vector<int>> &preMap, vector<int> &ans,
            unordered_set<int> &alreadyAdded) {
        if (visited.find(crs) != visited.end()) {
            return false;
        }
        if (preMap[crs].size() == 0) {
            if (alreadyAdded.find(crs) == alreadyAdded.end()) {
                alreadyAdded.insert(crs);
                ans.push_back(crs);
            }
            return true;
        }
        visited.insert(crs);
        for (int i = 0; i < preMap[crs].size(); i++) {
            int pre = preMap[crs][i];
            if (!dfs(pre, visited, preMap, ans, alreadyAdded)) {
                return false;
            }
        }
        visited.erase(crs);
        preMap[crs] = vector<int>();
        ans.push_back(crs);
        alreadyAdded.insert(crs);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preMap;
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = vector<int>();
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            int crs = prerequisites[i][0];
            int pre = prerequisites[i][1];
            preMap[crs].push_back(pre);
        }
        // visited set
        unordered_set<int> visited; // cycle set of neetcode
        unordered_set<int> alreadyAdded; // visited of neetcode
        vector<int> ans;
        for (int crs = 0; crs < numCourses; crs++) {
            cout << endl;
            if (!dfs(crs, visited, preMap, ans, alreadyAdded)) {
                return vector<int>();
            }
        }
        return ans;

    }
};