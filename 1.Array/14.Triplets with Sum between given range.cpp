

Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


int Solution::solve(vector<string> &A) {
 
 //vector<float> val;
 vector<float> v;
 for(int i=0;i<A.size();i++){
   std::string str = A[i]; 
   float a = std::stof(str);
    v.push_back(a);
 }
    float a= v[0];
    float b = v[1];
    float c = v[2];
    for(int i=3;i<v.size();i++){
        float d = a+b+c;
        if(d>1&&d<2){
            return 1;
        }
        else if(d>2){
            if(a>b&&a>c){
                a=v[i];
            }
            else if(b>a&&b>c){
                b = v[i];
            }
            else if(c>a&&c>b){
                c = v[i];
            }
        }
        else if(d<1){
            if(a<b&&a<c){
                a=v[i];
            }
            else if(b<a&&b<c){
                b=v[i];
            }
            else if(c<a&&c<b){
                c = v[i];
            }
        }
    }
    float d = a+b+c;
    if(d>1&&d<2){
            return 1;
    }
    return 0;
}
