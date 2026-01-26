class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> target;
        for (char c : t) target[c]++;

        unordered_map<char, int> window;
        int required = target.size();
        int formed = 0;

        int left = 0, right = 0;
        int minLen = INT_MAX, start = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;

            if (target.count(c) && window[c] == target[c])
                formed++;

            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char l = s[left];
                window[l]--;

                if (target.count(l) && window[l] < target[l])
                    formed--;

                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
        
    }
};