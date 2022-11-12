//{ Driver Code Starts
//

#include "header.h"
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node* helper(int in[], int pre[], int be, int en, int &i) {
        if(be > en) {
            return NULL;
        }
        
        for(int j=be; j<=en; j++) {
            if (in[j] == pre[i]) {
                Node *root = new Node(pre[i]);
                i++;
                
                root->left = helper(in, pre, be, j-1, i);
                root->right = helper(in, pre, j+1, en, i);
                
                return root;
            }
        }
        
        return NULL;
    }
    
    
    Node* buildTree(int in[], int pre[], int n)
    {
        // Code here
        Node *root = NULL;
        int i = 0;
        root = helper(in, pre, 0, n-1, i);
        
        return root;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends