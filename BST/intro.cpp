#include "header.h"
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        
    }
};

Node* insertIntoBST(Node* root, int data) {
    // base case
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data > root->data){
        // insert into right part
        root->right = insertIntoBST(root->right, data);
    }
    else {
        // insert into left part
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        Node* cur = q.front();
        q.pop();


        if (cur == NULL) {
            cout << endl;

            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << cur->data << " ";
            if (cur->left != NULL) {
                q.push(cur->left);
            }
            if (cur->right != NULL) {
                q.push(cur->right);
            }
        }
        
    }
}

void inOrder(Node* root) {
    if (root == NULL) {
        return ;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    
}

Node* miniVal(Node* root) {
    Node* temp = root;

    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

Node* maxiVal(Node* root) {
    Node* temp = root;

    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val) {
    // base case
    if (root == NULL) {
        return root;
    }

    // other base case
    if (root->data == val) {
        // node is found. now delete it
        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // left child exist
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child exist
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL) {
            int mini = miniVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val) {
        root->left = deleteFromBST(root->left, val);
        return root;
    } else {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main() {
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeInput(root);
    cout << "level order traversal" << endl;
    levelOrderTraversal(root);

    cout << endl << "inorder traversal" << endl;
    inOrder(root);

    cout << endl <<  "Min Value is " << miniVal(root)->data << endl;

    cout << "Max Value is " << maxiVal(root)->data << endl;
    

    cout << "deletion from BST" << endl;
    deleteFromBST(root, 50);

    cout << "level order traversal" << endl;
    levelOrderTraversal(root);

    cout << endl << "inorder traversal" << endl;
    inOrder(root);

    cout << endl <<  "Min Value is " << miniVal(root)->data << endl;

    cout << endl << "Max Value is " << maxiVal(root)->data << endl;
    
    return 0;
}