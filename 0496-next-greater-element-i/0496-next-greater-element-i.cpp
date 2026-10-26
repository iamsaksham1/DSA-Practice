
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();

        vector<int> nge(n, -1);
        stack<int> st;
        unordered_map<int, int> mp;

        // Traverse nums2 from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove smaller or equal elements
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // Find the next greater element
            if (!st.empty()) {
                nge[i] = st.top();
            }

            // Push current element
            st.push(nums2[i]);
        }

        // Map each element to its next greater element
        for (int i = 0; i < n; i++) {
            mp[nums2[i]] = nge[i];
        }

        // Build the answer for nums1
        vector<int> ans;

        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};
