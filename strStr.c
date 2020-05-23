// Brute-Force C
int strStr(char * haystack, char * needle){
    if (!*haystack) {
        if (!*needle) {
            return 0;
        }
        return -1;
    }
    
    char *p1 = haystack, *head = haystack;
    int pos = 0;
    while (*p1) {
        char *p2 = needle;
        while (*p1 && *p2 && *p1 == *p2) {
            ++p1;
            ++p2;
        }
        if (!*p2) {
            return pos;
        }
        p1 = head + (++pos);
    }
    return -1;
}
/**
解题思路：
    双指针跑步，需要注意恢复p1指针
 */

// Brute-Force C++
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.empty()) {
            if (needle.empty()) {
                return 0;
            }
            return -1;
        }
        
        int pos = haystack.find(needle);
        return (pos != string::npos ? pos : -1);
    }
};
/**
解题思路：
    C++有现成的API，所以没什么好说的
 */
