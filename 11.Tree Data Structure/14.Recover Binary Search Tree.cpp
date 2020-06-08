

Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

    Note:
    A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 

Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST          


______________________________________________________________________________________________________________________________________________________________________________________________


void inorder(TreeNode *A,vector <int> &v)
{
    if(A == NULL)
    return;
    
    inorder(A->left,v);
    v.push_back(A->val);
    inorder(A->right,v);
}
vector<int> Solution::recoverTree(TreeNode* A) {

 vector <int> v;
 inorder(A , v);
 vector <int> ans;
 for(int i=1;i<v.size();i++)
    if(v[i] < v[i-1])
         {
          ans.push_back(v[i-1]);
          break;
         }
for(int i=v.size()-1;i>0;i--)
{
    if(v[i] < v[i-1])
      {ans.push_back(v[i]);
      break;}
}

if(ans[0] > ans[1])
  swap(ans[0],ans[1]);
  
return ans;
}
