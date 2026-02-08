class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0;i < s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](const pair<char,int> &a, const pair<char,int> & b){
            return a.second > b.second;
        });
        string result;
        for(auto const& pair: v){
            result.append(pair.second,pair.first);
        }
        return result;
    }
};