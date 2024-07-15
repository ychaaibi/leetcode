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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_set<int>                childs;
        unordered_map<int,vector<int>>    tree;
        TreeNode                            *root;

        for ( int i=0; i<des.size(); i++ )
            childs.insert(des[i][1]);

        for ( int i=0; i<des.size(); i++ )
        {
            if ( childs.find(des[i][0]) == childs.end() )
                root = new TreeNode(des[i][0]);

            if ( tree.find(des[i][0]) == tree.end() )
                tree[des[i][0]] = vector<int>();

            tree[des[i][0]].push_back( i );
        }

        queue<TreeNode*>  q;

        q.push(root);

        while ( !q.empty() )
        {
            TreeNode *curr = q.front();

            q.pop();
        
            if ( tree.find(curr->val) == tree.end() )
                continue ;

            for ( int i=0; i<tree[curr->val].size(); i++ )
            {
                TreeNode *child = new TreeNode(des[tree[curr->val][i]][1]);

                if ( !des[tree[curr->val][i]][2] )
                    curr->right = child;
                else
                    curr->left = child;
                
                q.push(child);
            }
        }

        return( root );
    }
};