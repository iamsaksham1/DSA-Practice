/*
1929. Concatenation of Array

Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
Specifically, ans is the concatenation of two nums arrays.
Return the array ans.

LeetCode 1929 - Concatenation of Array

Approach 1: Create Array of Size 2N
Time Complexity: O(n)
Space Complexity: O(n)

int n = nums.size();
vector<int> ans(2 * n);

for(int i = 0; i < n; i++){
    ans[i] = nums[i];
    ans[i + n] = nums[i];
}

return ans;
*/


/*
Approach 2: Using push_back()
Time Complexity: O(n)
Space Complexity: O(n)

vector<int> ans;

for(int i = 0; i < nums.size(); i++){
    ans.push_back(nums[i]);
}

for(int i = 0; i < nums.size(); i++){
    ans.push_back(nums[i]);
}

return ans;
*/


/*
Approach 3: Copy + push_back()
Time Complexity: O(n)
Space Complexity: O(n)

vector<int> ans = nums;

for(int i = 0; i < nums.size(); i++){
    ans.push_back(nums[i]);
}

return ans;
*/


/*
Approach 4: Using insert()
Time Complexity: O(n)
Space Complexity: O(n)

vector<int> ans = nums;

ans.insert(ans.end(), nums.begin(), nums.end());

return ans;
*/


/*
Approach 5: Modulo Trick
Time Complexity: O(n)
Space Complexity: O(n)

int n = nums.size();

vector<int> ans(2 * n);

for(int i = 0; i < 2 * n; i++){
    ans[i] = nums[i % n];
}

return ans;
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans(2 * nums.size());
        for(int i=0; i<nums.size(); i++){
            ans[i]=nums[i];
            ans[i+nums.size()]=nums[i];
        }
        return ans;
    }
};
