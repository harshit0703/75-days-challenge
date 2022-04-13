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

    void display(ListNode *head)
    {
        while (head != NULL)
        {
            cout << head->val << "->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }

    ListNode *add(ListNode *a, ListNode *b)
    {
        int carry = 0;

        ListNode *dummy = new ListNode(-1);
        ListNode *newHead = dummy;
        ListNode *temp = dummy;

        while (a != NULL && b != NULL)
        {
            int sum = a->val + b->val + carry;
            carry = 0;
            if (sum >= 10)
            {
                carry = 1;
                sum %= 10;
            }

            ListNode *ptr = new ListNode(sum);
            temp->next = ptr;
            temp = temp->next;
            a = a->next;
            b = b->next;
        }

        while (a != NULL)
        {
            int sum = a->val + carry;
            carry = 0;
            if (sum >= 10)
            {
                carry = 1;
                sum %= 10;
            }

            ListNode *ptr = new ListNode(sum);
            temp->next = ptr;
            temp = temp->next;
            a = a->next;
        }

        while (b != NULL)
        {
            int sum = b->val + carry;
            carry = 0;
            if (sum >= 10)
            {
                carry = 1;
                sum %= 10;
            }

            ListNode *ptr = new ListNode(sum);
            temp->next = ptr;
            temp = temp->next;
            b = b->next;
        }

        if (carry != 0)
        {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }

        display(newHead->next);

        return newHead->next;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *a = reverse(l1);
        ListNode *b = reverse(l2);

        display(a);
        display(b);

        // now we just need to add them and then finally reverse the result as well

        ListNode *res = add(a, b);

        ListNode *ans = reverse(res);

        return ans;
    }
};