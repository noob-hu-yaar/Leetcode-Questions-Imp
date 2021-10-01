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
class Solution {
    TreeNode* helper(vector<int> &a, int start, int end)
    {
        if(start > end)
            return NULL;
        
        int mid = (start + end)/2;
        
        TreeNode* root=  new TreeNode(a[mid]);
        
        root->left = helper(a, start, mid-1);
        root->right = helper(a, mid+1, end);
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& a)
    {
        int n = a.size();
        return helper(a, 0, n-1);
        
    }
};