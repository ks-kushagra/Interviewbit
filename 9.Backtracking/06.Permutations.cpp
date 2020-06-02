

Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]

    NOTE

        No two entries in the permutation sequence should be the same.
        For the purpose of this problem, assume that all the numbers in the collection are unique.

    Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS.
    Example : next_permutations in C++ / itertools.permutations in python.
    If you do, we will disqualify your submission retroactively and give you penalty points. 
    ____________________________________________________________________________________________________________________________________________________________________________________________________________
    
    
    void solve(vector <int> A , vector <vector <int> > &ans , int l ,int e)
{
    
    if(l > e)
    return;
    
   if(l == e)
    ans.push_back(A);
    
    for(int i =l;i<=e;i++)
    {
        swap(A[i] , A[l]);
        solve(A , ans, l+1,e);
        swap(A[i] , A[l]);

    }
     
     
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    
    vector <vector <int >> ans;
    vector <int> temp;
    
    solve(A , ans ,0 , A.size()-1);
    
    return ans;
}
