

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

 
 ____________________________________________________________________________________________________________________________________________


int myCompare(string X, string Y)
{
    // first append Y at the end of X
    string XY = X.append(Y);
 
    // then append X at the end of Y
    string YX = Y.append(X);
 
    // Now see which of the two formed numbers is greater
    return XY.compare(YX) > 0 ? 1: 0;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string> b;
    for(int i=0;i<A.size();i++){
        b.push_back(to_string(A[i]));
    }
    sort(b.begin(),b.end(),myCompare);
    string ans="";
    for(int i=0;i<b.size();i++){
     ans+=b[i];
    }
    int i=0;
    while(ans[i]=='0'){
        i++;
    }
    if(i==ans.length())
     ans="0";
    return ans;
}

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


bool cmp(string a, string b)
{
    return (a+b >  b+a);
}

string Solution::largestNumber(const vector<int> &A) {
    
    vector <string> v;
    int n = A.size();
    
    int flag=0;
    
    
    for(int i=0;i<n;i++)
      {
          v.push_back(to_string(A[i]));
          if(A[i] >0)
          flag =1;
      }
      
      
      if(!flag)
       return "0";
       
       
        
    sort(v.begin() , v.end(),cmp);
    
    string s ="";
    
    for(int i =0;i<n;i++)
          s = s+v[i];
     
     
     
     
     return s;
}
