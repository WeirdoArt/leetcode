// Brute-Force

int strStr(char * haystack, char * needle){
    if(!*haystack || !*needle || strlen(haystack) < strlen(needle)) {
        return -1;
    }
    
    char *p1 = haystack;
    int pos = 0;
    while(pos < strlen(haystack) && *p1) {
        char * p2 = needle;
        while(*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }
        if(!*p2) {
            return pos;
        }
        p1 = p1[++pos];
    }
    return -1;
}
