#include "header.h"

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


bool comp(Job j1, Job j2) {
    return j1.profit > j2.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        int maxDeadLine = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxDeadLine = max(maxDeadLine, arr[i].dead);
        }
        vector<int> days(maxDeadLine+1, -1);
        
        int noOfJobs = 0;
        int profit = 0;
        for (int i = 0; i < n; i++) {
            int j = arr[i].dead;
            while(j>= 1 && days[j] != -1) {
                j--;
            }
            
            if (j >= 1) {
                days[j] = arr[i].profit;
                profit += arr[i].profit;
                noOfJobs++;
            }
        }
        
        return vector<int>({noOfJobs, profit});
    } 
};