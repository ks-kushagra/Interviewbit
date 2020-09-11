There is a corridor in a Jail which is N units long. Given an array A of size N. The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.

All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].

Initially all lights are off.

Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.



Problem Constraints
1 <= N <= 1000

1 <= B <= 1000



Input Format
First argument is an integer array A where A[i] is either 0 or 1.

Second argument is an integer B.



Output Format
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.


Example Input
Input 1:

A = [ 0, 0, 1, 1, 1, 0, 0, 1].
B = 3
Input 2:

A = [ 0, 0, 0, 1, 0].
B = 3


Example Output
Output 1:

2
Output 2:

-1
___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________-

//The idea is :
/*
for any value i
the range will be [i - B + 1  , i + B - 1]
if any one value is '1' ( from right side)  then count++ and move ptr to i+B-1;
*/
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j = (i+B-1);j>=0 && j>(i-B+1);j--)
        {
            if(A[j] == 1)
            {
              ans++;
              flag=1;
              i= j+B-1;
              break;
            }
        }
        
        if(flag==0)
         return -1;
    }
    
    return ans;
}

//The idea is :
/*
for any value i
the range will be [i - B + 1  , i + B - 1]
if any one value is '1' ( from right side)  then count++ and move ptr to i+B-1;
*/
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j = (i+B-1);j>=0 && j>(i-B+1);j--)
        {
            if(A[j] == 1)
            {
              ans++;
              flag=1;
              i= j+B-1;
              break;
            }
        }
        
        if(flag==0)
         return -1;
    }
    
    return ans;
}
