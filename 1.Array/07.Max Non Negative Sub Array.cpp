

Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.
The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is 
invalid.
Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:
    1. If there is a tie, then compare with segment's length and return segment which has maximum length.
    2. If there is still a tie, then return the segment with minimum starting index.

Input Format:

The first and the only argument of input contains an integer array A, of length N.

Output Format:

Return an array of integers, that is a subarray of A that satisfies the given conditions.

Constraints:

1 <= N <= 1e5
1 <= A[i] <= 1e5

Examples:

Input 1:
    A = [1, 2, 5, -7, 2, 3]

Output 1:
    [1, 2, 5]

Explanation 1:
    The two sub-arrays are [1, 2, 5] [2, 3].
    The answer is [1, 2, 5] as its sum is larger than [2, 3].

Input 2:
    A = [10, -1, 2, 3, -4, 100]
    
Output 2:
    [100]

Explanation 2:
    The three sub-arrays are [10], [2, 3], [100].
    The answer is [100] as its sum is larger than the other two.




-----------------------------------------------------------------------------------------------------------------------------------------------------------------
int all_negative(vector<int> &A){
    for(int i=0;i<A.size();i++){
        if(A[i]>=0){
            return 0;
        }
    }
    return 1;
}
vector<int> Solution::maxset(vector<int> &A) {
    long cur_sum=0;
    int cur_len=0;
    int end =0;
    long max = INT_MIN;
    int max_len =0;
    int n = A.size();
    if(all_negative(A)){
        vector<int> a;
        return a;
    }
    for(int i=0;i<n;i++){
        if(A[i]>=0)
        {
            cur_sum = cur_sum+A[i];
            cur_len++;
        }
       if(i==n-1||A[i]<0)
       {
            if(cur_sum==max)
            {
                if(cur_len>max_len)
                {
                    max_len = cur_len;
                    if(i==n-1)
                        end =i;
                    
                    else
                        end = i-1;
                }
            }
            
            else
            {
                if(cur_sum>max)
                {
                    if(i!=n-1)
                    end = i-1;
                    
                    else if(i==n-1)
                    end =i;
                    
                max_len=cur_len;
                max = cur_sum;
                }
            }
            
            cur_sum =0;
            cur_len=0;
            
        }
    }
    vector<int> ans;
    for(int i = end-max_len;i<=end;i++)
          if(A[i]>=0)
          ans.push_back(A[i]);
    
    while(ans[0]==0&&ans.size()!=max_len){
        ans.erase(ans.begin());
    }
    return ans;
}
