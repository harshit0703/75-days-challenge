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
    TreeNode *solve(int st, int en, vector<int> &nums)
    {
        if (st > en)
            return NULL;

        int mid = st + (en - st) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(st, mid - 1, nums);
        root->right = solve(mid + 1, en, nums);

        return root;
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        int st = 0;
        int en = nums.size() - 1;

        return solve(st, en, nums);
    }
};