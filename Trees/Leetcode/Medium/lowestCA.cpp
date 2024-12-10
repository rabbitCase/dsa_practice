//Leetcode Medium 235
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL ){
            return NULL;
        }
        TreeNode *cur=root;
        if(cur->val > p->val && cur->val > q->val)
        return lowestCommonAncestor(cur->left,p,q);
        if(cur->val < p->val && cur->val < q->val)
        return lowestCommonAncestor(cur->right,p,q);
        return cur;
    }
};