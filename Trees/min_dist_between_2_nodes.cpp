//{ Driver Code Starts
//Initial Template for C++


#include "header.h"
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    
    int answer = 0;
    
    pair<Node*, int> lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
        if (root == NULL) {
            Node *tmp = NULL;
            return make_pair(tmp, 0);
        }
        
        if (root->data == n1 || root->data == n2) {
            pair<Node*, int> left = lca(root->left, n1, n2);
            pair<Node*, int> right = lca(root->right, n1, n2);
            
            if (left.first == NULL && right.first == NULL) {
                return make_pair(root, 1);
            }
            
            if (left.first != NULL && right.first == NULL) {
                answer = left.second;
                return make_pair(root, left.second);
            }
            
            if (left.first == NULL && right.first != NULL) {
                answer = right.second;
                return make_pair(root, right.second);
            }
            
        }
        
        pair<Node*, int> left = lca(root->left, n1, n2);
        pair<Node*, int> right = lca(root->right, n1, n2);
        
        if (left.first != NULL && right.first != NULL) {
            answer = left.second + right.second;
            return make_pair(root, left.second + right.second);
        }
        
        if (left.first != NULL && right.first == NULL) {
            left.second += 1;
            return left;
        }
        
        if (left.first == NULL && right.first != NULL) {
            right.second += 1;
            return right;
        }
        
        if (left.first == NULL && right.first == NULL) {
            Node *tmp = NULL;
            return make_pair(tmp, 0);
        }
    } 

    
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        // Your code here
        
        
        answer = 0;
        pair<Node*, int> ans = lca(root, a, b);
        return answer;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends