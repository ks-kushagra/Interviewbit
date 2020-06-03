

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Make sure the returned strings are lexicographically sorted.

_________________________________________________________________________________________________________________________________________________________________________

void solve(vector<string> v , vector <string> &ans , string A , string temp,int curr)
{
    if(temp.length() == A.length())
    {
        ans.push_back(temp);
        return;
    }
    
    for(int i=0;i<v[A[curr]-'0'].length();i++)
    {
        temp = temp + v[A[curr]-'0'][i];
        solve(v , ans , A , temp , curr+1);
        temp.pop_back();
    }
}
vector<string> Solution::letterCombinations(string A) {
    vector <string> v(10);
    vector <string> ans;
    v[0]="0",v[2]="abc",v[3]="def",v[4]="ghi",v[5]="jkl",v[1]="1",v[6]="mno",v[7]="pqrs",v[8] = "tuv",v[9]="wxyz";
    solve(v,ans,A,"",0);
    return ans;
    
}
