

Given a binary tree, return the preorder traversal of its nodes’ values.

Example :
Given binary tree

   1
    \
     2
    /
   3

return [1,2,3].

Using recursion is not allowed.

__________________________________________________________________________________________________________________________________________________________________________________



vector<int> Solution::preorderTraversal(TreeNode* A) {

    vector <int>ans;
    if(A == NULL)
     return ans;
     
    stack <TreeNode *> s;
    s.push(A);
    
    while(!s.empty())
    {
        TreeNode *p=s.top();
        ans.push_back(p->val);
        s.pop();
        if(p->right)
        s.push(p->right);
        
        if(p->left)
        s.push(p->left);
    }
    
    return ans;
}
