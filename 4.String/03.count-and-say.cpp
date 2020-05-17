
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...

1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.


_______________________________________________________________________________________________________________________________________


string Solution::countAndSay(int A) {
    if(A==1)
        return "1";
    if(A==2)
        return "11";
    string str="11";
    for(int i=3;i<=A;i++){
        str+='$';  // z value algo
        int len=str.length();
        int c=1;
        string tmp="";
        for(int j=1;j<len;j++){
            if(str[j]!=str[j-1]){
                tmp+=c+'0';
                tmp+=str[j-1];
                c=1;
            }
            else
                c++;
        }
        str=tmp;
    }
    return str;
}
