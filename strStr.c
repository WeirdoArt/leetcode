// Brute-Force

int strStr(char* source, char* target)
{
    if (!*source || !*target) {
        if (!*target)
            return 0;
        return -1;
    }

    char *p1 = source, *phead = source;
    int pos = 0;
    while (*p1) {
        char* p2 = target;
        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (!*p2) {
            return pos;
        }
        p1 = phead + (++pos);
    }

    return -1;
}
