/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
private:
    int length(ListNode *&head)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }

        return len;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL || head->next == NULL)
            return NULL;

        // deleting the nth node from the back is equivalent as deleting the size - nth node from the start

        int len = length(head);

        int del = len - n;
        int curr = 1;

        if (del == 0)
            return head->next;

        ListNode *temp = head;

        while (curr != del)
        {
            temp = temp->next;
            curr++;
        }

        temp->next = temp->next->next;

        return head;
    }
};