

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

Make sure the returned list of strings are sorted.

__________________________________________________________________________________________________________________________________________________________________

int isValid(string str)
{
    
    if(str.length() %2 != 0)
    return 0;
    
    stack <char> s;
    
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == ')')
        {
        if(s.empty())
           return 0;
           
          s.pop();
        }
          
         else
         s.push(str[i]);
    }
    
    
    if(!s.empty())
    return 0;
    
    return 1;
}

void solve(vector <string> &ans , string temp , int n)
{
    if(n < temp.length())
    return ;
    
    if(n == temp.length() && isValid(temp))
      {
          ans.push_back(temp);
          return;
      }
      
       solve(ans , temp + "(" , n);
       solve(ans , temp + ")" ,n);
       
}
vector<string> Solution::generateParenthesis(int A) {
    
    vector<string> ans;
    string temp;
    solve(ans , temp ,2*A);
    return ans;
}
