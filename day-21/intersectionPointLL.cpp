/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
            head = head->next;
            len++;
        }
        return len;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL)
            return headB->next;
        if (headB == NULL)
            return headA->next;
        // basically for them to intersect just find the length of them and elminate the diff so that you can find the common intersection

        int lenA = findLen(headA);
        int lenB = findLen(headB);

        if (lenA > lenB)
        {
            while (lenA > lenB)
            {
                headA = headA->next;
                lenA--;
            }
        }

        else if (lenB > lenA)
        {
            while (lenB > lenA)
            {
                headB = headB->next;
                lenB--;
            }
        }

        while (headA != NULL && headB != NULL)
        {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};