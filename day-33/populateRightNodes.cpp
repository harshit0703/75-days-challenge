/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {

        if (root == NULL)
            return root;
        // from the given pic we can assume we have to perfom a level order traversal and simply connect the next
        // pointer with the next node in the level

        Node *newRoot = root;
        queue<Node *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp != NULL)
            {
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);

                if (q.front() != NULL)
                {
                    temp->next = q.front();
                }
            }

            else
            {
                if (q.empty())
                    break;
                q.push(NULL);
            }
        }

        return newRoot;
    }
};