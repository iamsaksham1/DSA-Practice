class Solution {
public:
    int maxArea(vector<int>& height) { //O(n)
        int maxw =0;
        int l =0;
        int r =height.size()-1;
        while(l<=r){
            int w = r-l;
            int h = min(height[r],height[l]);
            int currWater = w * h;
            maxw = max(currWater, maxw);
            height[l] > height[r] ? r-- : l++;        }
        
        return maxw;
    }
};