class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = " ";
        int res_len = 0;

        for(int i = 0;i < n;i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > res_len){
                    res = s.substr(l,r-l+1);
                    res_len = r - l + 1;
                }
                l--;
                r++;
            }

            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > res_len){
                    res = s.substr(l,r - l + 1);
                    res_len = r - l + 1;
                }
                l--;
                r++;
            }
            
            
        }
        return res;
    }
};