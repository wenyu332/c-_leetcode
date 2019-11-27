/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        stack<TreeNode *> temp;
        while(root)
        {
            temp.push(root);
            root=root->left;
        }  
        while(temp.size()>0)
        {
            TreeNode *node=temp.top();
            temp.pop();
            values.push_back(node->val);
            node=node->right;
            while(node)
            {
                temp.push(node);
                node=node->left;
            }
        }
        return values;
    }
};
