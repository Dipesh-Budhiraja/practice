class info {
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int>* root, int &maxSize) {
    if (root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }
    
    info left = solve(root->left, maxSize);
    info right = solve(root->right, maxSize);
    
    info currnode;
    currnode.size = left.size + right.size + 1;
    currnode.maxi = max(root->data, right.maxi);
    currnode.mini = min(root->data, left.mini);
    
    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currnode.isBST = true;
    } else {
        currnode.isBST = false;
    }
    
    if (currnode.isBST) {
        maxSize = max(maxSize, currnode.size);
    }
    
    return currnode;
}

int largestBST(TreeNode<int>* root) 
{
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}
