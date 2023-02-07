class TrieNode {
public:
    vector<TrieNode*> children;
    bool end;
    
    TrieNode(){
        children = vector<TrieNode*>(26, nullptr);
        end = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void add(string& word){
        TrieNode* cur = root;
        for(char c : word){
            if(!cur->children[c-'a']){
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        cur->end = true;
    }
    
    bool find(string word){
        TrieNode* cur = root;
        for(char c : word){
            if(!cur->children[c-'a']){
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return cur->end;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        
        Trie* trie = new Trie();
        
        for(string& word : wordDict){
            trie->add(word);
        }
        
        for(int i = n-1; i >= 0; --i){
            dp[i] = trie->find(s.substr(i));
            
            for(int j = n; j >= i+1; --j){
                dp[i] = dp[j] && trie->find(s.substr(i, j-i));
                if(dp[i]) break;
            }
        }
        
        return dp[0];
    }
};
