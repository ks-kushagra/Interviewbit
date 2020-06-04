

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3

The above binary tree is symmetric.
But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

___________________________________________________________________________________________________________________________________________________________

int isSameTree(TreeNode* A, TreeNode* B) {

    if(A==NULL && B == NULL)
    return 1;
    
    if((A==NULL && B != NULL) || (A != NULL && B == NULL) || (A->val != B->val))
     return 0;
  
     int left = isSameTree(A->left , B->left);
     int right = isSameTree(A->right , B->right);
     
     return (left & right );
}

TreeNode *mirror(TreeNode *A)
{
    if(A== NULL)
    return NULL;
    
    TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
    p->val = A->val;
    p->left = mirror(A->right);
    p->right= mirror(A->left);
    
    return p;
}


int Solution::isSymmetric(TreeNode* A) {
TreeNode *B = mirror(A);
return isSameTree(A,B);
     
}  
