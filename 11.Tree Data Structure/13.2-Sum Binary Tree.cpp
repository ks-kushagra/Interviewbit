

Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

    Your solution should run in linear time and not take memory more than O(height of T).
    Assume all values in BST are distinct.

Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0

_____________________________________________________________________________________________________________________________________________________________________________________________


TreeNode *root = NULL;
int isPresent(TreeNode *A,int x,TreeNode *curr)
{
    if(A == NULL)
     return 0;
    
    if(A->val == x && curr != A)
    return 1;
    
    if(A->val > x)
      return isPresent(A->left , x, curr);
    
    else
    return isPresent(A->right , x, curr);
}
int solve(TreeNode *A , int B , TreeNode *curr)
{
  
  if(curr == NULL)
  return 0;
  
  if(isPresent(A , B-curr->val,curr))
   return 1;
   
   int t1 = solve(A , B , curr->left);
   if(t1)
   return t1;
   int t2 = solve(A , B, curr->right);
   if(t2)
   return t2;
   
   return 0;
}
int Solution::t2Sum(TreeNode* A, int B) {
 
 return solve(A , B, A);
}




__________________________________________________________________________________________________________________________________________________________________________________________________________________________
//
                            ???Partially Accepted??
//



TreeNode *root = NULL;
int isPresent(TreeNode *A,int x,TreeNode *curr)
{
    if(A == NULL)
     return 0;
    
    if(A->val == x && curr != A)
    return 1;
    
    int t1 = isPresent(A->left ,x,curr);
    int t2 = isPresent(A->right,x,curr);
    
    return t1 || t2;
}
int solve(TreeNode *A , int B , TreeNode *curr)
{
  
  if(curr == NULL)
  return 0;
  
  if(isPresent(A , B-curr->val,curr))
   return 1;
   
   int t1 = solve(A , B , curr->left);
   if(t1)
   return t1;
   int t2 = solve(A , B, curr->right);
   if(t2)
   return t2;
   
   return 0;
}
int Solution::t2Sum(TreeNode* A, int B) {
 
 return solve(A , B, A);
}

___________________________________________________________________________________________________________________________________________________________________________


Another approach is that you can inorder the tree ans store every element hih results you a sorted vector.
    Now you can use 2 pointers approach for finding sum of two elements
    
