int inOrderTraverse(BinaryTreeNode<int>* root, int &i, int k) {
    if (root == NULL) {
        return -1;
    }
    
    int leftAns = inOrderTraverse(root->left, i, k);
    
    if (leftAns != -1) {
        return leftAns;
    }
    
    i++;
    if (i == k) {
        return root->data;
    }
    
    
    int rightAns = inOrderTraverse(root->right, i, k);
    if (rightAns != -1) {
        return rightAns;
    }
    
    return -1;
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i = 0;
    int ans = inOrderTraverse(root, i, k);
    return ans;
}