int lengthOfLastWord(char * s){
    if (!s) {
        return 0;
    }
    
    int res = 0;
    int i = 0;
    while (s[i]) {
        if (s[i] != ' ') {
            if (i != 0 && s[i - 1] == ' ') { // 如果上一个是空格就还原计数器
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
解题思路：
    遍历字符串，空格字符是单词结束的标志，那就找非空格字符，找到就判断一下上一个字符是否是空格（也就是判断是否为单词开始），
    如果是开始就还原计数器，否则就自增计数器，注意控制边界（i != 0 表示不能为字符串的开始，否则会越界）
 */