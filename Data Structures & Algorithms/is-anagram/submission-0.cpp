class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(27);

        int n = s.size(), m = t.size();

        for(int i=0;i<n;i++)
        {
            arr[s[i]-'a']++;
        }

        for(int i=0;i<m;i++)
        {
            arr[t[i]-'a']--;
        }


        for(int i=0;i<27;i++)
        {
            if(arr[i] != 0) return false;
        }

        return true;
        
    }
};
