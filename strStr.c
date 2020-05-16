// Brute-Force

int strStr(char* haystack, char* needle) {
    if (!*haystack || !*needle) {
        if (!*needle) 
            return 0;
        return -1;
    }

    char* p1 = haystack;
    char* phead = haystack;
    int pos = 0;
    while (*p1) {
        char* p2 = needle;
        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (!*p2) 
            return pos;
        p1 = phead + (++pos);
    }
    return -1;
}
