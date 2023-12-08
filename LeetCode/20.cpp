class Solution {
public:
    bool isValid(string s) {
        int i;
        stack <char> parentheses;
        for(i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') parentheses.push(s[i]);
            else if(parentheses.empty() || (s[i]==')' && parentheses.top()!='(') || (s[i]=='}' && parentheses.top()!='{') || (s[i]==']' && parentheses.top()!='[')) return false;
            
            else parentheses.pop();;
        }
        if(parentheses.empty()) return true;
        else return false;
    }
};
