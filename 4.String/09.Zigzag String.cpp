

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a
fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R

And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D

and hence the answer would be ACBD.

_________________________________________________________________________________________________________________________________________________________________________________________

string Solution::convert(string A, int B) {
    
    vector <vector <char> > v(B);
    int n = A.length();
    
    int dir=0;
    int i=0;
   int flag1 =0,flag2 =0;
    if(n <= 3 || B == 1)
     return A;
     
    while(i < n )
    {
        if(dir == 0)
        {
            for(int j=0;j<B-1 && i < n;j++)
                {
                   flag1 =1;
                   v[j].push_back(A[i++]);
               }
               
            dir =1;
        }
        
        else if( dir == 1)
        {
            for(int j=B-1;j>0 && i < n;j--)
            {
                flag2 =1;
                v[j].push_back(A[i++]);
            }
            
            dir =0;
        }
        
        if(flag1 ==0  && flag2 == 0)
          break;
    }
    
    
    
    
    string ans="";
    
    for(i=0;i<B;i++)
    {
        for(int j=0;j<v[i].size();j++)
          ans = ans + v[i][j];
    }
    
    
    return ans;
    
    
}
