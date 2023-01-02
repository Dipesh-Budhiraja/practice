void trav(TreeNode<int>* root, TreeNode<int>* &head) {
    if (root == NULL) {
        return;
    }
    
    trav(root->right, head);
    
    // reverse inorder
    if (head == NULL) {
        head = root;
    } else {
        root->right = head;
        head = root;
    }
    
    trav(root->left, head);
    root->left = NULL;
}


TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>* head = NULL;
    
    trav(root, head);
    
    return head;
}



void inorder(TreeNode<int>* root, vector<TreeNode<int>*> &v) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left, v);
    
    v.push_back(root);
    
    inorder(root->right, v);
}


TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>* head = NULL;
    
    vector<TreeNode<int>*> v;
    
    inorder(root, v);
    
    for (int i = 0; i < v.size()-1; i++) {
        v[i]->left = NULL;
        v[i]->right = v[i+1];
    }
    v[v.size()-1]->left = NULL;
    v[v.size()-1]->right = NULL;
    head = v[0];
    
    return head;
}