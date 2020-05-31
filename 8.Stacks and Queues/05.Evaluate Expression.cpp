

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.



Input Format

The only argument given is character array A.

Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.

For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9
    
Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6

________________________________________________________________________________________________________________________________________________________________________


int Solution::evalRPN(vector<string> &A) {
    
    stack <int> s;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i] == "+"||A[i] == "-"||A[i] == "*"||A[i] == "/")
        {
            int a = (s.top());s.pop();
            int b = (s.top());s.pop();
            
             if(A[i] == "+")
              s.push(b + a);
              
             else if(A[i] == "-")
              s.push(b-a);
              
              else if(A[i] == "*")
               s.push(a*b);
               
               else
               s.push(b/a);
        }
        
        else
        s.push(stoi(A[i]));
    }
    
    
    return s.top();
}
