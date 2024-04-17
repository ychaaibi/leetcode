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
    string ans;
    
    string& _min(string& s1, string& s2)
    {
        for ( int i=s1.length() - 1, j=s2.length() - 1; i>=0 and j>=0; i--, j-- )
            if ( s1[i] != s2[j] )
                return ( (s1[i] > s2[j]) ? s2 : s1 );
        
        return ( (s1.length() > s2.length()) ? s2 : s1 );
    }
    
    void    traverse( TreeNode* root, string& curr )
    {
        curr.push_back(root->val + 'a');
        if ( !root->left and !root->right )
        {
            if ( ans != "" )
                ans = _min(ans, curr);
            else
                ans = curr;
            curr.pop_back();
            return ;
        }
        
        if ( root->right )
            traverse(root->right, curr);
        if ( root->left )
            traverse(root->left, curr);
        curr.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string curr;
        
        traverse(root, curr);
        reverse(ans.begin(), ans.end());
        return ( ans );
    }
};

