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
    static bool cmp (Interval& i1,Interval& i2){
        return i1.start<i2.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int last=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<last){
                return false;
            }
            last=intervals[i].end;
        }
        return true;
    }
};
