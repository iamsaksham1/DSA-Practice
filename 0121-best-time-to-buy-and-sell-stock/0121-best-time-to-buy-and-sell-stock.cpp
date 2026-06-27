class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = prices[0];
        int MAX = 0;
        int profit = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<smallest){
                smallest = prices[i];
            }
            else{
                profit = prices[i]-smallest;
            }
            if(profit>MAX){
                MAX = profit;
            }
        }
        return MAX;
    }
     
}; 