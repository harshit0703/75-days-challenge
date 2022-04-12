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
public:
    ListNode *middleNode(ListNode *head)
    {
        // this concept is derived somewhat from floyds cycle detection method
        ListNode *turtle = head, *rabbit = head;
        while (rabbit != NULL && rabbit->next != NULL)
        {
            turtle = turtle->next;
            rabbit = rabbit->next->next;
        }

        return turtle;
    }
};