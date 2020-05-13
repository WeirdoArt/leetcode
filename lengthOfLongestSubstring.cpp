// Brute Force
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                if(allUnique(s, i, j)) {
                    ans = ans > j - i ? ans : j - i;
                }
            }
        }
        return ans;
    }
    
    bool allUnique(string str, int start, int end) {
        set<char> s;
        int n = 0;
        for(int i = start; i < end; ++i) {
            char ch = str[i];
            if(s.find(ch) != s.end()) {
                return false;
            }
            s.insert(ch);
        }
        return true;
    }
};
