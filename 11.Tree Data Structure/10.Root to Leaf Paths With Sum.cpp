

Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]


____________________________________________________________________________________________________________________________________________________________________________________


void solve(TreeNode *A , int target ,vector<vector<int> > &ans , vector<int> temp)
{
    if(A->left == NULL && A->right == NULL && A->val == target)
    {
        temp.push_back(A->val);
        ans.push_back(temp);
        return;
    }
    
    temp.push_back(A->val);
    
    if(A->left)
         solve(A->left , target - A->val , ans, temp);
     
     if(A->right)
         solve(A->right , target - A->val , ans, temp);
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > ans;
    vector <int> temp;
    solve(A,B,ans,temp);
    return ans;
}
