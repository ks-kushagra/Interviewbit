

Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.


______________________________________________________________________________________________________________________________________________________________________________


int Solution::pow(int x, int n, int d) {

    if(n == 0)
    return (1%d);
    
    if(n==1)
     return ( (x+d) % d);
     
     
     long long int t = pow(x , n/2 ,d)%d;
     
     if(n % 2 != 0)
         return  ( (x %d)* ((t*t)%d)  )%d;
    
    else
    return (t * t)%d;
}
