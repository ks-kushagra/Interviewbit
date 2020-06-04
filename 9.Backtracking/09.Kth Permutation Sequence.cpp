

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3 ) :

1. "123"
2. "132"
3. "213"
4. "231"
5. "312"
6. "321"

Given n and k, return the kth permutation sequence.

For example, given n = 3, k = 4, ans = "231"

    Good questions to ask the interviewer :

        What if n is greater than 10. How should multiple digit numbers be represented in string?

            In this case, just concatenate the number to the answer.
            so if n = 11, k = 1, ans = "1234567891011" 

        Whats the maximum value of n and k?

            In this case, k will be a positive integer thats less than INT_MAX.
            n is reasonable enough to make sure the answer does not bloat up a lot. 


______________________________________________________________________________________________________________________________________________________________________________________________________________


string solve(vector<int> v , int k)
{
    do
    {
        if(--k ==0)
        break;
    }while(next_permutation(v.begin() , v.end()));
    
    string s = "";
    
    for(int i=0;i<v.size();i++)
       s=s+to_string(v[i]);
       
       return s;
}

string Solution::getPermutation(int A, int B) {
    vector <int> v;
    for(int i=1;i<=A;i++)
    v.push_back(i);
    
    return solve(v,B);
}

_______________________________________________________________________________________________________________________________________________________________________________



int fact(int n)
{
    if(n>12)
        return INT_MAX;
    if(n==0)
        return 1;
    return n*fact(n-1);
}
string answer(int B, vector<int> &v)
{
    int A=v.size();
    if(A==0)
        return "";
    int f=fact(A-1);
    int pos=B/f;
    B%=f;
    string c=to_string(v[pos]);
    v.erase(v.begin()+pos);
    return c+answer(B,v);
}
string Solution::getPermutation(int A, int B) 
{
    vector<int> v;
    for(int i=1;i<=A;i++)
        v.push_back(i);
    return answer(B-1,v);
}

