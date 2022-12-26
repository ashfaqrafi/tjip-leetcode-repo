//Horizontal scanning
//time: O(S), where S is the sum of all characters in all strings.
//space: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int stringLength = strs.size();
        if(stringLength == 0) return "";
        int LCP = INT_MAX;
        for(int i = 0; i < stringLength -1; i++){
            LCP = min(LCP, (int)min(strs[i].size(), strs[i+1].size()));
            while(strs[i].substr(0, LCP) != strs[i+1].substr(0, LCP)){
                LCP--;
            }
            if(LCP == 0)return "";
        }
        return strs[0].substr(0, LCP);
    }
};
