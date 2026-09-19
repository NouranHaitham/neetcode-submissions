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

private:

static bool comparater(const Interval& a,const Interval& b)
{
    return (a.start == b.start)? a.end < b.end: a.start < b.start;
}


public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), comparater);

        int n = intervals.size();
        for(int i=0;i<n-1;i++)
        {
            auto [s1, e1] = intervals[i];
            auto [s2, e2] = intervals[i+1];

            if(s2 >= e1) continue;
            return false;
        }

        return true;
    }
};
