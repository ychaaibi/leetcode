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
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int         len = 0, f = 1;
        ListNode    *curr = head, *prev, *nw, *nw_head, *prev_head;
        
        while (curr && ++len)
            curr = curr->next;
        nw_head = head;
        while (len >= k)
        {
            prev = nw_head;
            curr = nw_head->next;
            for (int i=0; i<k-1; i++)
            {
                nw = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nw;
            }
            if (f)
            {
                head->next = NULL;
                head = prev;
                prev_head = nw_head;
                prev_head->next = curr;
                f = 0;
            }
            else
            {
                prev_head->next = prev;
                prev_head = nw_head;
                nw_head->next = curr;
            }
            nw_head = curr;
            len -= k;
        }
        return (head);
    }
};