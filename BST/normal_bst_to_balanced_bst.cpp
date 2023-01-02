void inorder(TreeNode<int>* root, vector<int> &v) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

TreeNode<int>* createBalancedBST(vector<int> &v, int beg, int end) {
    if (beg > end) {
        return NULL;
    }
    
    int mid = (beg + end)/2;
    
    TreeNode<int>* root = new TreeNode<int>(v[mid]);
    root->left = createBalancedBST(v, beg, mid-1);
    root->right = createBalancedBST(v, mid+1, end);
    
    return root;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> v;
    inorder(root, v);
    
    TreeNode<int>* head = createBalancedBST(v, 0, v.size()-1);
    
    return head;
}
