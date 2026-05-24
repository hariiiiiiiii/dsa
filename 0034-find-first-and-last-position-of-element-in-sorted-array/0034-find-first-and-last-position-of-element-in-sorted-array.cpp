class Solution {
public:

    int binarySearch(vector<int>& nums, int target, bool isSearchingLeft) {
        int low = 0;
        int high = nums.size() - 1;
        int idx = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                idx = mid;

                if (isSearchingLeft) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);

        result[0] = binarySearch(nums, target, true);
        result[1] = binarySearch(nums, target, false);

        return result;
    }
};