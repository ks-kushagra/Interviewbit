

Given N x M character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)



Input Format:

    The First and only argument is a N x M character matrix.

Output Format:

    Return a single integer denoting number of black shapes.

Constraints:

    1 <= N,M <= 1000
    A[i][j] = 'X' or 'O'

Example:

Input 1:
    A = [ OOOXOOO
          OOXXOXO
          OXOOOXO  ]
Output 1:
    3
Explanation:
    3 shapes are  :
    (i)    X
         X X
    (ii)
          X
    (iii)
          X
          X

Note: we are looking for connected shapes here.

XXX
XXX
XXX

is just one single connected black shape.

___________________________________________________________________________________________________________________________________________________________________________________________________________


void dfs(vector <string> A , vector<vector <int> > &visited, int i, int j)
{
    if(i <0 || j<0 || i>= A.size() || j >=A[0].length() || visited[i][j] == 1 ||A[i][j]=='O')
    return;
    visited[i][j]=1;
    
    dfs(A,visited,i+1,j);
    dfs(A,visited,i-1,j);
    dfs(A,visited,i,j+1);
    dfs(A,visited,i,j-1);

}
int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].length();
    vector<vector <int>> visited(n , vector <int> (m , 0));
    int shapes=0;
    for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
       if(A[i][j]=='X' && visited[i][j]==0)
          {
              dfs(A , visited , i,j);
              shapes++;
          }
          
          
    return shapes;
}
