Problem Description

Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time.


Input Format

First and only argument is an 2D integer array A of size M x N.


Output Format

Return a single integer denoting the minimum sum of a path from cell (1, 1) to cell (M, N).


Example Input

Input 1:

 A = [  [1, 3, 2]
        [4, 3, 1]
        [5, 6, 1]
     ]



Example Output

Output 1:

 8



Example Explanation

Explanation 1:

 The path is 1 -> 3 -> 2 -> 1 -> 1
 So ( 1 + 3 + 2 + 1 + 1) = 8
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________



int Solution::minPathSum(vector<vector<int> > &A) {
    
    if(A.size() == 0)
        return 0;
    
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<int> > temp(rows, vector<int>(cols));
    
    temp[0][0]=A[0][0];
    
    for(int i = 1; i < cols; i++)
       temp[0][i] = A[0][i] + temp[0][i-1];

    for(int i = 1; i < rows; i++)
        temp[i][0] = temp[i-1][0] + A[i][0];
    
    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            temp[i][j] = A[i][j] + min(temp[i-1][j], temp[i][j-1]);
        }
    }
    
    return temp[rows-1][cols-1];
}
