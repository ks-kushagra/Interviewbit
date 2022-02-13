You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

-----------------------------------------------------------------------------------------------------------------------------------------------

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int arrSum=0,arrSqSum=0;
    for(int i=0;i<A.size();i++){
        arrSum += A[i] - (i+1);
        arrSqSum += (long long int)A[i] * (long long int)A[i] - (long long int)(i+1)*(long long int)(i+1);
    }
    //(a+b) = arrSqSum / arrSum = t 
    //a-b = arrSum
    //2a = t + arrSum 
    //2b = arrSum-t
    
    arrSqSum = arrSqSum/arrSum;
    
    int a = (arrSqSum + arrSum)/2;
    int b = (arrSqSum - arrSum)/2;
    
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}
