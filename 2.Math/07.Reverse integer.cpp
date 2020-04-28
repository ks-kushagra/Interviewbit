


Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

___________________________________________________________________________________________________________________________________________________________________________________


int Solution::reverse(int A) {
    int sign=0;
    if(A<0)
      {
        sign =1;
        A=A*(-1);
      }

     if(A==0)
       return 0;
       
     int rev=0;
    while(A>0)
      {
        if((INT_MAX - A%10)/10 < rev)
           return 0;
          
          rev = rev*10 + A%10;
          A=A/10;
      }
      
      
      if(sign)
        return -rev;
     
     
      return rev;
}
