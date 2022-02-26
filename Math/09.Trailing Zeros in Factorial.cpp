


Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Example :

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1


Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) +   ....

___________________________________________________________________________________________________________________________________________________________
  
  int Solution::trailingZeroes(int A) {
    int ans =0;
    while(A > 0){
        ans += A/5;
        A = A/5;
    }
    return ans;
}

___________________________________________________________________________________________________________________________________________________________


int Solution::trailingZeroes(int A) {
    if(A==0)
      return 0;
    int count =0;
    int t=1;
    while(A/(pow(5,t))>0)
      {
          count = count + floor(A/(pow(5,t++))); 
          
      }
    return count;
}

