// Approach: Single Pass
// TC: O(N), MC: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        
        int i = length-2;
        
        while(i >= 0 && nums[i] >= nums[i+1]){
            --i;
        }
        
        if(i >= 0){
            //nums[i] < nums[i+1]
            int j = length-1;
            
            /*
            find a j > i s.t. nums[j] > nums[i] and 
            is the smallest in nums[i+1:],
            to do this, we find from the end,
            because nums[i+1:] is in descending order
            */
            while(j >= 0 && nums[j] <= nums[i]){
                --j;
            }
            
            swap(nums[i], nums[j]);
            
            //after swapping, nums[i+1:] is still in descending order
        }
        
        reverse(nums.begin()+i+1, nums.end());
    }
};
