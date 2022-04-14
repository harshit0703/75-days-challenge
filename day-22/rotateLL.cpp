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
    int findLen(ListNode *head)
    {
        int len = 0;
        while (head != NULL)
        {
            len++;
            head = head->next;
        }

        return len;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        int len = findLen(head);
        k %= len;

        if (k == 0)
            return head;

        int diff = len - k;
        int cnt = 1;
        ListNode *originalHead = head;

        while (cnt < diff)
        {
            head = head->next;
            cnt++;
        }

        ListNode *temp = head->next;
        ListNode *newHead = head->next;
        head->next = NULL;

        while (temp->next != NULL)
            temp = temp->next;
        temp->next = originalHead;

        return newHead;
    }
};