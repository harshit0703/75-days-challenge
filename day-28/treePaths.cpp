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
class Solution
{
private:
    void solve(TreeNode *root, string str, vector<string> &ans)
    {

        if (root == NULL)
            return;

        str += to_string(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(str);
            return;
        }

        str += "->";

        solve(root->left, str, ans);
        solve(root->right, str, ans);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {

        vector<string> ans;
        solve(root, "", ans);

        return ans;
    }
};