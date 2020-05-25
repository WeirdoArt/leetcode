class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 1; i < n; ++ i) {
            string temp = "";
            for(int j = 0, count; j < s.size(); ++ j) {
                for(count = 1; j < s.size() && s[j] == s[j + 1]; ++ j, ++count);
                    temp = temp + (char)(count + '0') + s[j];
            }
            s = temp;
        }
        return s;
    }
};
/**
解题思路：

 */
