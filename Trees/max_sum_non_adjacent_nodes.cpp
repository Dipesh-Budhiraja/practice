//{ Driver Code Starts
//Initial Template for C++

#include "header.h" 
using namespace std; 

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    int traverse(Node *root, bool parentTaken, unordered_map<Node*, int> &m) {
        if(root == NULL) {
            return 0;
        }
        
        if (m.find(root) != m.end()) {
            return m[root];
        }
        
        if(root->left == NULL && root->right == NULL) {
            if (parentTaken) {
                return 0;
            }
            m[root] = root->data;
            return root->data;
        }
        
        int l1 = 0, r1 = 0, s1 = 0;
        
        if (parentTaken == false) {
            // node taken
            l1 = traverse(root->left, true, m);
            r1 = traverse(root->right, true, m);
            s1 = l1 + r1 + root->data;
            
            // node not taken
            // int l2 = traverse(root->left, false);
            // int r2 = traverse(root->right, false);
            // int s2 = l2 + r2;
            
            // return max(s1, s2);
        }
        
        int l2 = traverse(root->left, false, m);
        int r2 = traverse(root->right, false, m);
        int s2 = l2 + r2;
        
        // return l + r;
        int val = max(s1, s2);
        m[root] = val;
        return val;
        
    }
  
  
    unordered_map<Node*, int> m;
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        // unordered_map<Node*, int> m;
        // return traverse(root, false, m);
        
        
        if (root == NULL) {
            return 0;
        }
        
        if (m[root]) {
            return m[root];
        }
        
        // case1: when root is taken
        int whenRootTaken = root->data;
        
        // left grandchildren
        if (root->left) {
            whenRootTaken += getMaxSum(root->left->left);
            whenRootTaken += getMaxSum(root->left->right);
        }
        
        // right grandchildren
        if (root->right) {
            whenRootTaken += getMaxSum(root->right->left);
            whenRootTaken += getMaxSum(root->right->right);
        }
        
        // case2: when root is not taken 
        // call children
        int whenRootNotTaken = getMaxSum(root->left) + getMaxSum(root->right);
        
        return m[root] = max(whenRootTaken, whenRootNotTaken);
        
    }
};

//{ Driver Code Starts.

// Driver code 
int main()
{
  int t;
  scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        cout<<ob.getMaxSum(root)<<endl;
  }
  return 0;
}
// } Driver Code Ends