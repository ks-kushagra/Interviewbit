

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

    Note:

        All numbers (including target) will be positive integers.
        Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        The combinations themselves must be sorted in ascending order.
        CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
        The solution set must not contain duplicate combinations.

Example,
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]

    Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
    Example : itertools.combinations in python.
    If you do, we will disqualify your submission retroactively and give you penalty points. 


_____________________________________________________________________________________________________________________________________________________________________________________________________________


int nonDecreasing(vector <int> v)
{
    for(int i=1;i<v.size();i++)
       {
           if(v[i] < v[i-1])
             return 0;
       }
       
       return 1;
}
void sumSubset(vector <vector <int> > &ans, set <vector <int> > &s1 , vector<int> temp ,vector <int> A ,int sum)
{
    if(sum ==0){
     if(s1.find(temp) == s1.end() && nonDecreasing(temp)) 
        {
            s1.insert(temp);
            ans.push_back(temp);
        }
    return;
    }
    
    
    if(sum < 0)
    return ;
    
    else
    {
    for(int i=0;i<A.size();i++)
    {
        temp.push_back(A[i]);
        sumSubset(ans,s1,temp,A,sum - A[i]);
        temp.pop_back();
    }
    }
    
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    vector <vector <int> > ans;
    set <vector <int> > s1;
    vector <int> temp;
    
    if(B ==0)
    return ans;
    
    if(A.size())
    sort(A.begin(),A.end());
    
    sumSubset(ans,s1,temp,A, B);
    
    return ans;
}
