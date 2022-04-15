/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {

        if (head == NULL)
            return head;

        Node *curr = head;

        while (curr != NULL)
        {
            if (curr->child != NULL)
            {
                Node *nextPtr = curr->next;
                Node *res = flatten(curr->child);
                curr->child = NULL;
                curr->next = res;
                res->prev = curr;
                while (res->next != NULL)
                    res = res->next;
                if (nextPtr)
                {
                    res->next = nextPtr;
                    nextPtr->prev = res;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};