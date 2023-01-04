//Optimize the array R
//time: O(N), space O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        int R = 1;
        vector<int> ans(N, 1);
        
        for(int i = 1; i < N; i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        
        for(int i = N-2; i >= 0; i--){
            R *= nums[i+1];
            ans[i] *= R;
        }
        
        return ans;
    }
};
