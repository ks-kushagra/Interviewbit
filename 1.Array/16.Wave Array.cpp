

Given an array of integers, sort the array into a wave like array and return it,
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]

    NOTE : If there are multiple answers possible, return the one thats lexicographically smallest.
    So, in example case, you will return [2, 1, 4, 3] 

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

vector<int> Solution::wave(vector<int> &A) {
    int n = A.size();
    
    if(n<=1){
        return A;
    }
    sort(A.begin(),A.end());
    int index=0;
    while(index < n-1){
        swap(A[index], A[index+1]);
        index = index+2;
    }
    return A;
}
__________________________________________________________________________________________________________________________________________________________________________________________
vector<int> Solution::wave(vector<int> &A) {
    vector<int> a;
    vector<int> b;
    int i=0;
    sort(A.begin(),A.end());
    while(i<A.size()){
        a.push_back(A[i]);
        if((i+1)<A.size())
        b.push_back(A[i+1]);
        i=i+2;
    }
    vector<int> c;
    //int n = (a.size()<b.size()?a.size():b.size());
    i=0;
    while(i<b.size()){
        c.push_back(b[i]);
        c.push_back(a[i++]);
    }
    if(i<a.size())
       c.push_back(a[i]);

    return c;
}
