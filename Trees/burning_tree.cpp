//{ Driver Code Starts
//Initial Template for C++

#include "header.h"
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // create mapping
    // return target node
    Node* createParentMapping(Node *root, int target, 
                                unordered_map<Node*, Node*> &nodeToParent) {
        // level order traversal
        Node* targetNode = NULL;
        nodeToParent[root] = NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (cur->data == target) {
                targetNode = cur;
            }
            
            Node *left = cur->left;
            Node *right = cur->right;
            
            if (left != NULL) {
                nodeToParent[left] = cur;
                q.push(left);
            }
            
            if (right != NULL) {
                nodeToParent[right] = cur;
                q.push(right);
            }
        }
        
        return targetNode;
    }
    
    int burnTree(Node* targetNode, unordered_map<Node*, Node*> &nodeToParent) {
        int timer = 0;
        unordered_set<Node*> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited.insert(targetNode);
        q.push(new Node(-1));
        
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            
            if (cur->data == -1) {
                timer ++;
                if(!q.empty()) {
                    q.push(new Node(-1));
                }
                continue;
            }
            
            Node *left = cur->left;
            Node *right = cur->right;
            Node *parent = nodeToParent[cur];
            bool flag = false;
            
            if (left != NULL && visited.find(left) == visited.end()) {
                q.push(left);
                visited.insert(left);
                flag = true;
            }
            
            if (right != NULL && visited.find(right) == visited.end()) {
                q.push(right);
                visited.insert(right);
                flag = true;
            }
            
            if (parent != NULL && visited.find(parent) == visited.end()) {
                q.push(parent);
                visited.insert(parent);
                flag = true;
            }
            
            // if (flag == true) {
            //     timer++;
            // }
        }
        return timer;
    }
    
    int minTime(Node* root, int target) 
    {
        // algo:
        // step1: create nodeToParent mapping
        // step2: find target node
        // step3: burn the tree in min time
        
        int ans = 0;
        unordered_map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        ans = burnTree(targetNode, nodeToParent);
        
        return ans-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends