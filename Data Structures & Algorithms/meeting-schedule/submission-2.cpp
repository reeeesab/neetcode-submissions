/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

    sort(intervals.begin(), intervals.end(),
    [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });

    Interval temp = intervals[0];
     for(int i=1; i<intervals.size(); i++){
        Interval  curr = intervals[i];
        if(curr.start<temp.end){
            return false;
        }else{
            temp = curr;
        }
     }   
     return true;
    }
};
