

Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 


_______________________________________________________________________________________________________________________________________________________________________________________


int isPrime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
     {
         if(n%i ==0)
         return 0;
     }
     return 1;
}

vector<int> Solution::primesum(int A) {
    
    vector <int> ans;
    for(int i=2;i<=A/2;i++)
    {
        if(isPrime(i) && isPrime(A-i))
           {
               ans.push_back(i);
               ans.push_back(A-i);
               return ans;
           }
    }
    
    return ans;
}

_________________________________________________________________________________________________________________________________________________________________________________
vector<int> Solution::primesum(int A) {
  
    
int *seive = (int *)malloc((A+1) * sizeof(int));
vector <int> v;
//printf("%d",INT_MAX);
// memset(seive, 1, sizeof(seive));
    
  for(int i=2;i<=A;i++)
     {
         seive[i]=1;
     }
     
for(int i = 2; i*i <= A ; i++)
  {
      if(seive[i]== 1)
        {
           // seive[i]=1;
            for(int j = i*i; j<=A; j+=i)
               {
                   seive[j]=0;
               }
        }
  }
 
  for(int i=2;i<=A;i++)
     {
         if(seive[i]== 1 && seive[A - i] == 1 )
            {
                v.push_back(i);
                v.push_back(A-i);
                return v;
            }
     }
     
     return v;

}
