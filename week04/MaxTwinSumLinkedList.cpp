class Solution {
public:
    int pairSum(ListNode* head) {
    vector <int> v;
		while(head) v.push_back(head->val), head = head->next;

		int ans = 0;
		for(int i = 0; i < v.size(); i++)
			ans = max(ans, v[i] + v[v.size() - 1 - i]);
		return ans;
    }
};
