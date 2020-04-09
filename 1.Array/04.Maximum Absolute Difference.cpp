

You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.

-------------------------------------------------------------------------------------------------------------------------

int MAX(int i,int j)
{
    return (i>=j?i:j);
}

int MIN(int i,int j)
{
    return (i<j?i:j);
}
int Solution::maxArr(vector<int> &A) {

    int n = A.size();
    int max1=INT_MIN; int max2=INT_MIN; int max3=INT_MIN; int max4=INT_MIN; 
    int min1 =INT_MAX;int min2 =INT_MAX;int min3 =INT_MAX;int min4 =INT_MAX;
    int ans =INT_MIN;
    for(int i =0;i<n;i++){
        max1 = MAX(max1,A[i]+i);
        max2 = MAX(max2,A[i]-i);
        max3 = MAX(max3,-A[i]+i);
        max4 = MAX(max4,-A[i]-i);
        
        min1 = MIN(min1,A[i]+i);
        min2 = MIN(min2,A[i]-i);
        min3 = MIN(min3,-A[i]+i);
        min4 = MIN(min4,-A[i]-i);
    }
    ans = MAX(ans,max1-min1);
    ans = MAX(ans,max2-min2);
    ans = MAX(ans,max3-min3);
    ans = MAX(ans,max4-min4);
    return ans;
}
