class Solution {
public:
    unordered_map<int, int> inorder_indices;
    
    TreeNode* buildTree(vector<int>& preorder, int prestart, int preend, 
        vector<int>& inorder, int instart, int inend){
        //[prestart, preend], [inorder, inend] are inclusive
        if(prestart > preend) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[prestart]);
        
        // int split = find(inorder.begin()+instart, 
        //     inorder.begin()+inend+1, root->val)-inorder.begin();
        int split = inorder_indices[root->val];
        int left_size = split - instart;
        
        root->left = buildTree(preorder, prestart+1, prestart+1+left_size-1, 
                               inorder, instart, split-1);
        
        root->right = buildTree(preorder, prestart+left_size+1, preend, 
                                inorder, split+1, inend);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        for(int i = 0; i < n; ++i){
            inorder_indices[inorder[i]] = i;
        }
        
        return buildTree(preorder, 0, n-1, inorder, 0, n-1);
    }
};
