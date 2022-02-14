Given a string, find the rank of the string amongst its permutations sorted lexicographically.
Assume that no characters are repeated.

Example :

Input : 'acb'
Output : 2

The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba

The answer might not fit in an integer, so return your answer % 1000003

________________________________________________________________________________________________________________________________________________________________-

int count(string s,int i)
  {
      char t = s[i];
      int c=0;
      for(int j=i+1;j<s.length();j++)
        {
            if(t > s[j])
              c++;
        }
        return c;
  } 
  int fact(int n)
    {if(n==0)
       return 0;
      if(n==1)
        return 1;
        
        return (n*fact(n-1))%1000003;
    } 
    
    
int Solution::findRank(string A) {
  
  int repeat=0;
  vector<char> s;
   for(int i=0;i<A.length();i++)
       s.push_back(A[i]);
       
    sort(s.begin(),s.end());
    
    for(int i=0;i<s.size()-1;i++)
       {
           if(s[i]==s[i+1])
             return 0;
       }
       
       int rank=0;
 for(int i=0;i<A.length();i++)
    {
        int c = count(A,i);
        if(c)
         rank = (rank%1000003 + c*fact(A.length()-i-1)%1000003)%1000003; 
         else
          {
              continue;
          }
    }
      return (rank+1)%1000003;
}
