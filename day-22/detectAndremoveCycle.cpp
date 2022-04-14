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
public:
    ListNode *detectCycle(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return NULL;

        // now to detect a cycle we will apply floyd warshall cycle detection method
        ListNode *slow = head, *fast = head;
        bool cyclePresent = false;

        while (fast != NULL && fast->next != NULL)
        {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                cyclePresent = true;
                break;
            }
        }

        if (!cyclePresent)
            return NULL;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};