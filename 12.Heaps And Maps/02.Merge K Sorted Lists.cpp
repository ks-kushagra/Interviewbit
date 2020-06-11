

Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9

will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20


____________________________________________________________________________________________________________________________________________________________________________________


ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
priority_queue<pair<int, ListNode *> , vector <pair<int, ListNode *>> , greater< pair<int , ListNode *> > > pq;

for(int i=0;i<A.size();i++)
   pq.push({A[i]->val , A[i]});


ListNode *head = NULL;
ListNode *p = NULL;
while(!pq.empty())
{
    auto q = pq.top();
    pq.pop();
    
    if(head == NULL)
    {
        head = q.second;
        p=head;
    }
    
    else
     {
         p->next = q.second;
         p=p->next;
     }
     
     if(q.second->next)
     pq.push( {q.second->next->val , q.second->next});
}
 
return head;    
}
