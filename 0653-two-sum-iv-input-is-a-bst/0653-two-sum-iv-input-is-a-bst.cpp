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
 class BSTiterator{
    stack<TreeNode*> st;
    bool reverse = true;
public:
    BSTiterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp -> right);
        else pushAll(temp -> left);
        return temp -> val;
    }
private:
    void pushAll(TreeNode* node){
        for(; node != NULL; ){
            st.push(node);
            if(reverse == true){
                node = node -> right;
            }
            else node = node -> left;
        }
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);

        int left = l.next();
        int right = r.next();
        while(left < right){
            if(left + right == k) return true;
            else if(left + right < k) left = l.next();
            else right = r.next();
        }
        return false;
    }
};