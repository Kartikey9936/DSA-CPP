
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


kth smallest in bst;
just traverse add a counter

class Solution {
public:
    void inorder(TreeNode* root, int k, int &count, int &ans){
        if(root == NULL) return;
        inorder(root->left,k,count,ans);
        count++;
        if(count==k){
            ans =root->val;
            return;
        }
        inorder(root->right,k,count,ans);
    
    }

    int kthSmallest(TreeNode* root, int k) {
        int count =0;
        int ans =-1;
        inorder(root, k, count, ans);
        return ans;

        


        
    }
};

find BT OR BST- traverse inorder then save all value in vector,then check in vector all values should inc ;
2-- by range of all the node in bst

class Solution {
public:
      void inorder(TreeNode* root,vector<int>& ans){
        if(root ==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
      }
    // bool helper(TreeNode* root,long long minval,long long maxval){//this will be bool;
    //     if(root == NULL) return true;
    //     if(root->val>=maxval || root->val<=minval) return false;
    //     return helper(root->left, minval, root->val) && 
    //     helper(root->right,root->val,maxval);

    // }


    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        inorder(root, ans);//we called the function to traversal
        for(int i =1;i<ans.size();i++){
            if(ans[i]<=ans[i-1]){
                return false;
            }
            
        }
        return true;

        // return helper(root, LLONG_MIN, LLONG_MAX);

        
    }
    
};

BST FROM PREORDER
its brute force code 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i =1;i<n;i++){
            TreeNode* curr = root;
            while(true){
                if(preorder[i]<curr->val){
                    if(curr->left == NULL){
                        curr->left = new TreeNode(preorder[i]);
                        break;//we got position to insert so will break loop and process another
                        
                    }
                    else{
                        curr = curr->left;
                    }

                }
                else{
                    if(curr->right == NULL){
                        curr->right = new TreeNode(preorder[i]);
                        break;
                    }
                    else{
                        curr= curr->right;
                    }
                }
            }
        }
        return root;   

        
        
    }
};

we can also write this in recursion by making helper function to select correct position to insert ;


