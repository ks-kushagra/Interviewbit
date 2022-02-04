

Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]

    NOTE : k is 0 based. k = 0, corresponds to the row [1]. 

Note:Could you optimize your algorithm to use only O(k) extra space?



-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int Coeff(int n, int k)  
{  
    int res = 1;  
  
    if ( k > n - k )  
        k = n - k;  
  
    for (int i = 0; i < k; ++i)  
    {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
  
    return res;  
}
vector<int> Solution::getRow(int A) {
    vector<int > k;
    for(int i=0;i<=A;i++){
        k.push_back(Coeff(A,i));
    }
    return k;
}


--------------Another -----------------------------------
    vector<int> Solution::getRow(int A) {
    
       vector<int>temp;
    
        int n  = 1;
        for( int col = 0; col <= A ; col++){// nth row will have n + 1 elements in pascal triangle
            temp.push_back(n);
            n = n * (A - col)/(col + 1);
        }
    return temp; 
}
