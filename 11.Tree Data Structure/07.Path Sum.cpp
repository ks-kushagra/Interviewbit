

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

__________________________________________________________________________________________________________________________________________________________________________________________________________________


int Solution::hasPathSum(TreeNode* A, int B) {

if(A==NULL && B == 0)
return 1;
if(A==NULL && B != 0)
return 0;

if(A->left == NULL && A->right == NULL)
{
    if(A->val == B)
    return 1;
    
    else
    return 0;
}

int left=0,right=0;

if(A->left)
left = hasPathSum(A->left , B-A->val);

if(A->right)
right = hasPathSum(A->right, B-A->val);

return left || right;

    
}
