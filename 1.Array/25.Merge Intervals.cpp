

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
_________________________________________________________________________________________________________________________________________________________________________
 /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(const Interval &a, const Interval &b){
    if(a.start == b.start){
        return a.end<b.end;
    }
    
    return a.start < b.start;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    intervals.push_back(newInterval);
    sort(intervals.begin() , intervals.end() , compare);
    int i=0;
    int n = intervals.size();
    vector<Interval> ans;
    while(i<n-1){
        if(intervals[i].end < intervals[i+1].start){
            ans.push_back(intervals[i]);
            i++;
        }else{
            //intervals[i].end >= intervals[i+1].start
            int j = i+1;
            while(j < n && intervals[i].end >= intervals[j].start){
                intervals[i].start = min(intervals[i].start , intervals[j].start);
                intervals[i].end = max(intervals[i].end , intervals[j].end);
                j++;
            }
            ans.push_back(intervals[i]);
            i=j;
        }
    }
    
    if(i == n-1){
        ans.push_back(intervals[i]);
    }
    return ans;
}   
