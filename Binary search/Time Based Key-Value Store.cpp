#include "header.h"

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string> > > timemap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back( {timestamp, value} );
    }
    
    string get(string key, int timestamp) {
        if (timemap.find(key) == timemap.end()) {
            return "";
        }

        if (timestamp < timemap[key][0].first) {
            return "";
        }

        int left = 0; 
        int right = timemap[key].size()-1;

        while (left <= right) {
            int mid = (left + right)/2;
            if (timemap[key][mid].first < timestamp) {
                left = mid + 1;
            } else if (timemap[key][mid].first > timestamp) {
                right = mid - 1;
            } else {
                cout << "get of " << timestamp << "returns: " << timemap[key][mid].second << endl;
                return timemap[key][mid].second;
            }
        }
        cout << "get of " << timestamp << " returns: " << timemap[key][right].second << " right: {}" << right << endl;
        return timemap[key][right].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */