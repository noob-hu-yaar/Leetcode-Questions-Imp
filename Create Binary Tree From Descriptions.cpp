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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d)
    {
        unordered_map<int, TreeNode*> m;
        unordered_map<TreeNode*, TreeNode*> par_map;
        vector<TreeNode*> list;
        for(auto i : d)
        {
            int p = i[0], c = i[1], left = i[2];
            auto parent = (m.count(p)) ? m[p] :(m[p] = new TreeNode(p));
            auto child = (m.count(c)) ? m[c] :(m[c] = new TreeNode(c));
            
            if(left == 1)
                parent->left = child;
            else
                parent->right = child;
            
            par_map[child] = parent;
            list.push_back(parent);
        }
        
        for(auto i : list)
        {
            if(!par_map.count(i))
                return i;
        }
        
        return new TreeNode(0);
    }
};