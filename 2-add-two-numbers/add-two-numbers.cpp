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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*   ans=NULL;
        ListNode*   curr=NULL;
        int         rest = l1->val + l2->val;
            
        ans = new ListNode(rest % 10), curr = ans, rest /= 10;
        l1 = l1->next, l2 = l2->next;
        
        for ( ; l1 != NULL or l2 != NULL or rest; )
        {
            
            if ( l1 )
                rest += l1->val, l1 = l1->next;
            if ( l2 )
                rest += l2->val, l2 = l2->next;
            
            curr->next = new ListNode( rest % 10 ), curr = curr->next, rest /= 10;
        }
        
        return (ans);
    }
};