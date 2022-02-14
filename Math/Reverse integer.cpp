


Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

___________________________________________________________________________________________________________________________________________________________________________________

int Solution::reverse(int A) {
    int sign = 1;
    if(A<0){
        A=A*(-1);
        sign =-1; // negative
    }

    string s = std::to_string(A);
    std::reverse(s.begin(),s.end());
    long temp = std::stol(s);

    if(temp > INT_MAX){
        return 0;
    }

    return (sign)*(int)(temp);

}

