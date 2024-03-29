

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
    vector<int> ans;
    stack<int> s;int count =1;s.push(count++);

    for(int i=0;i<A.length();i++){
        if(A[i]=='I'){
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
        }
            s.push(count++);
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}


_____________________________________________________________________________________________________________________________________________________________________________________________

vector<int> Solution::findPerm(const string A, int B) {
    
    stack <int> s;
    vector <int> v;
    int t=1;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='D')
            s.push(t++);
            
        else if(A[i]=='I')
        {
            s.push(t++);
            while(!s.empty())
            {
                v.push_back(s.top());
                s.pop();
            }
        }
    }
    
    s.push(t++);
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    
    return v;
}

____________________________________________________________________________________________________________________________________________________________________________________________________________
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
