
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap 
after raining.



Input Format

The only argument given is integer array A.

Output Format

Return the total water it is able to trap after raining..

For Example

Input 1:
    A = [0,1,0,2,1,0,1,3,2,1,2,1]
Output 1:
    6
Explaination 1: <img src="http://i.imgur.com/0qkUFco.png">
    
    In this case, 6 units of rain water (blue section) are being trapped
    ___________________________________________________________________________________________________________________________________________________________________________________________
    
    
    int Solution::trap(const vector<int> &A) {
    
    int n = A.size();
    vector <int> maxLeft(n);
    vector <int> maxRight(n);
    int sum =0;
    maxLeft[0]=A[0];
    maxRight[n-1]=A[n-1];
    
    for(int i=1;i<n;i++)
      maxLeft[i] = max(A[i] , maxLeft[i-1]);
      
    for(int i=n-2;i>=0;i--)
     maxRight[i] = max(A[i] , maxRight[i+1]);
     
     
     for(int i=0;i<n;i++)
       sum = sum +   min(maxLeft[i] , maxRight[i]) - A[i];
       
       
     return sum;
     
}
