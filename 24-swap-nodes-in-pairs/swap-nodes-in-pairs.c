/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *current;
    int             val;
    
    current = head;
    while (current)
    {
        if (!current->next)
            return (head);
        val = current->next->val;
        current->next->val = current->val;
        current->val = val;
        current = current->next->next;
    }
    return (head);
}