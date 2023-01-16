//BFS with queue

//TC: O(N), MC: O(N)

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int level_size = q.size();
            
            Node* prev = nullptr;
            
            while(level_size-- > 0){
                Node* cur = q.front(); q.pop();
                
                if(prev) prev->next = cur;
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                
                prev = cur;
            }
        }
        
        return root;
    }
};
