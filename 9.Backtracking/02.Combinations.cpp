

Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

    Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
    Entries should be sorted within themselves.

Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

    Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
    Example : itertools.combinations in python.
    If you do, we will disqualify your submission retroactively and give you penalty points. 

________________________________________________________________________________________________________________________________________________________________________________________


void solve(vector <vector <int> > &ans , vector <int> temp ,int A ,int B , int curr)
{
 if(temp.size()== B)
   {
       ans.push_back(temp);
       return;
   }
   
   for(int i=curr;i<=A;i++)
   {
       temp.push_back(i);
       solve(ans , temp , A , B , i+1);
       temp.pop_back();
   }
  
  
}
vector<vector<int> > Solution::combine(int A, int B) {
    vector < vector <int> > ans;
    vector <int> temp;
    solve(ans,temp,A , B , 1);
    return ans;
}


_____________________________________________________________________________________________________________________________________________________________________________________________________


void combinations(int n ,int k ,vector < vector <int> > &ans, vector <int> temp,int curr)
{
    if(temp.size()==k)
     ans.push_back(temp);
     
    if(temp.size() > k)
    return ;
     
     else
     {
         for(int i=curr;i<=n;i++)
         {
             
                  temp.push_back(i);                   //If you include the number in the subset
                  combinations(n,k,ans,temp,i+1);
                  temp.pop_back();                     //If you dont include that number
         }
     }
}

vector<vector<int> > Solution::combine(int A, int B) {
    
    vector <int> temp;
    vector<vector <int> > ans;
    
    if(B==0)
    return ans;
    
    if(B==1)
    {
        for(int i=1;i<=A;i++)
       { temp.push_back(i);
        ans.push_back(temp);
        temp.pop_back();
       }
        return ans;
    }
    
    if(A<B)
    return ans;
    
    combinations(A,B,ans,temp,1);
    
    return ans;
    
}
