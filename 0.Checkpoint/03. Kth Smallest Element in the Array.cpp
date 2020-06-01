

Find the kth smallest element in an unsorted array of non-negative integers.

Definition of kth smallest element

    kth smallest element is the minimum possible n such that there are at least k elements in the array <= n.
    In other words, if the array A was sorted, then A[k - 1] ( k is 1 based, while the arrays are 0 based ) 

NOTE
You are not allowed to modify the array ( The array is read only ).
Try to do it using constant extra space.

Example:

A : [2 1 4 3 2]
k : 3

answer : 2

_____________________________________________________________________________________________________________________________________________________________________


int Solution::kthsmallest(const vector<int> &A, int B) {
    
    int n = A.size();
    int end = *max_element(A.begin() , A.end());
    int start = *min_element(A.begin() , A.end());
    
    while(start <= end)
    {
        int mid = (start + ( end - start)/2);
        int countless =0,countequal = 0;
        
        for(int i=0;i<n;i++)
          {
              if(A[i] < mid)
               countless++;
               
               else if(A[i] == mid)
                countequal++;
              
              
              if(countless > B)
              break;
          }
          
          if(countless < B && countless+countequal >= B)
            return mid;
            
           
          else if(countless >= B)
            end = mid -1;
            
          else 
          start = mid+1;
    }
    
    return -1;
}
