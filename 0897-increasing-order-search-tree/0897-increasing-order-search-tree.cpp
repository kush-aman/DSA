/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class traverse{
    stack<TreeNode*> st;
public:
    traverse(TreeNode* root){
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode* node = st.top();
        st.pop();
        pushAll(node -> right);
        return node -> val;
    }
private:
    void pushAll(TreeNode* node){
        for(;node != NULL;st.push(node),node = node -> left);
    }    
};
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        traverse t(root);
        TreeNode* head = new TreeNode(t.next());
        TreeNode* node = head;
        while(t.hasNext()){
            head -> right = new TreeNode(t.next());
            head = head -> right;
        }

        return node;
    }
};