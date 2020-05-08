
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

________________________________________________________________________________________________________________________________________________________________________________________________________



void sep(vector<int> &A)
{
    int i=0,j=0;
    for(i=0;i<A.size();i++)
    {
        if(A[i]<=0)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            j++;
        }
    }
    A.erase (A.begin(),A.begin()+j);
}
int Solution::firstMissingPositive(vector<int> &A) {
    sep(A);
    int i;
    for(i=0;i<A.size();i++)
    {
        if(abs(A[i])-1<A.size() && A[abs(A[i])-1]>0)
            A[abs(A[i])-1]=-A[abs(A[i])-1];
    }
    for(i=0;i<A.size();i++)
    {
        if(A[i]>0)
            return i+1;
    }
    return A.size()+1;
}
