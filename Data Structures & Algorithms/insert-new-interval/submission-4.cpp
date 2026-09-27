class Solution {

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int n = intervals.size();
        vector<vector<int>> result;
        result.reserve(n+2);

        bool isDone = 0;

        for(int i=0;i<n;i++)
        {
            int s1 = intervals[i][0], e1 = intervals[i][1]; // 1 5
            int s2 = newInterval[0], e2 = newInterval[1]; // 6 8

            // case 1: s1  e1   or s1 e1     or   s1       e1
            //(Merge)    s2  e2       s2 e2          s2  e2
            if((s2 >= s1 && s2 <= e1) || (s2 < s1 && e2 >= s1))
            {
                int st = min(s1,s2), ed = max(e1,e2); // 1 5
                for(;i<n;i++)
                {
                   if(intervals[i][0] <= ed && intervals[i][0]>=st) 
                        ed = max(intervals[i][1],ed);
                    else
                        break;     
                }
                result.push_back({st,ed});
                for(;i<n;i++) result.push_back(intervals[i]);
                isDone = 1;
                break; 
            }
            // case 1:     s1   e1       or        s1 e1     
            //(Merge)    s2  (e2) (e2)        s2 e2         
            else if(s2 < s1 && e2 < s1)
            {
                result.push_back(newInterval);
                for(int j=i;j<n;j++) result.push_back(intervals[j]);
                isDone = 1;
                break;
            }
            // s1 e1 s2 e2
            else result.push_back(intervals[i]);
        }

        if(n == 0 || !isDone) result.push_back(newInterval);
        return result;
   
    }
};

///


