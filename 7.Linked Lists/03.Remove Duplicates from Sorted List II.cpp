


Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

__________________________________________________________________________________________________________________________________________________________________
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(A==NULL||A->next == NULL)
    return A;

    map <int, pair<ListNode *,int> > mp;
    ListNode *p=A;
     
    while(p!=NULL)
     {
         if(mp.find(p->val) == mp.end())
         {
         ListNode *q = (ListNode *)malloc(sizeof(ListNode));
         q->val = p->val;
         mp[p->val] = {q , 1} ;
         }
         
         else
           mp[p->val].second++;
           
       p=p->next;
     }
     
     A = NULL;
     p=A;
     
     for(auto it = mp.begin();it != mp.end() ;it++)
     {
         if((it->second).second == 1)
         {
             if(A == NULL)
             {
                 A = ((it->second).first);
                 p=A;
             }
             
             else
             {
                 p->next = (it->second).first;
                 p=p->next;
             }
         }
     }
     
     return A;
}
