class Solution {
public:
    string largestOddNumber(string num) {
        int odd = -1;
        for (int i = 0; i < num.size(); i++) {
            if ((num[i] - '0') % 2 == 1) {
                odd = i;
            }
        }
        if (odd == -1) {
            return "";
        }
        return num.substr(0, odd + 1);
    }
};