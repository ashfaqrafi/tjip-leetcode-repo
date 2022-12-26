class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast = 0, slow = 0;
        int length = nums.size();

        for(; fast < length; fast++){
            if(nums[fast]){
                nums[slow++] = nums[fast];
            }
        }
        
        for(; slow < length; slow++){
            nums[slow] = 0;
        }
    }
};
