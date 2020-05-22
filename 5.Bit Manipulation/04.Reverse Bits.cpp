

Reverse the bits of an 32 bit unsigned integer A.

Input Format:

    First and only argument of input contains an integer A

Output Format:

    return a single unsigned integer denoting minimum xor value

Constraints:

0 <= A < 2^32

For Examples :

Example Input 1:
    A = 0
Example Output 1:
    0
Explanation 1:
        00000000000000000000000000000000  
=>      00000000000000000000000000000000
Example Input 2:
    A = 3
Example Output 2:
    3221225472
Explanation 2:
          00000000000000000000000000000011 
=>        11000000000000000000000000000000

Since java does not have unsigned int, use long

___________________________________________________________________________________________________________________________________________________________________
#include<bitset>
unsigned int Solution::reverse(unsigned int A) {

    string binary = bitset<32> (A).to_string();
    string s="";
    for(int i=0;i<binary.length();i++)
     s= binary[i] + s;
     
    unsigned long ans  = bitset<32>(s).to_ulong();
    
    return (unsigned int)ans;
}
