

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

You need to do this in place.

Note that if you end up using an additional array, you will only receive partial score.

Example:

If the array is

[
    [1, 2],
    [3, 4]
]

Then the rotated array becomes:

[
    [3, 1],
    [4, 2]
]


------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Solution::rotate(vector<vector<int> > &A) {
    
    int n = A.size();
    
    if(n==0){
        return;
    }
    
    
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
           int t = A[i][j];
           A[i][j]=A[n-i-1][j];
           A[n-i-1][j]=t;
        }
    }

  
   for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int t = A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=t;
         
        }
    }
}
