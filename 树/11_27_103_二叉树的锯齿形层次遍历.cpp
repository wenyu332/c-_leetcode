class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        if(root==NULL) return results;
        else{
            vector<TreeNode *>nodes;
            nodes.push_back(root);
            int level=0;
            while(nodes.size()>0){
                
                cout<<level<<endl;
                vector<TreeNode *>tmpNodes;
                vector<int>values;
                int size=nodes.size();
                for(int i=0;i<size;i++)
                {
                    if(level%2==0)
                        values.push_back(nodes[i]->val);
                    else
                        values.push_back(nodes[size-i-1]->val);
                    if(nodes[i]->left!=NULL)tmpNodes.push_back(nodes[i]->left);
                    if(nodes[i]->right!=NULL)tmpNodes.push_back(nodes[i]->right);
                }
                level++;
                //cout<<endl;
                results.push_back(values);
                nodes.assign(tmpNodes.begin(),tmpNodes.end());
            }
            return results;
        }
    }
};
