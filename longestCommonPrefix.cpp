// Approach 1: Horizontal scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) { // 遍历vector
            string compstr = strs[i];
            int idx = 0;
            while (idx < compstr.size()) { // 遍历每个字符串
                if (prefix[idx] != compstr[idx]) {
                    prefix = prefix.substr(0, idx);
                    break;
                }
                ++idx;
            }
            if (idx == compstr.size()) {
                prefix = compstr;
            }
        }
        return prefix;
    }
};
/**
解题思路：
    横向扫描就是用第一个字符串和下一个字符串找公共前缀，然后再用找到的公共前缀依次和剩下的字符串去找，以此类推
 */

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
/**
解题思路：
    纵向扫描，以第一个字符串为基准去扫描剩余字符串，依次比较第一个字符串与剩余字符串的每一个字符，
    需要注意边界条件，遍历第一个字符串的索引不应该超过剩余字符串的长度，当相等的时候说明在此之前全部相等
    以下是更精简的代码
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
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

// Approach 3: Divide and conquer
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs.size() == 0) {
            return "";
        }
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
    
    string longestCommonPrefix(vector<string>& strs, int lLen, int rLen) {
        if (lLen == rLen) {
            return strs[lLen];
        }
        else {
            int mid = (lLen + rLen) / 2;
            string lStr = longestCommonPrefix(strs, lLen, mid);
            string rStr = longestCommonPrefix(strs, mid + 1, rLen);
            return commonPrefix(lStr, rStr);
        }
    }
    
    string commonPrefix(string lStr, string rStr) {
        int minLen = min(lStr.size(), rStr.size());
        for (int i = 0; i < minLen; ++i) {
            if (lStr[i] != rStr[i]) {
                return lStr.substr(0, i);
            }
        }
        return lStr.substr(0, minLen);
    }
};
/**
解题思路：(我对递归还是一知半解)
    利用递归分而治之的思想考虑横向扫描的方法
 */
