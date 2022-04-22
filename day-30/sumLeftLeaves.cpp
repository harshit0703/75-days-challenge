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
    bool isLeaf(TreeNode *root)
    {
        if (root->left == NULL && root->right == NULL)
            return true;

        return false;
    }

    void preorder(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return;

        if (root->left != NULL && isLeaf(root->left))
        {
            sum += root->left->val;
            preorder(root->right, sum);
        }

        else
        {
            preorder(root->left, sum);
            preorder(root->right, sum);
        }
    }

public:
    int sumOfLeftLeaves(TreeNode *root)
    {

        int sum = 0;
        preorder(root, sum);

        return sum;
    }
};