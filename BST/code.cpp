
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

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int floor = -1;
              while(root){
                  if(root->data == k) return k;
                  if(root->data>k){
                      
                      root = root->left;
                  }
                  else{
                      floor = root->data;// just one line is changed
                      root = root->right;
                  }
              }
              return floor;
    }
};

////////////////////////////////////////////////delete node in BST //////////////////////
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *dummy = root;
        if(root == NULL) return NULL;
        if(root->val == key) return helper(root);

        while(root != NULL){
            if(root->val>key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                }
                else{
                    root = root->right;
                }
            }
        }
        return dummy;   
    }
    TreeNode* helper(TreeNode* root){//this is node which we want to delete
        if(root->left == NULL){
            return root->right;
        }
        if(root->right == NULL){
            return root->left;
        }
        TreeNode* rightchild = root->right;
        TreeNode* leftlastright = find(root->left);
        leftlastright->right = rightchild;
        return root->left;

    }
    TreeNode* find(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        else{
            return find(root->right);
        }

    }