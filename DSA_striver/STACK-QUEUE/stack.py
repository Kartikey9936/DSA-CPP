class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        if(s.size()== 1) return false;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;     //imp edge case because if we have closing bracket at the start then it will return false
                }
                if((s[i] == ')' && st.top() == '(') ||
                  (s[i] == ']' && st.top() == '[') ||
                  (s[i] == '}' && st.top() == '{')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        
        }
        # if (st.empty())
        #  return true;
        # else
        # return false; iskki jagah ye bhi shi h 
        return st.empty();
        
        
        
    }
};

