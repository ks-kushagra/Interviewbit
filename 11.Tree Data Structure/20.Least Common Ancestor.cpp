Find the lowest common ancestor in an unordered binary tree given two values in the tree.

    Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) 
    is the lowest (i.e. deepest) node that has both v and w as descendants. 

Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4

For the above tree, the LCA of nodes 5 and 1 is 3.

    LCA = Lowest common ancestor 

Please note that LCA for nodes 5 and 4 is 5.

        You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
        No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
        There are no duplicate values.
        You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.

______________________________________________________________________________________________________________________________________________________________________________________________________________________


int isPresent(TreeNode *A , int x)
{
    if(A == NULL)
    return 0;
    
    if(A->val == x)
     return 1;
     
     return isPresent(A->left ,x) || isPresent(A->right , x);
}

int solve(TreeNode *A , int a , int b)
{
    if(A == NULL)
    return 0;
    
    if(A->val == a || A->val == b)
     return A->val;
     
    int t1 = solve(A->left , a, b);
    int t2 = solve(A->right , a , b);
    
    if(t1 && t2)
     return A->val;
     
    return (t1 != 0 ? t1 : t2);
}
int Solution::lca(TreeNode* A, int B, int C) {
    
    if(!isPresent(A,B) || !isPresent(A ,C))
    return -1;
    
    
    return solve(A , B ,C);
}
