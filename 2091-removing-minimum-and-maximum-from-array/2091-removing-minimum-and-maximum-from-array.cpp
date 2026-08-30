class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find minimum and maximum indices
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        // Put smaller index in a
        // and larger index in b
        int a = min(minIndex, maxIndex);
        int b = max(minIndex, maxIndex);

        // 3 possible ways
        int fromFront = b + 1;
        int fromBack = n - a;
        int bothSides = (a + 1) + (n - b);

        return min({fromFront, fromBack, bothSides});
    }
};