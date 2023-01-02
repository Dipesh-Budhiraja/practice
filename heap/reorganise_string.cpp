//{ Driver Code Starts
#include "header.h"
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends

class Pair {
public:
    char ch;
    int freq;
    
    Pair(char ch, int freq) {
        this->ch = ch;
        this->freq = freq;
    }
};

class compare {
public:
    bool operator()(Pair* a, Pair* b) {
        return a->freq < b->freq;
    }
};

class Solution
{
    public:
    string rearrangeString(string s)
    {
        int map[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            map[s[i] - 'a']++;
        }
        
    //     for (int i = 0; i < 26; i++) {
    //         cout << map[i] << " ";
    //     }
    //     cout << endl;
        
        priority_queue<Pair*, vector<Pair*>, compare> maxHeap;
        
        for (int i = 0; i < 26; i++) {
            if (map[i] > 0) {
                 maxHeap.push(new Pair(char(i + 'a'), map[i]));
            }
        }
        
        string ans = "";
        
        Pair* block = maxHeap.top();
        maxHeap.pop();
        
        ans += block->ch;
        block->freq--;
        
        while(maxHeap.empty() == false) {
            Pair* temp = maxHeap.top();
            maxHeap.pop();
            ans += temp->ch;
            temp->freq--;
            
            if (block->freq > 0) {
                maxHeap.push(block);
            }
            block = temp;
        }
        if (ans.length() != s.length()) {
            ans = "-1";
        }
        // cout << ans << endl;
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends