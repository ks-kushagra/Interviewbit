

Given three sorted arrays A, B and Cof not necessarily same sizes.

Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
i.e. minimize | max(a,b,c) - min(a,b,c) |.

Example :

Input:

A : [ 1, 4, 5, 8, 10 ]
B : [ 6, 9, 15 ]
C : [ 2, 3, 6, 6 ]

Output:

1

Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.

____________________________________________________________________________________________________________________________________________________________________________________________________________



int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int i=0,j=0,k=0;
    int ans = INT_MAX;
    
    while( i < A.size() && j < B.size() && k < C.size())
    {
        int max1 = max(A[i] , max(B[j] , C [k]));
        int min1 = min( A[i] , min(B[j] , C[k]));
        ans = min(ans , abs ( max1 - min1 ));
        
        if(min1 == A[i])
          i++;
          
        else if(min1 == B[j])
         j++;
         
        else
         k++;
    }
    
    return ans;
}
