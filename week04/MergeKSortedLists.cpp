// Approach: Priority Queue
// TC: O(NlogK)
// MC: O(K) for the priority queue

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode* a, const ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        
        for(ListNode* node : lists){
            if(node != nullptr) pq.push(node);
        }
        
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        
        while(!pq.empty()){
            ListNode* node = pq.top(); pq.pop();
            cur->next = node;
            node = node->next;
            cur = cur->next;
            cur->next = nullptr;
            if(node != nullptr){
                pq.push(node);
            }
        }
        
        return head->next;
    }
};
