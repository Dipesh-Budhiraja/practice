#include "header.h"
/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(Item i1, Item i2) {
    double r1 = i1.value/(double)i1.weight;
    double r2 = i2.value/(double)i2.weight;
    
    return r1 > r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr+n, comp);
        int weightOfItemsCollected = 0;
        double value = 0;
        for (int i = 0; i < n; i++) {
            if (weightOfItemsCollected + arr[i].weight <= W) {
                weightOfItemsCollected += arr[i].weight;
                value += arr[i].value;
            } else {
                int remainingWeight = W - weightOfItemsCollected;
                value += (arr[i].value/(double)arr[i].weight)*remainingWeight;
                break;
            }
        }
        
        return value;
    }
        
};