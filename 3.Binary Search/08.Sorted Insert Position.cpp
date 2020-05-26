


Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0


______________________________________________________________________________________________________________________________________________________________________________-


int Solution::searchInsert(vector<int> &A, int B) {

    
    int n = A.size();
    int start =0;
    int end = n-1;
    
    if(n==0)
    return 0;
    
    if(B < A[0])
    return 0;
    
    if(B > A[n-1])
    return n;
    
    
    int ans=-1;
    while(start <= end)
    {
        int mid = ( start + (end - start)/2);
        
        if(A[mid] == B)
        return mid;
        
        if(A[mid] > B)
        {
            end = mid-1;
            ans = mid;
        }
        
        else
        start = mid+1;
    }
    
   
    
    return ans;
}
