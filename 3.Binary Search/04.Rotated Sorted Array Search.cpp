

Given an array of integers A of size N and an integer B.

array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value B to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.

        NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*

Input Format

The first argument given is the integer array A.
The second argument given is the integer B.

Output Format

Return index of B in array A, otherwise return -1

Constraints

1 <= N <= 1000000
1 <= A[i] <= 10^9
all elements in A are disitinct.

For Example

Input 1:
    A = [4, 5, 6, 7, 0, 1, 2, 3]
    B = 4
Output 1:
    0
Explanation 1:
 Target 4 is found at index 0 in A.


Input 2:
    A = [5, 17, 100, 3]
    B = 6
Output 2:
    -1


______________________________________________________________________________________________________________________________________________________________________________________-


int findSmallest(const vector <int> A , int n)
{
    int start =0;
    int end = n-1;
    int ans = -1;
    
    while( start <= end)
    {
        int mid = ( start + (end - start)/2);
        
        int prev = (mid -1 + n)%n; 
        int next = (mid +1)%n;
        
        if( (A[prev] >= A[mid]) && (A[next] >= A[mid]))
         {
             ans = mid;
             break;
         }
         
        if(A[start] <= A[mid] && A[mid] <= A[end])
         return start;
        
        if(A[mid] >= A[start])
        {
            start = mid+1;
        }
        
        else if(A[mid] <= A[end])
         end = mid -1;
    }
    
    return ans;
}


int binSearch(const vector <int> A , int start,int end ,int k)
{
    while(start <= end)
    {
        int mid = (start + (end - start) /2);
        
        if(A[mid] == k)
         return mid;
         
        else if(A[mid] < k)
        start = mid+1;
        
        else
         end = mid-1;
    }
    
    return -1;
}
int Solution::search(const vector<int> &A, int B) {
    
    
    int min_index = findSmallest(A,A.size());
    
    if(A[min_index] == B)
     return min_index;
     
     
    int t1 = binSearch(A , 0 , min_index -1,B);
    int t2 = binSearch(A , min_index+1 , A.size()-1 , B);
    
    
    if(t1 != -1)
     return t1;
     
     else 
     return t2;
}

_________________________________________________________________________________________________________________________________________________________________




int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(A[mid] == B) return mid;
        else if(A[0]<=A[mid]){//i.e. left part is sorted
            if(A[0]<=B && B < A[mid]) high = mid-1;//B lies on left part
            else low = mid+1;
        }else{//right part is sorted
            if(A[mid] < B && B<=A[n-1]) low = mid+1;//B lies on right part
            else high = mid-1;
        }
    }
    return -1;
}


