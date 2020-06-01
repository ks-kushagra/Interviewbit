

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

    Note:

        All numbers (including target) will be positive integers.
        Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        The solution set must not contain duplicate combinations.

Example :

Given candidate set 10,1,2,7,6,1,5 and target 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

    Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
    Example : itertools.combinations in python.
    If you do, we will disqualify your submission retroactively and give you penalty points. 


___________________________________________________________________________________________________________________________________________________________________________________________________________


void solve(vector <vector <int> > &ans , vector <int> temp , vector <int> A, int B , int curr , int sum)
{
    if(sum > B)
    return;
    
    if(sum  ==  B)
    {
        if(find(ans.begin() , ans.end() , temp) == ans.end())
        ans.push_back(temp);
        return;
    }
    
    for(int i=curr;i<A.size();i++)
    {
        temp.push_back(A[i]);
        solve(ans , temp , A , B , i+1, sum + A[i]);
        temp.pop_back();
    }
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin() , A.end());
    vector<vector <int> > ans;
    vector <int> temp;
    solve(ans , temp , A, B,0,0);
    return ans;
}
