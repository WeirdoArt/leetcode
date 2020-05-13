// Approach 1: Brute Force
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


// Approach 2: Sliding Window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char>hashset;
        int ans = 0, i = 0, j = 0;
        while(i < n && j < n) {
            if(hashset.find(s[j]) == hashset.end()) {
                hashset.insert(s[j++]);
                ans = ans > j - i ? ans : j - i;
            }
            else {
                hashset.erase(s[i++]);
            }
        }
        return ans;
    }
};

// Approach 3: Sliding Window Optimized
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, int>hashmap;
        int ans = 0;
        for(int i = 0, j = 0; j < n; j++) { 
            auto tmp = hashmap.find(s[j]);
            if(tmp != hashmap.end()) {
                i = max(tmp->second, i); // 1
            }
            ans = max(ans, j - i + 1);
            hashmap[s[j]] = j + 1;
        }
        return ans;
    }
};

// replace the Map with an integer array as direct access table.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int index[128] = {0};
        for(int i = 0, j = 0; j < n; j++) { // n=7
            i = max(index[s[j]], i);
            ans = max(ans, j - i + 1);
            index[s[j]] = j + 1;
        }
        return ans;
    }
};
