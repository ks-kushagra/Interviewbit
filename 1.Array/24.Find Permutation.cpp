

Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first
n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

    Length of given string s will always equal to n - 1
    Your solution should run in linear time and space.

Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]


_____________________________________________________________________________________________________________________________________________________________________________________________



vector<int> Solution::findPerm(const string A, int B) {
    stack<int> st;
    vector<int> ans;
    int t=1;
    int n=B-1;
    if(B==0){
        return ans;
    }
    
    for(int i=0;i<n;i++){
        if(A[i]=='I'){
            st.push(t++);
            while(!st.empty()){
             int k = st.top();
             ans.push_back(k);
             st.pop();
            }
            if(i==n-1){
                ans.push_back(t++);
            }
          
        }
        else if(A[i]=='D'){
            st.push(t++);
            if(i==n-1){
                st.push(t++);
            }
        }
    }
    if(!st.empty()){
        while(!st.empty()){
            int k = st.top();
            ans.push_back(k);
            st.pop();
        }
    }
    return ans;
}
