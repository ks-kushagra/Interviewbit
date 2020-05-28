
    Asked in:  
    Google

Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5

_____________________________________________________________________________________________________________________________________________________________________________________________


 /*
 int size(ListNode *A)
 {
     if(A == NULL)
     return 0;
     
     int s=0;
     
     ListNode *p =A;
     while(p!=NULL)
      {
          p=p->next;
          s++;
      }
      
      return s;
 }
ListNode *merge(ListNode *p1 , ListNode *q1)
{
    ListNode *A =p1 , *B = q1;
    if(A == NULL)
    return B;
    
    if(B== NULL)
    return A;
    
    ListNode *head = NULL;
    ListNode *q= NULL;
    while(A != NULL && B != NULL)
    {
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->next=NULL;
        
        if(A->val < B ->val)
        {
            p->val = A->val;
            A=A->next;
        }
        
        else if(A->val > B->val )
         {
             p->val = B->val;
             B = B->next;
         }
         
         else
         {
             p->val = A->val;
             A= A->next;

         }
         
         if(head == NULL)
         {
             head = p;
             q=head;
         }
         
         else
         {
             q->next =p;
             q = q->next;
         }
    }
    
    
    if( A!= NULL)
    {
        q->next = A;
    }
    
    if(B!= NULL)
     q->next = B;
     
     
     return head;
}
ListNode* Solution::sortList(ListNode* A) {
    
    
    if(A ==NULL || A->next == NULL)
    return A;
    
    int n = size(A);
    int k = n/2-1;
    
    ListNode *p=A;
    while(k-- > 0)
     p= p->next;
     
     ListNode *q = p->next;
     p->next=NULL;
     
     ListNode *list1 = sortList(A);
     ListNode *list2 = sortList(q);
     ListNode *head =merge(list1 , list2);
     
     
     return head;
    
}
*/

____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
ListNode* merge(ListNode* A, ListNode* B){
    if(A == NULL){
        return B;
    }
    if(B == NULL){
        return A;
    }
    
    ListNode* head = NULL;
    
    if(A->val < B->val){
        head = A;
        A = A->next;
    }
    else{
        head = B;
        B = B->next;
    }
    
    ListNode* temp = head;
    
    while(A != NULL && B != NULL){
        if(A->val < B->val){
            temp->next = A;
            A = A->next;
        }
        else{
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    
    if(A != NULL){
        temp->next = A;
    }
    else{
        temp->next = B;
    }
    
    return head;
} 


ListNode* Solution::sortList(ListNode* A) {

    ListNode* head = A;
    
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* start = A;
    ListNode* end = A->next;
    
    while(end != NULL && end->next != NULL){
        start = start->next;
        end = (end->next)->next;
    }
    
    end = start->next;
    start->next = NULL;
    
    return merge(sortList(head), sortList(end)); 
}
