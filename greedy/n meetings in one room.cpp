#include "header.h"

class Meeting {
public:
    int s;
    int f;
    int index;
};

bool comp(Meeting m1, Meeting m2) {
    return m1.f < m2.f;
}

class Solution
{
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<Meeting> meetings;
        Meeting meeting;
        for (int i = 0; i < n; i++) {
            meeting.s = start[i];
            meeting.f = end[i];
            meeting.index = i;
        
            meetings.push_back(meeting);
        }
        sort(meetings.begin(), meetings.end(), comp);
        
        int endLimit = -1;
        vector<int> ans;
        // cout << meetings.size() << endl;
        for (int i = 0; i < meetings.size(); i++) {
            // cout << meetings[i].f << " " << endl;
            if (meetings[i].s > endLimit) {
                // cout << "meeting start time: " << meetings[i].s << endl;
                ans.push_back(meetings[i].index);
                endLimit = meetings[i].f;
            }
        }
        
        return ans.size();
        
    }
};