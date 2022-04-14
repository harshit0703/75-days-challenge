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

    ListNode *helper(ListNode *head, int k, int rem)
    {
        if (k > rem)
            return head;

        // reverse the k nodes and call recursively
        ListNode *curr = head, *prev = NULL, *nextPtr;
        int cnt = 1;
        while (cnt <= k)
        {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
            cnt++;
        }

        head->next = helper(nextPtr, k, rem - k);

        // now the prev will be pointing to the new head
        return prev;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // this question can be solved in multiple steps first reverse the k nodes and do the same thing recursively

        int len = findLen(head);
        ListNode *newHead = helper(head, k, len);
        return newHead;
    }
};