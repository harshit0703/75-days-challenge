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
// class Solution {
//     private:
//     bool solve(TreeNode* root, long minVal, long maxVal){
//         if(root == NULL) return true;
//         if(root->val >= maxVal || root->val <= minVal) return false;

//         return solve(root->left, minVal, root->val) && solve(root->right, root->val, maxVal);
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         return solve(root, LONG_MIN, LONG_MAX);
//     }
// };

class Solution
{
private:
    void solve(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        solve(root->left, v);
        v.push_back(root->val);
        solve(root->right, v);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        // we used a vector and so the space complexity will be O(N)
        vector<int> v;
        solve(root, v);
        int i = 0;
        while (i < v.size() - 1)
        {
            if (v[i] >= v[i + 1])
                return false;
            i++;
        }

        return true;
    }
};