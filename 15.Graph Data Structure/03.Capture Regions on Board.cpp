

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Input Format:

    First and only argument is a N x M character matrix A

Output Format:

    make changes to the the input only as matrix is passed by reference.

Constraints:

    1 <= N,M <= 1000

For Example:

Input 1:
    A = [ [X, X, X, X],
          [X, O, O, X],
          [X, X, O, X],
          [X, O, X, X] ]
Output 1:
    After running your function, the board should be:
    A = [ [X, X, X, X],
          [X, X, X, X],
          [X, X, X, X],
          [X, O, X, X] ]
Explanation:
    O in (4,2) is not surrounded by X from below.


________________________________________________________________________________________________________________________________________________________________________________________________________________________


bool memo[1002][1002];
vector<vector<char> >v;
int n,c;
void dfs(int i,int j){
    if(memo[i][j])return;
    if(i>=n||i<0||j<0||j>=c)return;
    if(v[i][j]=='X')return;
    memo[i][j]=true;
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}
void Solution::solve(vector<vector<char> > &A) {
    memset(memo,0,sizeof(memo));
    n=A.size();
    c=A[0].size();
    v=A;
    for(int i=0;i<c;i++){
        if(A[0][i]!='X')dfs(0,i);
        if(A[n-1][i]!='X')dfs(n-1,i);
    }
    for(int i=0;i<n;i++){
        if(A[i][0]!='X')dfs(i,0);
        if(A[i][c-1]!='X')dfs(i,c-1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<c;j++){
            if(!memo[i][j])A[i][j]='X';
        }
    }
}
_______________________________________________________________________________________________________________________________________________________________________________________________


-------------------------------------------------Partially Accepted-----------------------------------------------------------------------


int isSafe(vector <vector <char> > A , int i , int j,vector <vector <int> > visited)
{
    int n = A.size();
    int m = A[0].size();
    
    if(i <0 || j<0 || i>=n || j>=m || A[i][j] == 'X'|| visited[i][j]==1)
    return 0;
    
    
    return 1;
}
void dfs(vector <vector <char> > &A , int i ,int j,vector <vector <int> > &visited)
{
    

    A[i][j]='O';
    visited[i][j]=1;

    if(isSafe(A,i+1,j,visited))
     dfs(A,i+1,j,visited);
    
    if(isSafe(A,i-1,j,visited))
     dfs(A,i-1,j,visited);
    
   if(isSafe(A,i,j+1,visited))
    dfs(A,i,j+1,visited);
    
   if(isSafe(A,i,j-1,visited))
     dfs(A,i,j-1,visited);
    
}
void Solution::solve(vector<vector<char> > &A) {
      memset(memo,0,sizeof(memo));
  int n = A.size(),m=A[0].size();
  vector <vector <int> > visited(n , vector <int> (m , -1));
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        if(A[i][j] == 'O')
           A[i][j]='-';
           
    
    
  for(int i=0;i<A[0].size();i++) // first row
     if(A[0][i] == '-')
         dfs(A,0,i,visited);
         
  
   for(int i=0;i<n;i++) // last column
        if(A[i][m-1] == '-')
          dfs(A , i , m-1,visited);
          
    for(int i=0;i<m;i++) // last row
      if(A[n-1][i] == '-')
        dfs(A , n-1 , i,visited);
        
    
    for(int i=0;i<n;i++) // first column
       if(A[i][0] == '-')
        dfs(A , i , 0,visited);
        
        
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
          if(A[i][j]=='-')
            A[i][j]='X';
    
}
