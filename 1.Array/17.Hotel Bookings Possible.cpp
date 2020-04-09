

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. Bookings contain an arrival 
date and a departure date.
He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem 
in time O(N log N) .

Input:


First list for arrival time of booking.
Second list for departure time of booking.
Third is K which denotes count of rooms.

Output:

A boolean which tells whether its possible to make a booking. 
Return 0/1 for C programs.
O -> No there are not enough rooms for N booking.
1 -> Yes there are enough rooms for N booking.

Example :

Input : 
        Arrivals :   [1 3 5]
        Departures : [2 6 8]
        K : 1

Return : False / 0 

At day = 5, there are 2 guests in the hotel. But I have only one room. 

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {

    int n=arrive.size();
    int loc=0,i,j,count=0;
    pair<int ,int> pr[2*n];
    for(i=0;i<n;i++)
    {
        pr[loc].first=arrive[i];
        pr[loc++].second=1;
    }
     for(j=0;j<n;j++)
    {
        pr[loc].first=depart[j];
        pr[loc++].second=0;
    }
    
    sort(pr,pr+(n+n));
    
    for(i=0;i<loc;i++)
    {
             
        if(pr[i].second==1)
            count++;
        else if(pr[i].second==0)    
            count--;
            
            if(count>K)
                 return false;
       
            
    }
    
    return true;    
    
}

