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
    void traverse( TreeNode* root, int val, int depth )
    {
        if ( !root )
            return ;
        if ( depth == 2 )
        {
            TreeNode *left = new TreeNode(val), *right = new TreeNode(val);
            left->left = root->left, right->right = root->right;
            root->left = left, root->right = right;
            return ;
        }
        traverse(root->left, val ,depth - 1);
        traverse(root->right, val, depth - 1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if ( depth == 1 )
        {
            TreeNode* new_root = new TreeNode(val);
            
            new_root->left = root;
            return ( new_root );
        }
        
        traverse( root, val, depth );
        return ( root );
    }
};