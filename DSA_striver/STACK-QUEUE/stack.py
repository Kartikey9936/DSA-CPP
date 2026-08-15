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

boolean flag pattern 
bool flag = true;

for (int i = 0; i < n; i++) {

    if (/* condition is violated */) {
        flag = false;
        break;
    }
}

if (flag) {
    // condition was true for every element
}

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_c = 0;
        int n = nums.size();
        if (n == 0) return 0;
        bool allzero = true;
        for(int i =0;i<n;i++){
            xor_c = xor_c^nums[i];
            if(nums[i] != 0){
                allzero = false;
            }
        }
        if(allzero) return 0;
        if(xor_c == 0) return n-1;
        return n;
    }
    
};

