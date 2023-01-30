// TC: O(H+k), 
// MC: O(H+k), where H is the height of the tree, it could be N or logN
// Approach: Iteration

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        
        do{
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top(); stk.pop();

            if(--k == 0) return cur->val;
            // cout << cur->val << " ";
            cur = cur->right;
            
        //when stk not empty or cur not null, we should continue the loop
        }while(!stk.empty() || cur);
        // cout << endl;
        
        return -1;
    }
};
