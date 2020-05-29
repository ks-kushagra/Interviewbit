

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each
of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807

Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

______________________________________________________________________________________________________________________________________________________________________________________________________________________________________

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    ListNode *head = NULL, *q=NULL;
    int c=0;
    
    while( A!= NULL && B != NULL)
    {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->next=NULL;
        
        int sum = A->val + B->val + c;
        p->val = sum % 10;
        c=sum/10;
        
        A=A->next;
        B=B->next;
        
        if(head == NULL)
            {
                head = p;
                q=head;
            }
        
        else
        {
            q->next = p;
            q=q->next;
        }
    }
    
    while(A != NULL)
    {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->next=NULL;
        int sum = A->val + c;
        p->val = sum %10;
        c=sum/10;
        
        A=A->next;
        
         if(head == NULL)
            {
                head = p;
                q=head;
            }
        
        else
        {
            q->next = p;
            q=q->next;
        }

    }
    
        
    while(B!= NULL)
    {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->next=NULL;
        int sum = B->val + c;
        p->val = sum %10;
        c=sum/10;
        
        B=B->next;
        
         if(head == NULL)
            {
                head = p;
                q=head;
            }
        
        else
        {
            q->next = p;
            q=q->next;
        }

    }
    
    
    
    if(c == 1)
    {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->next=NULL;
        
        p->val =1;
        
                 if(head == NULL)
            {
                head = p;
                q=head;
            }
        
        else
        {
            q->next = p;
            q=q->next;
        }
    }
    
    return head;
    
}
