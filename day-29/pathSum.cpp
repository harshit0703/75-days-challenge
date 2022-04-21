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
    void allPaths(TreeNode *root, int sum, vector<int> &v)
    {

        if (root == NULL)
        {
            return;
        }

        sum += root->val;

        if (root->left == NULL && root->right == NULL)
        {
            v.push_back(sum);
            return;
        }

        allPaths(root->left, sum, v);
        allPaths(root->right, sum, v);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {

        if (root == NULL)
            return false;

        vector<int> v;
        allPaths(root, 0, v);

        for (auto i : v)
        {
            if (i == targetSum)
                return true;
        }

        return false;
    }
};