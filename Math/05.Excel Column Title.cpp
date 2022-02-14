

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

____________________________________________________________________________________________________________________________________________________________________________

string Solution::convertToTitle(int A) {
    
    string ans ="";
    
    while(A > 0)
    {
        ans = (char)((A-1)%26+'A') + ans; 
        A--;
        A=A/26;
    }
    
    return ans;
}



_________________________________________________________________________________________________________________________________________________________________________________________
string Solution::convertToTitle(int A) {

    vector <int> v;
    
    while(A>26)
      {
          v.push_back(A%26);
          if(A%26==0)
            {A=A/26-1;
              continue;
            }
          A=A/26;
      }
      if(A!=0)
      v.push_back(A);
      string s="";
      for(int i=0;i<v.size();i++)
        {

            char t;
            if(v[i]==0)
             t='Z';
             else
              t = 64+v[i];
              s=t+s;
        }
        return s;
}

