/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<vector>
 using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        else{
            if(root->left==NULL && root->right==NULL) return true;
            else if((root->left==NULL && root->right!=NULL) || (root->left!=NULL && root->right==NULL)) return false;
            else{
            vector<TreeNode*>nodes;
            nodes.push_back(root->left);
            nodes.push_back(root->right);
            int flag=0;
            while(nodes.size()>0){
                int size=nodes.size();
                int j=size;
                
                if(size%2!=0) return false;
                for(int i=0;i<j;i++,j--){
                    if(nodes[i]!=NULL && nodes[j-1]!=NULL){
                        cout<<nodes[i]->val<<" "<<nodes[j-1]->val<<endl;
                        if(nodes[i]->val!=nodes[j-1]->val)
                        return false;
                        }
                    else if((nodes[i]==NULL && nodes[j-1]!=NULL) or (nodes[i]!=NULL && nodes[j-1]==NULL)) return false;
                    
                }
                
                vector<TreeNode*>tmpNodes;
                vector<TreeNode*>::iterator iter=nodes.begin();
                int count=0;
                for(;iter!=nodes.end();iter++){
                    if(*iter==NULL){
                        count+=2;
                        tmpNodes.push_back(NULL);
                        tmpNodes.push_back(NULL);
                        continue;
                    }
                    
                    if((*iter)->left==NULL) count++;
                    if((*iter)->right==NULL) count++;
                    tmpNodes.push_back((*iter)->left);
                    tmpNodes.push_back((*iter)->right);
                }
                if (count==size*2) return true;
                nodes.assign(tmpNodes.begin(),tmpNodes.end());
            }
            }
        }
        return true;
    }
};
