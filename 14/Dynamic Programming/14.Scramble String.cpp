

Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that “rgtae” is a scrambled string of “great”.


Given two strings A and B of the same length, determine if B is a scrambled string of S.


Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.

Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True

Constraints:

1 <= len(A), len(B) <= 50

Examples:

Input 1:
    A = "we"
    B = "we"

Output 1:
    1

Input 2:
    A = "phqtrnilf"
    B = "ilthnqrpf"
    
Output 2:
    0

_____________________________________________________________________________________________________________________________________________________________________________________________________________________________

int solve(string A , string B,unordered_map<string, int> &mp)
{
    string s = A + " " + B;
    
    if(mp.find(s) != mp.end())
    return mp[s];
    
    if(A.length() != B.length())
    return 0;
    
    if(A == B)
    return mp[s]=1;
    
    if(A.length()<=1)
    return 0;
    int n = A.length();
    for(int i=1;i<A.length();i++){
    int cond1 = solve(A.substr(0,i),B.substr(n-i,i),mp) && solve(A.substr(i,n-i) , B.substr(0,n-i),mp);
    int cond2 = solve(A.substr(0,i),B.substr(0,i),mp) && solve(A.substr(i,n-i) , B.substr(i,n-i),mp);
        if(cond1 || cond2)
         return mp[s]= 1;
    }
    
    return mp[s]=0;
}
int Solution::isScramble(const string A, const string B) {
 unordered_map<string, int>mp;
 return solve(A,B,mp);
}
