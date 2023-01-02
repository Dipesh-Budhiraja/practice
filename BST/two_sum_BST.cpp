
void inorder(BinaryTreeNode<int>* root, vector<int> &vals) {
    if (root == NULL) {
        return ;
    }
    
    inorder(root->left, vals);
    
    vals.push_back(root->data);
    
    inorder(root->right, vals);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> vals;
    
    inorder(root, vals);
    
    int i = 0;
    int j = vals.size() - 1;
    
    while(i < j) {
        int sum = vals[i] + vals[j];
        
        if (sum == target) {
            return true;
        }
        
        if (sum > target) {
            j--;
        } else {
            i++;
        }
    }
    
    return false;
}