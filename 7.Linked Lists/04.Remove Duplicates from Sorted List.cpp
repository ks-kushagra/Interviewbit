

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

_________________________________________________________________________________________________________________________________________________________


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode *p=A;
    if(A==NULL)
    return A;
    
    while(p->next != NULL)
    {
        if(p->val == p->next->val)
        {
            p->next = p->next->next;
        }
        
        else
         p=p->next;
    }
    
    return A;
}
