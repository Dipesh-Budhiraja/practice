bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    
    if (root == NULL) {
        return true;
    }
    
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    
    bool isLeftBST = validateBST(root->left);
    bool isRightBST = validateBST(root->right);
    
    if (isLeftBST && isRightBST) {
        if (root->left == NULL && root->right == NULL) {
            return true;
        } 
        
        if (root->left != NULL && root->right == NULL 
            && root->left->data <= root->data ) {
            return true;
        }
        
        if (root->left == NULL && root->right != NULL 
            && root->data <= root->right->data ) {
            return true;
        }
        
        if (root->left != NULL && root->right != NULL 
           && root->left->data <= root->data 
           && root->data <= root->right->data ) {
            return true;
        }
    }
    
    return false; 
}


bool isBST(BinaryTreeNode<int> *root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    
    if (root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    return false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    
    return isBST(root, INT_MIN, INT_MAX);
    
}