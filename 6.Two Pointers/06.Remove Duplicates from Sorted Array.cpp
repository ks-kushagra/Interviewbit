

Remove duplicates from Sorted Array
Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

Note that even though we want you to return the new length, make sure to change the original array as well in place

Do not allocate extra space for another array, you must do this in place with constant memory.

    Example:
    Given input array A = [1,1,2],
    Your function should return length = 2, and A is now [1,2]. 


__________________________________________________________________________________________________________________________________________________________________________

int Solution::removeDuplicates(vector<int> &A) {

    set<int> s;
    
    for(int i=0;i<A.size();i++)
    s.insert(A[i]);
    
    A= vector <int>();
    
    for(auto it = s.begin() ; it != s.end();it++)
     A.push_back(*it);
     
     
     return A.size();
}

__________________________________________________________________________________________________________________________________________________________________



		int removeDuplicates(vector<int> &A) {
			int count = 0, n = A.size();
			for (int i = 0; i < n; i++) { 
				if (i < n - 1 && A[i] == A[i+1])
            continue;
            
				else {
					A[count] = A[i];
					count++;
				}
			}
			return count;
		}  
__________________________________________________________________________________________________________________________________________________________________


