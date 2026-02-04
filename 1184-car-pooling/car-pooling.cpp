class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //diff array q
        vector<int> temp(1001,0);

        for(auto& i : trips){
            int val = i[0];
            int start = i[1];
            int end = i[2] - 1;

            temp[start] += val;
            if(end < 1000)
                temp[end+1] -= val;
        }
        int max_cap = temp[0];
        for(int i = 1;i < 1001;++i){
            temp[i] += temp[i-1];
            max_cap = max(max_cap,temp[i]);
        }
        return max_cap <= capacity;
    }
};