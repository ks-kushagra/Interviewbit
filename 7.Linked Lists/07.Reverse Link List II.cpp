

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

    Note:
    Given m, n satisfy the following condition:
    1 ≤ m ≤ n ≤ length of list.

    Note 2:
    Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question. 


____________________________________________________________________________________________________________________________________________________________________________________

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    if(A==NULL || A->next == NULL || B == C)
    return A;
    
    int k1=B-2;
    ListNode *l = A;
    int t=k1;
    while(k1-- > 0)
    {
        l=l->next;
    }
    
    ListNode *temp = l->next;
    
    if(t == -1)
     temp=l;
     
     ListNode *p=NULL,*q=temp,*r =q->next;
    
     
    int k = C-B+1;
    
    while(r != NULL && k-->0)
    {
         q->next = p;
         p=q;
         q=r;
         r=r->next;
    }
    
    if(k > 0)
    {
         q->next = p;
         p=q;
         q=r; 
    }
    
        temp->next = q;

    if(t == -1)
    return p;
    
    l->next = p;
    
    return A;
    
}
