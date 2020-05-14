// Approach 1: Horizontal scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        
        int min = strs[0].size();
        for(int i = 1; i < strs.size(); ++i) {
            min = min < strs[i].size() ? min : strs[i].size();
        }
        
        string ret;
        for(int i = 0; i < min; ++i) {
            char ch = strs[0][i];
            for(int j = 0; j < strs.size(); ++j) {
                if(ch != strs[j][i]) {
                    return ret;
                }
            }
            ret.push_back(ch);
        }
        return ret;
    }
};
