class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pointer1 = 0, pointer2 = 0;
        nums1.resize(m);
        nums2.resize(n);
        while(pointer2 < n){
            if(m == 0 || nums1.back() <= nums2[pointer2]){
                //nums1 has been fully processed
                nums1.push_back(nums2[pointer2]);
                //have processed a node in nums2
                pointer2++;
            }else if(nums2[pointer2] <= nums1[pointer1]){
                nums1.insert(nums1.begin()+pointer1, nums2[pointer2]);
                //have processed a node in nums2
                pointer2++;
            }
            //every time we look at one node in nums1
            pointer1++;
        }
        nums1.resize(m+n);
    }
};
