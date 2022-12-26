class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 0 1 0 3 12
        // 1 0 0 3 12
        // 1 3 0 0 12
        // 1 3 12 0 0
        for (int L = 0, R = 0; R < nums.size(); R++)
        {
            if (nums[R] != 0)
            {
                swap(nums[L], nums[R]);
                L++;
            }
        }
        return;
    }
};