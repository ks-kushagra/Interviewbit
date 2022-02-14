

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.





------------------------------------------------------------------------------------------------------------------------------------------------------------------------


bool compareNum(string a, string b) {
            return a + b > b + a;
    }
    
    
string Solution::largestNumber(const vector<int> &A) {

            string result;
            vector<string> str;
            for (int i = 0; i < A.size(); i++) {
                str.push_back(to_string(A[i]));
            }
            
            sort(str.begin(), str.end(), compareNum);
            for (int i = 0; i < str.size(); i++) {
                result += str[i];
            }

            int pos = 0;
            while (result[pos] == '0' && pos + 1 < result.size()) pos++; 
            return result.substr(pos);
}
