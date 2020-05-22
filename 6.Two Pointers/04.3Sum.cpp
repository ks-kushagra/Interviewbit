

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

___________________________________________________________________________________________________________________________________________________________________________


int Solution::threeSumClosest(vector<int> &A, int B) {

    if(A.size() < 3){
        return 0;
    }
    
    sort(A.begin(), A.end());
    
    int i = 0;
    int sum, minDiff = INT_MAX;
    
    while(i < A.size()-2){
        int left = i+1;
        int right = A.size()-1;
        while(right > left){
            int temp = A[i]+A[left]+A[right];
            int diff = abs(temp-B);
            if(diff == 0){
                return B;
            }
            if(diff < minDiff){
                minDiff = diff;
                sum = temp;
            }
            if(temp < B){
                left++;
            }
            else{
                right--;
            }
        }
        i++;
    }
    
    return sum;
}
