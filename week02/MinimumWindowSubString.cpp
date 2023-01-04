class Solution {
public:
    string minWindow(string s, string t) {
      map <char, int> m;
      for(int i = 0;i < t.size(); i++) m[t[i]]++;
      int length = s.size();
      int left = 0, right = 0 , ansLeft = 0, ansRight = 0;
      int counter = t.size();
      bool flag = false;
      string minWinSubStr = "";
      while(right <s.size()){
         char c = s[right];
         if(m.find(c)!= m.end()){
            if(m[c] > 0) counter--;
            m[c]--;
         }
         while(counter == 0 && left <= right){
            if(right - left + 1 <= length){
               length = right -left + 1;
               flag = true;
               ansLeft = left;
               ansRight = right;
            }
            if(left == right)break;
            c = s[left];
            if(m.find(c)!= m.end()){
               m[c]++;
               if(m[c] > 0) counter++;
            }
            left++;
         }
         right++;
      }
      if(!flag)return minWinSubStr;
      else
      for(int i = ansLeft; i <= ansRight; i++) minWinSubStr += s[i];
      return minWinSubStr;
    }
};
