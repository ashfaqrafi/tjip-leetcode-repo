class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> line;
        int lineSize = 0;
        int current = 0;
        int total_length = words.size();
        vector<string> justified_txt;
        
        while(current < total_length){
            // cout << "current: " << current << endl;
            if(lineSize + (line.size() - 1) + (1 + words[current].size()) <= maxWidth){
                // cout << "build line" << endl;
                lineSize += words[current].size();
                line.push_back(words[current]);
                ++current;
            }else{
                // cout << "flush" << endl;
                //cannot add words into this line anymore
                string str = "";
                if(line.size() == 1){
                    str += line[0];
                    str += string(maxWidth - str.size(), ' ');
                }else{
                    int quot = (maxWidth - lineSize) / (line.size() - 1);
                    int mod = (maxWidth - lineSize) % (line.size() - 1);
                    
                    for(int i = 0; i < line.size(); ++i){
                        str += line[i];
                        if(i != line.size() - 1)
                            str += string(quot + (i < mod), ' ');
                    }
                }
                justified_txt.push_back(str);
                line.clear();
                lineSize = 0;
            }
            // ++current;
        }
        
        //flush the last line
        string str = "";
        //last line must be left-justified
        for(int i = 0; i < line.size(); ++i){
            str += line[i];
            if(i != line.size() - 1) str += " ";
        }
        str += string(maxWidth - str.size(), ' ');
        justified_txt.push_back(str);
        line.clear();
        lineSize = 0;
        
        justified_txt.back() += string(maxWidth-justified_txt.back().size(), ' ');
        
        return justified_txt;
    }
};
