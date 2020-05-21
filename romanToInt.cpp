// 
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> map({
            pair<char, int>('I', 1),
            pair<char, int>('V', 5),
            pair<char, int>('X', 10),
            pair<char, int>('L', 50),
            pair<char, int>('C', 100),
            pair<char, int>('D', 500),
            pair<char, int>('M', 1000)
        });
    
        int res = 0, prev = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            auto curr = map.find(s[i]);
            if (curr != map.end()) {
                if (curr->second >= prev) {
                    res += curr->second;
                }
                else {
                    res -= curr->second;
                }
            }
            prev = curr->second;
        }
        return res;
    }
};
/**
解题思路：
    关键点1：罗马数字的定义
    关键点2：从小到大解析（从右到左）
    先搞清楚罗马数字的定义！要“从小到大”去解析罗马数字符串s，“从大到小”会很麻烦（需要同时处理3位数），
    直接从后往前算，就不用考虑那么多规则，除了小在大前面要用大减小之外，其他就累加。
 */
