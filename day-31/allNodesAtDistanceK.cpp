/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp)
    {

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {

            TreeNode *temp = q.front();
            q.pop();

            if (temp->left)
            {
                mp[temp->left] = temp;
                q.push(temp->left);
            }

            if (temp->right)
            {
                mp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {

        // at first we need to mark all the parents
        unordered_map<TreeNode *, TreeNode *> parentTrack;

        markParents(root, parentTrack);

        // now simply use a bfs and travel in all three directions left right and parent and keep a track of the dist
        unordered_map<TreeNode *, bool> visited;
        int currDist = 0;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;

        while (!q.empty())
        {

            int n = q.size();
            if (currDist++ == k)
                break;

            for (int i = 0; i < n; i++)
            {

                TreeNode *temp = q.front();
                q.pop();

                if (temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }

                if (temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }

                if (parentTrack[temp] && !visited[parentTrack[temp]])
                {
                    q.push(parentTrack[temp]);
                    visited[parentTrack[temp]] = true;
                }
            }
        }

        // at the end all the elements present in the queue will be at a distance k

        vector<int> ans;

        while (!q.empty())
        {

            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};