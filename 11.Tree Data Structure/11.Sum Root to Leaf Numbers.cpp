

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

_________________________________________________________________________________________________________________________________________________________________


int solve(TreeNode *A , int &ans , int temp)
{
    if(A == NULL)
     {
         ans = (ans + temp)%1003;
         return ans;
     }
     
     
    temp = (temp*10+A->val)%1003;
    
     if(A->left == NULL && A->right == NULL)
     {
         return ans = (ans + temp)%1003;
     }
     
     if(A->left)
     int left = solve(A->left , ans , temp);
     
     if(A->right)
     int right = solve(A->right , ans,temp);
     
     return ans;
}
int Solution::sumNumbers(TreeNode* A) {

  int ans =0;
  return solve(A,ans,0);
}
