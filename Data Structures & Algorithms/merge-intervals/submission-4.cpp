class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


        map<int,int> event;
        for(auto inter : intervals)
        {   
            event[inter[0]]++;
            event[inter[1]]--;
        }

        vector<vector<int>> result;
        int st = -1;
        int active = 0;
        // [[0,0],[1,4],[6,7]]
        // 1(+2) 3(-) 5(-) 6(+) 7(-)
        for(auto [time, count]: event)
        {
            // brackets [[[[]]]]
            if(st == -1) st = time;
            // if(active + count > 0) // 0  to  +  
            // {
            //     st = time;
            // }
            if(active + count == 0) // + to 0
            {
                result.push_back({st,time});
                st = -1;
            }
            active += count;
        }

        return result;
    }
};
