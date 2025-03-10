// TC: O(N^2)
// MC: O(N)

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    vector<vector<int>> ans;

    sort(begin(people), end(people), [](const auto& a, const auto& b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });

    for (const vector<int>& p : people)
      ans.insert(begin(ans) + p[1], p);

    return ans;
  }
};
