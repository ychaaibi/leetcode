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
        // unordered_set<int>                  childs;
        // unordered_map<int,vector<int>>      tree;
        vector<bool>                        childs(1e5 + 1, false);
        vector<vector<int>>                 tree(1e5 + 1);

        TreeNode                            *root;

        for ( int i=0; i<des.size(); i++ )
            childs[des[i][1]] = true;

        for ( int i=0; i<des.size(); i++ )
        {
            if ( !childs[des[i][0]] )
                root = new TreeNode(des[i][0]);

            tree[des[i][0]].push_back( i );
        }

        queue<TreeNode*>  q;

        q.push(root);

        while ( !q.empty() )
        {
            TreeNode *curr = q.front();

            q.pop();

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