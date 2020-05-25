

Given an integar A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY



Input Format

The first and only argument given is the integer A.

Output Format

Return floor(sqrt(A))

Constraints

1 <= A <= 10^9

For Example

Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3

_______________________________________________________________________________________________________________________________________________________________________


int Solution::sqrt(int A) {
    
    int start =1;
    int end = A/2;
    
    if(A<=1)
    return A;
    
    int ans=0;
    while(start <= end)
    {
        int mid = ( start + (end - start)/2 );
        
        if(mid == A/mid)
         {
             ans =mid;
             break;
         }
         
         
         if(mid < A / mid)
           {
               start = mid+1;
               ans = mid;
           }
           
          else
            end = mid -1;
    }
    
  return ans;  
}
