class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        vector<int>curr = intervals[0];
        
        int n= intervals.size();
        for(int i=0; i<n; i++){
            if(intervals[i][0]<=curr[1]){
                // overlap ?
                // merge 
                curr[1]= max(intervals[i][1], curr[1]);
            }
            else{
                // no overlap
                //store current
                ans.push_back(curr);
                // move to next interval
                curr = intervals[i];
            }
        }
        // push last interval
        ans.push_back(curr);
        return ans;
    }
};