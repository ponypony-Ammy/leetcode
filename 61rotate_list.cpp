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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==nullptr)
        return head;
        ListNode* slow=head;
        ListNode* fast=head;
        int cnt=0;
        while(slow!=nullptr)
        {
            slow=slow->next;
            cnt++;
        }
        k=k%cnt;
        slow=head;
        // find length of linked list
        if (k==0)
        return head;
        for(int i=0;i<k;i++)
        {
            fast=fast->next;
        }
        while(fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=nullptr;
        return head;
    }
};