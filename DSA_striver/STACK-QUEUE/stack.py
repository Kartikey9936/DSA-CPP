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

https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
        
    }
    
    int pop() {
      int x = s1.top();
      s1.pop();
      return x; 
        
    }
       
    int peek() {
       return  s1.top();
        
    }
    
    bool empty() {
        return s1.empty();

        
    }
};









class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;

        for (int i = 0; i < nums1.size(); i++) {

            for (int j = 0; j < nums2.size(); j++) {

                if (nums1[i] == nums2[j]) {

                    bool found = false;

                    for (int k = j + 1; k < nums2.size(); k++) {

                        if (nums2[k] > nums2[j]) {
                            v.push_back(nums2[k]);
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        v.push_back(-1);
                    }

                    break;
                }
            }
        }

        return v;
    }
};


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        for(int i =0;i<n;i++){
            ans.push_back(asteroids[i]);
            if(asteroids[i]<0){
                for(int j = i-1;j>=0;j--){
                    if(ans.back()<0 && abs(asteroids[j])>ans.back()){
                        ans.pop_back();
                        ans.push_back(asteroids[j] - ans.back());

                    }

                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
            else if (asteroids[i] < 0) {
                while(!st.empty() && st.top()>0 && st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroids[i])){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }
                
            }
            
            // else if(asteroids[i] < 0 && abs(asteroids[i])== st.top()){
            //     st.pop();
            // }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};



