


Given a matrix of integers A of size N x M and an integer B.

Write an efficient algorithm that searches for integar B in matrix A.

This matrix A has the following properties:

        Integers in each row are sorted from left to right.
        The first integer of each row is greater than or equal to the last integer of the previous row.

Return 1 if B is present in A, else return 0.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Input Format

The first argument given is the integer matrix A.
The second argument given is the integer B.

Output Format

Return 1 if B is present in A, else return 0.

Constraints

1 <= N, M <= 1000
1 <= A[i][j], B <= 10^6

For Example

Input 1:
    A = 
    [ [1,   3,  5,  7],
      [10, 11, 16, 20],
      [23, 30, 34, 50]  ]
    B = 3
Output 1:
    1

Input 2:
    A = [   [5, 17, 100, 111]
            [119, 120,  127,   131]    ]
    B = 3
Output 2:
    0
____________________________________________________________________________________________________________________________________________________________________

  int findRow(vector<vector<int>> &A , int B){
    int rowSize = A.size();
    int colSize = A[0].size();
    int start =0, end = rowSize-1;

    while(start<=end){
        int mid = (start+end)/2;

        if(A[mid][0]<=B && A[mid][colSize-1]>=B){
            return mid;
        }

        if(A[mid][0]>B){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}

int binarySearch(vector<int> A , int B) {
    int start =0 , end = A.size()-1;

    while(start<=end){
        int mid = (start+end)/2;

        if(A[mid]==B){
            return mid;
        }else if(A[mid]<B){
            start  = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}
int Solution::searchMatrix(vector<vector<int> > &A, int B) {

    int row=findRow(A,B);
    if(row == -1){
        return 0; // out of range
    }

    return (binarySearch(A[row] , B)==-1)?0:1;
}

____________________________________________________________________________________________________________________________________________________________________


int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    
    int i =0;int n = A.size(),m=A[0].size();
    int j = m-1;
    while(i>=0 && i <n && j>=0 && j<m)
    {
        if(A[i][j] == B)
        return 1;
        
        if(A[i][j] > B)
        j--;
        
        else
        i++;
    }
    
    
    return 0;
}
