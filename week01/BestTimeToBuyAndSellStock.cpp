// Greedy Approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int maxToTail = 0;
        int profit, maxProfit = 0;
        
        for(int i = length-1; i >= 0; i--){
            maxToTail = max(maxToTail, prices[i]);
            profit = max(maxToTail - prices[i], 0);
            maxProfit = max(maxProfit, profit);
        }    
        return maxProfit; 
    }
};
