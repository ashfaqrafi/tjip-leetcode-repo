/**
  Approach: One-pass Hash Table
  **/

/**
Complexity Analysis:
Time complexity : O(n).
We traverse the list containing nn elements only once.
Each look up in the table costs only O(1) time.
Space complexity : O(n).
The extra space required depends on the number of items stored in the hash table, which stores at most nn elements.
**/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> tws;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(tws.find(complement) != tws.end()){
                return vector<int> {tws[complement], i};
            }
            tws[nums[i]] = i;
        }
        return vector<int> {};
    }
};
