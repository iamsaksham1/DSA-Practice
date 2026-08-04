class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int miniElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());

        vector<bool> exists(maxElement - miniElement +1);
        for(int& i : nums) exists[i - miniElement] = true;

        vector<int>ans;
        for(int i=0; i< maxElement - miniElement; i++){
            if(!exists[i]){
                ans.push_back(i + miniElement);
            }
        }
        return ans;
    }
};