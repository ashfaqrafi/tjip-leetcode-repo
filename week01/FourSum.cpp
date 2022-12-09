// Just wrap 3Sum problem with one more outer loop.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<vector<int>> frs;
        
        sort(nums.begin(), nums.end());
        
        for(int first = 0; first < length-3; first++){
            if(first > 0 && nums[first] == nums[first-1]) continue;
            for(int second = first+1; second < length-2; second++){
                if(second > first+1 && nums[second] == nums[second-1]) continue;
                int left = second+1, right = length-1;
                long long currentTarget = target - (long long)nums[first] - (long long)nums[second];
                // cout << first << " " << second << " " << left << " " << right << endl;
                while(left < right){
                    if(nums[left] + nums[right] == currentTarget){
                        frs.push_back({nums[first], nums[second], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }else if(nums[left] + nums[right] < currentTarget){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        
        return frs;
    }
};
