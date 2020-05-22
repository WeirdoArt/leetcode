// Approach 1: Horizontal scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        string cache;
        for (int i = 0; i < strs[0].size(); ++i) {
            auto ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i == strs[j].size() || ch != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

// Approach 2: Vertical scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        
        // 找出最短的字符串的长度
        int min = strs[0].size();
        for(int i = 1; i < strs.size(); ++i) {
            min = min < strs[i].size() ? min : strs[i].size();
        }
        
        string ret;
        for(int i = 0; i < min; ++i) { 
            char ch = strs[0][i]; // 遍历第一个串的每个字符
            for(int j = 0; j < strs.size(); ++j) { // 遍历每个串
                if(ch != strs[j][i]) { // 依次用每个串的每个字符与第一个串的每个字符进行比较
                    return ret; // 不相等就立即返回buf
                }
            }
            ret.push_back(ch); // 相等的情况下将当前字符加入buf
        }
        return ret;
    }
};

/*
总结：不要想着一口吃成个大胖子，要懂得把问题拆解开，首先需要知道最小的需要遍历的边界，所以要找到最短的字符串，
    然后要懂得换个视角，遍历vector去依次分别比较每个串的每一个字符，而不是挨个遍历每个串依次比较每个字符
*/
