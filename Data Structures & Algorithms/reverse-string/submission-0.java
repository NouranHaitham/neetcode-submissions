class Solution {
    public void reverseString(char[] s) {
        
        int n = s.length;
        int len = n/2;
        System.out.println(n);
        // 1 2 3 4 
        for(int i=0;i<len;i++)
        {
            char temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
             System.out.println(s[i] + " "+s[n-1-i]);
        }
    }
}