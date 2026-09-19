class Solution {
public:
    bool isAlphanumric(const char& c)
    {
        if(c >= 'a' && c <='z') return true;

        if(c >= 'A' && c <='Z') return true;

        if(c >= '0' && c <='9') return true;

        return false;
    }

    string prepareString(const string& s)
    {
        string ans;

        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(isAlphanumric(s[i]))
            {
                ans += s[i];
            }
        }
        return ans;
    }

    bool isPalindrome(string s) {

        s = prepareString(s);

        cout<<s<<"\n";
        
        int n = s.size();

        int l = 0, r = n-1;
        while(l <= r)
        {
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;    
        }

        return true;

    }
};
