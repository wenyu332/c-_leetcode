class Solution {
public:
    int *last=NULL;
    bool isValidBST(TreeNode* root,long long min=LONG_LONG_MIN,long long max=LONG_LONG_MAX) {
        
        // getNodeValue(root,res);
        // int size=res.size()-1;
        // for(int i=0;i<=size-1;i++)
        // {
        //     if(res[i]>=res[i+1]) return false;
        // }
        // return true;
        if(root==NULL) return true;
        if(root->val<=min||root->val>=max) return false;
        return isValidBST(root->left,min,root->val) && isValidBST(root->right,root->val,max);

    }
    void getNodeValue(TreeNode *root,vector<int>&res)
    {
        if(root)
        {
            getNodeValue(root->left,res);
            res.push_back(root->val);
            getNodeValue(root->right,res);
        }
    }
};
