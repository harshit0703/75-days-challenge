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
    TreeNode *solve(vector<int> &preorder, int prest, int preen, vector<int> &postorder, int postst, int posten)
    {

        if (prest > preen)
            return NULL;

        TreeNode *root = new TreeNode(preorder[prest]);
        if (prest == preen)
            return root;

        int idx = postst;
        while (postorder[idx] != preorder[prest + 1])
            idx++;

        int cnt = idx - postst + 1;

        root->left = solve(preorder, prest + 1, prest + cnt, postorder, postst, idx);
        root->right = solve(preorder, prest + cnt + 1, preen, postorder, idx + 1, posten - 1);

        return root;
    }

public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {

        int n = preorder.size();

        return solve(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};