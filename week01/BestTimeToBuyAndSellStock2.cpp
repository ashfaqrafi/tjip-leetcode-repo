/**
  Approach: Simple One Pass Algorithm

  /**
  Complexity Analysis

  Time complexity : O(n)O(n). Single pass.

  Space complexity: O(1)O(1). Constant space needed.
  **/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if(length == 0) return 0;
        int profit = 0;
        for(int i = 0; i < length - 1; i++){
            profit += max(0, prices[i+1] - prices[i]);
        }
        return profit;
    }
};
