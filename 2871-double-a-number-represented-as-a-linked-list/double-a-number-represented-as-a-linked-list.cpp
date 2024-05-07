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
    int rest( ListNode* head )
    {
        int res = 0;

        if ( head->next )
            res = rest(head->next);

        int val = head->val * 2 + res;

        head->val = val % 10;

        return ( val / 10 );
    }

    ListNode* doubleIt(ListNode* head) {
        int res = rest( head );

        if ( res )
            head = new ListNode(res, head);
        
        return ( head );
    }
};