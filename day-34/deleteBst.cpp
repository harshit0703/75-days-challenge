Node *deleteNode(Node *root, int key)
{
    if (root)
    {
        if (key < root->data)
            root->left = deleteNode(root->left, key);

        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else
        {
            if (!root->left && !root->right)
                return NULL;
            // No child condition
            if (!root->left || !root->right)
                return root->left ? root->left : root->right;
            // One child cond -> replace the node with it's child

            // Two child condition
            Node *temp = root->left;
            while (temp->right != NULL)
                temp = temp->right;

            root->data = temp->data;

            root->left = deleteNode(root->left, temp->data);
        }
    }
    return root;
}