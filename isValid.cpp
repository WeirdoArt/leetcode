// Approach 1: Stacks
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        if (s.length() == 0) {
            return true;
        }
        if (s.length() == 1) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(c == '}' || c == ')' || c == ']') {
                if (stack.empty()) return false;
                if (c == '}' && stack.top() != '{') return false;
                if (c == ')' && stack.top() != '(') return false;
                if (c == ']' && stack.top() != '[') return false;
                stack.pop();
            } 
            else {
                stack.push(c);
            }
        }
        if(stack.empty()) {
            return true;
        }
        return false;
    }
};
/**
解题思路：
    关键点：利用栈的特性
    既然是找有效的匹配，那肯定得找到“对应”的右括号才算有效，所以在迭代过程中如果是左括号就都压栈，
    同时在迭代过程中如果遇到“任何”一个右括号就去看是否与栈顶元素相“对应”，如果为真就弹栈否则直接返回false，
    最后检查栈是否为空，如果为空表示全部匹配返回true，否则就是有左括号未匹配到对应的右括号返回false；
 */

// Approach 2: Stacks && map
class Solution {
public:
    bool isValid(string s) {
        map<char, char> map({
            pair<char, char>(')', '('), 
            pair<char, char>('}', '{'), 
            pair<char, char>(']', '[')
        });
        stack<char> stack;

        if (s.length() == 0) {
            return true;
        }
        if (s.length() == 1) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(map.find(c) != map.end()) {
                if (stack.empty() || stack.top() != map.find(c)->second) {
                    return false;
                }
                stack.pop();
            } 
            else {
                stack.push(c);
            }
        }
        if(stack.empty()) {
            return true;
        }
        return false;
    }
};
/**
解题思路：
    此方法与以上方法思路一样，只不过加入了map方便操作，代码也更易读。
 */
