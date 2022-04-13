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
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nextPtr;

        while (curr != NULL)
        {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }

        return prev;
    }

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
    bool isPalindrome(ListNode *head)
    {
        if (head->next == NULL)
            return true;
        // to do it in O(1) space what we can do is to first find the middle of the ll then reverse the ll from st to middle
        // and then use two pointer one from st and other from the middle and check them if they are diff return false

        int len = findLen(head);

        ListNode *mid = findMiddle(head);
        ListNode *newHead = mid->next;
        mid->next = NULL;
        ListNode *rev = reverse(head);

        if (len % 2 == 1)
            rev = rev->next;

        while (rev != NULL && newHead != NULL)
        {
            if (rev->val != newHead->val)
                return false;
            rev = rev->next;
            newHead = newHead->next;
        }

        if (rev == NULL && newHead == NULL)
            return true;
        return false;
    }
};