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
public:
    int widthOfBinaryTree(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        int ans = INT_MIN;

        while (!q.empty())
        {

            int n = q.size();
            int minIdx = q.front().second;
            int first, last;

            for (int i = 0; i < n; i++)
            {

                int currIdx = q.front().second - minIdx;
                TreeNode *temp = q.front().first;
                q.pop();

                if (temp->left)
                    q.push({temp->left, (long long)2 * currIdx + 1});
                if (temp->right)
                    q.push({temp->right, (long long)2 * currIdx + 2});

                if (i == 0)
                    first = currIdx;
                if (i == n - 1)
                    last = currIdx;
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};