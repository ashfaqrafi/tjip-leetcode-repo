//time: O(NKlogK), space: O(NK), K is the maximum length of string in "strs"

struct RetrieveValue
{   
    template <typename T>
    typename T::second_type operator()(T keyValuePair) const
    {   
        return keyValuePair.second;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for(string& str : strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            groups[sorted].push_back(str);
        }
        
        vector<vector<string>> final_anagram;
        transform(groups.begin(), groups.end(), back_inserter(final_anagram), RetrieveValue());
        
        return final_anagram;
    }
};
