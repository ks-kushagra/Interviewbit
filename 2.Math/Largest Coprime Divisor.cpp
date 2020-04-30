

You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

    X divides A i.e. A % X = 0
    X and B are co-prime i.e. gcd(X, B) = 1

For example,

A = 30
B = 12
We return
X = 5


_____________________________________________________________________________________________________________________________________________________________________



int gcd(int a,int b)
 {
     if(a==0)
      return b;
     if(b==0)
      return a;
     
     if(a>b)
      return gcd(a-b,b);
     return gcd(a,b-a);
 }
 
 
int Solution::cpFact(int A, int B) {
    int max =0;
    if(A==1)
       return 1;
     if(A>0 && B==0)
       return 1;
      
      if(gcd(A,B)==1)
         return A;
         
    for(int i=A;i>=1;i--)
        {
            
            if(A%i==0 && gcd(i,B)==1)
                max = (max>i?max:i);
        }
        return max;
}


_____________________________________________________________________________________________________________________________________________


Another Solotion

int gcd(int A, int B){
    if(A==0) return B;
    if(B==0) return A;
    if(A<B) swap(A, B);
    return gcd(A%B, B);
}
int Solution::cpFact(int A, int B) {
    for(int g=gcd(A, B); g>1; g=gcd(A, g)) A/=g;
    return A;
}


