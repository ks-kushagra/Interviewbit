

You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;

Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C. 


_____________________________________________________________________________________________________________________________________________________________________

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

int i=0;
int j=0;
int k=0;
int ans = INT_MAX;

while(i < A.size() && j<B.size() && k < C.size())
{
    int diff1 = abs(A[i] - B[j]);
    int diff2 = abs(B[j] - C[k]);
    int diff3 = abs(A[i] - C[k]);
    
    int temp = max( diff1 , max(diff2 , diff3));
    
    ans = min(ans , temp);
    
    int t =  min(A[i] , min( B[j] , C[k]));
    
    if( t == A[i])
       i++;
       
     else if(t == B[j])
     j++;
     
     else k++;
}
    
    return ans;
}

___________________________________________________________________________________________________________________________________________

 int minimize(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
        int diff = INT_MAX;
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        int i, j, k;
        for(i = 0, j = 0, k = 0; i < a.size() && j < b.size() && k < c.size();) {
            minimum = min(a[i], min(b[j], c[k]));
            maximum = max(a[i], max(b[j], c[k]));
            diff = min(diff, max - min);
            if (diff == 0) break;
            if (a[i] == minimum) i++;
            else if (b[j] == minimum) j++;
            else k++;
        }
        return diff;
    }
