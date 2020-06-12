

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

    Note:

        You may only use constant extra space.
        You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

Example :

Given the following perfect binary tree,

         1
       /  \
      2    5
     / \  / \
    3  4  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 5 -> NULL
     / \  / \
    3->4->6->7 -> NULL

Note that using recursion has memory overhead and does not qualify for constant space.

____________________________________________________________________________________________________________________________________________________________________________________________________________________________


TreeLinkNode *nextRight(TreeLinkNode *A)
{
    TreeLinkNode *temp = A->next;
    
    if(temp == NULL)
     return NULL;
     
     return temp->left;
}
void Solution::connect(TreeLinkNode* A) {
    
    if(A == NULL)
     return ;
     
     A->next = NULL;
     if(A->left == NULL && A->right == NULL)
      return ;

     
     TreeLinkNode *p = A;
     while(p!= NULL)
     {
         TreeLinkNode *q = p;
         
         while(q != NULL && (q->left != NULL && q->right != NULL))
         {
               q->left->next = q->right;
               q->right->next = nextRight(q);
               q = q->next;
         }
         
     p=p->left;
     }
}
