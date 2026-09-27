class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());

        int n = intervals.size();
        vector<vector<int>> result;
        result.reserve(n+2);

        if(n == 0) return result;
        int s = intervals[0][0], e = intervals[0][1];

        for(int i=1;i<n;i++)
        {
            while(i<n)
            {
                int s2 = intervals[i][0], e2 = intervals[i][1];
                if(s2 >= s && s2 <= e) // merge interval
                {
                    s = min(s2,s);
                    e = max(e2,e);
                    i++;
                }
                else break;  
            }

            result.push_back({s,e});
            if(i < n) s = intervals[i][0], e = intervals[i][1];
        }

        if(result.size() == 0 || result.back()[0] != s) result.push_back({s,e});
        return result;

    }
};
