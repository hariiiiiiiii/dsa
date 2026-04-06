class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int end = 0;
        int sum = 0;
        int count = 0;

        mp[0] = 1;
        for(end; end < nums.size(); end++){
            sum += nums[end];

            if(mp.find(sum - k) != mp.end()){
                count += mp[sum - k];
            }
            mp[sum]++;
        }
        return count;
    }
};