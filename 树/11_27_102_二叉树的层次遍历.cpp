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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if(root==NULL) return results;
        else{
            vector<TreeNode*>nodes;
            nodes.push_back(root);
            while(nodes.size()>0){
                vector<int>value;
                vector<TreeNode*>tmpNodes;
                vector<TreeNode*>::iterator iter=nodes.begin();
                for(;iter!=nodes.end();iter++)
                {
                    value.push_back((*iter)->val);
                    if((*iter)->left!=NULL)
                    tmpNodes.push_back((*iter)->left);
                    if((*iter)->right!=NULL)
                    tmpNodes.push_back((*iter)->right);
                }
                results.push_back(value);
                nodes.assign(tmpNodes.begin(),tmpNodes.end());
            }
            return results;
        }
    }
};
