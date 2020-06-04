

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

    Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3


_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


//Pass vector V by reference instead of value…TreeNode*cal(int l, int r,const vector &V)
TreeNode *solve(const vector <int> &A, int start ,int end)
{
    if(start > end)
    return NULL;

   int mid = (start+end)/2;
   TreeNode *p = (TreeNode *)malloc(sizeof(TreeNode));
   p->val = A[mid];
   p->left = solve(A , start,mid-1);
   p->right = solve(A , mid+1, end);
   return p;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
 return solve(A,0,A.size()-1);    
}
