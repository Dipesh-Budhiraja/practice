#include "header.h"
using namespace std;

int counter = 0;

void solution(int i, int n, int k, int noOfSets, vector<vector<int> >&ans) {
    if (i > n) {
        if (noOfSets == k) {
            counter++;
            cout << counter << ". ";
            for (vector<int> set : ans) {
                cout << "[";
                for (int num: set) {
                    cout << num << ",";
                }
                cout << "]";
            }
            cout << endl;
        }

        return;
    }

    for (int j = 0; j < ans.size(); j++) {
        if (ans[j].size() > 0) {
            ans[j].push_back(i);
            solution(i+1, n, k, noOfSets, ans);
            ans[j].pop_back();
        } else {
            ans[j].push_back(i);
            solution(i+1, n, k, noOfSets+1, ans);
            ans[j].pop_back();
            break;
        }
    }


}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int> > ans(k, vector<int>());

    solution(1, n, k, 0, ans);

    return 0;
}