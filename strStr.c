// Brute-Force

int strStr(char * haystack, char * needle){
    if(!*haystack) {
        return -1;
    }
    
    char *p1 = haystack;
    int pos = 0;
    while(*p1) {
        char * p2 = needle;
        while(*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }
        if(!*p2) {
            return pos;
        }
        pos++;
    }
    return -1;
}
