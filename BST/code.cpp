
/// @brief /////////////////////////////
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val)
            return root;

        if (val < root->val)
            return searchBST(root->left, val);

        return searchBST(root->right, val);
    }
};

TreeNode* searchBST(TreeNode* root, int val) {
    while (root != NULL && root->val != val) {
        root = val < root->val ? root->left : root->right;
    }
    return root;
}
/////////////////////////////////////////////////

int minValue(Node* root) {
    if (root->left == NULL)
        return root->data;

    return minValue(root->left);
}

int minValue(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}
/// @brief ///////////////////////////////////////////
class Solution {
  public:
    int findCeil(Node* root, int x) {
        // if(root == NULL) return -1;
        int ceil = -1;
        while(root){
            if(root->data == x) return x;
            if(root->data>x){
                ceil = root->data;
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return ceil;

        
    }
};

// //////////////////////////////////////////