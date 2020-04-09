

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


 bool compare(string a , string b){
        return (a+b>b+a);
    }
    
    
int all_zero(const vector<int> &A){
        for(int i=0;i<A.size();i++){
            if(A[i]!=0){
                return 0;
            }
        }
        return 1;
    }
string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    if(all_zero(A)){
        return "0";
    }
    
    
    vector<string> digit;
    
    
    for(int i =0;i<n;i++){
        digit.push_back(to_string(A[i]));
    }
    sort(digit.begin(),digit.end(),compare);
    string s="";
    for(int i=0;i<n;i++){
        s=s+digit[i];
    }
    return s;
}
