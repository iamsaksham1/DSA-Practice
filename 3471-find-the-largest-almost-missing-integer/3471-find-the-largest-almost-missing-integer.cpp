class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case 1: k == 1
        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums) {
                freq[x]++;
            }

            int ans = -1;

            for (auto& [x, count] : freq) {
                if (count == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Case 2: k == n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n
        int ans = -1;

        // Check first element
        if (count(nums.begin(), nums.end(), nums[0]) == 1) {
            ans = max(ans, nums[0]);
        }

        // Check last element
        if (count(nums.begin(), nums.end(), nums[n - 1]) == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};