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

void inorder(TreeNode<int>* root, vector<int> &v) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> tree1, tree2;
    // step1 - store inorder
    inorder(root1, tree1);
    inorder(root2, tree2);
    
    // step2 - merge 2 sorted arrays
    vector<int> mergedTree;
    int i = 0, j = 0;
    while(i < tree1.size() && j < tree2.size()) {
        if (tree1[i] < tree2[j]) {
            mergedTree.push_back(tree1[i++]);
        } else {
            mergedTree.push_back(tree2[j++]);
        }
    }
    
    while (i < tree1.size()) {
        mergedTree.push_back(tree1[i++]);
    }
    
    while (j < tree2.size()) {
        mergedTree.push_back(tree2[j++]);
    }
    
    // step3 - build BST from a sorted array
    TreeNode<int>* head = createBalancedBST(mergedTree, 0, mergedTree.size()-1);
    
    return head;
}



