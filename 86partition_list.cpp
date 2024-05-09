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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lt = nullptr;

        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *ltiter = nullptr;
        ListNode *iter = new ListNode(0, head);

        while (iter != nullptr && iter->next != nullptr)
        {
            ListNode *fast = iter->next;
            if (fast->val < x)
            {
                iter->next = fast->next;
                if (fast == head)
                {
                    head = head->next;
                }
                fast->next = nullptr;
                if (lt == nullptr)
                {
                    lt = fast;
                    ltiter = fast;
                }
                else
                {
                    ltiter->next = fast;
                    ltiter = fast;
                }
            }
            else
                iter = iter->next;
        }
        if (lt == nullptr)
        {
            lt = head;
        }
        else
        {
            ltiter->next = head;
        }
        return lt;
    }
};