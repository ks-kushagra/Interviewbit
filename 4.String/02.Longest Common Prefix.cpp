

Given the array of strings A,
you need to find the longest string S which is the prefix of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
and S2.

For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".



Input Format

The only argument given is an array of strings A.

Output Format

Return longest common prefix of all strings in A.

For Example

Input 1:
    A = ["abcdefgh", "aefghijk", "abcefgh"]
Output 1:
    "a"
    Explanation 1:
        Longest common prefix of all the strings is "a".

Input 2:
    A = ["abab", "ab", "abcd"];
Output 2:
    "ab"
    Explanation 2:
        Longest common prefix of all the strings is "ab".

_____________________________________________________________________________________________________________________________________________________________________________________________________________


string lcp(string a , string b)
{
    int i=0;
    int j=0;
    
    string s ="";
    
    while( i< a.length() && j < b.length())
    {
        if(a[i] == b[j])
        {
            s = s + a[i];
            i++;
            j++;
        }
        
        else
         break;
    }
    
    
    return s;
}
string Solution::longestCommonPrefix(vector<string> &A) {
    
    int n = A.size();
    
    if(n == 0)
    return "";
    
    if(n == 1)
     return A[0];
     
    string s = lcp(A[0],A[1]);
    
    for(int i=2;i<n;i++)
    {
        s = lcp(s , A[i]);
    }
    
    return s;
}
