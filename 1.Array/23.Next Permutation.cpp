

Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.

If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.

Note:

1. The replacement must be in-place, do **not** allocate extra memory.
2. DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION. Use of Library functions will disqualify your submission retroactively and will give you penalty points.

Input Format:

The first and the only argument of input has an array of integers, A.

Output Format:

Return an array of integers, representing the next permutation of the given array.

Constraints:

1 <= N <= 5e5
1 <= A[i] <= 1e9

Examples:

Input 1:
    A = [1, 2, 3]

Output 1:
    [1, 3, 2]

Input 2:
    A = [3, 2, 1]

Output 2:
    [1, 2, 3]

Input 3:
    A = [1, 1, 5]

Output 3:
    [1, 5, 1]

Input 4:
    A = [20, 50, 113]

Output 4:
    [20, 113, 50]


----------------------------------------------------------------------------------------------------------------------------------------------------------------------



vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    vector <int> v;
    if(n==0){
        return v;
    }
    
      if(n==1)
      {
         v.push_back(A[0]);
         return v;
      }
      
      
    else{
        int i=n-1;
        while(i>0&&A[i]<A[i-1]){
            i--;
        }
     
        int t=i-1;
        if(i==0){
            sort(A.begin(),A.end());
        }
        else{
            int temp=i;
            for(int j=i+1;j<n;j++){
                if(A[t]<A[j]&&A[temp]>A[j]){
                    temp = j;
                }
            }
            int l=A[temp];
            A[temp] = A[t];
            A[t]=l;
            sort(A.begin()+t+1,A.end());
        }
    }
    
    return A;
    
}
