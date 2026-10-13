leetcode 102 bfs level order traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);//starting part put the root
        if(root == NULL) return ans; //base case
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i =0;i<size;i++){
                //lets say from [2,3] 
                TreeNode* node = q.front();
                q.pop();
                // i got 2
                level.push_back(node->val); //[2]
                //now process the children
                if(node->left){//if 2 has left put into que
                    q.push(node->left);
                }
                if(node->right){ // if 3 has right put the que
                    q.push(node->right);
                }
                
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};


leetcode 144 preorder traversal
class Solution {
public:
    vector<int> ans;

    void preorder(TreeNode* root){
        if(root == NULL) return;
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ans;

        
    }
};

leetcode 94 inorder traversal
this is iterative solution using stack here we are using stack to implement recursion

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {

            // Go as left as possible
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            // Process node
            curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            // Move to right subtree
            curr = curr->right;
        }

        return ans;
    }
};

//tree question pattern
//first see bfs- level order traversal need 
// or dfs recursive traversal need (solve small small sub tree start from small unit then make edge cases)
if(root == NULL)
    return something;

left = solve(root->left);
right = solve(root->right);

return combine(left, right, root);

leetcode right view of bt 
if left view i = 0 
just level order traversal and we take first element of level left view if last element right view 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         vector<int> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (i == size - 1)
                ans.push_back(node->val);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }

    return ans;
}
        
};


leetcode https://leetcode.com/problems/symmetric-tree/description/
just devide left and right subtree then traverse root l r == root r l 
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        //here left and rights are nodes of subtree

        // Both nodes are NULL
        if (left == NULL && right == NULL)
            return true;

        // Only one node is NULL
        if (left == NULL || right == NULL)
            return false;

        if(left->val != right->val) 
            return false;

        // Values must match and children must be mirrored
        //here left=right we are checking
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        // else case process the subtress
        return isMirror(root->left, root->right);
    }
};

