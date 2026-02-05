class Solution {
    static unordered_map<int,int> freq;

    static bool cmp(int a, int b) {
        if (freq[a] != freq[b])
            return freq[a] < freq[b];   
        return a > b;                  
    }

public:
    vector<int> frequencySort(vector<int>& nums) {
        freq.clear();

        for (int x : nums) {
            freq[x]++;
        }

        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};

unordered_map<int,int> Solution::freq;
