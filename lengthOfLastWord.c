int lengthOfLastWord(char * s){
    if (!s) {
        return 0;
    }
    
    int res = 0;
    int i = 0;
    while (s[i]) {
        if (s[i] != ' ') {
            if (i != 0 && s[i - 1] == ' ') {
                res = 1;
            }
            else {
                res++;
            }
        }
        ++i;
    }
    return res;
}
/**

 */
