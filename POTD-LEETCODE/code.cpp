length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2026-08-12


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;
        unordered_map<int,int> mpp;
        for(int right = 0;right<nums.size();right++){
            mpp[nums[right]]++;
            while(mpp[nums[right]] > k){
                mpp[nums[left]]--;
                left++;
                

            }
            ans = max(ans,right-left+1);

        }
        return ans;
        
    }
};

https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0;
        int sum = 0;
        int cnt = 0;
        for(int right = 0;right<arr.size();right++){
            sum = sum +arr[right];
            if(right - left +1 >k){
                sum = sum -arr[left];
                left++;
            }
            if(right-left +1 ==k && sum >= threshold*k){
                cnt++;
            }

        }
        return cnt;
    }
};

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> mpp;
        int left = 0;
        int length =0;
        for(int right = 0;right<s.size();right++){
            mpp[s[right]]++;
            while(mpp[s[right]]>2){
                mpp[s[left]]--;
                left++;
            }
            length = max(length,right-left+1);

        }
        return length;
          
    }
};

only 800 cases https://leetcode.com/problems/find-the-largest-almost-missing-integer/?envType=daily-question&envId=2026-08-18
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int left = 0;
        int n = nums.size();
        int ans = -1;
        if (k == n) {
        

        unordered_map<int, int> cnt;

        for (int right = 0; right < n; right++) {

            if (right - left + 1 > k) {
                left++;
            }

            if (right - left + 1 == k) {

                unordered_map<int, int> mpp;

                // Count frequency in current window
                for (int i = left; i <= right; i++) {
                    mpp[nums[i]]++;
                }

                // Count how many windows contain the number exactly once
                for (auto it : mpp) {
                    if (it.second == 1) {
                        cnt[it.first]++;
                    }
                }
            }
        }

        // Find largest number appearing in exactly one window
        for (auto it : cnt) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};

optimizexd 
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> windowCount;

        // Check every window of size k
        for (int left = 0; left <= n - k; left++) {

            unordered_set<int> seen;

            for (int i = left; i < left + k; i++) {
                seen.insert(nums[i]);
            }

            // Count how many windows contain each number
            for (int x : seen) {
                windowCount[x]++;
            }
        }

        int ans = -1;

        // Number appearing in exactly one window
        for (auto it : windowCount) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};

20 aug 
vector<int> arr1;
vector<int> arr2;

arr1.push_back(nums[0]);
arr2.push_back(nums[1]);

for(int i = 2; i < nums.size(); i++){
    if(arr1.back() > arr2.back()){
        arr1.push_back(nums[i]);
    }
    else{
        arr2.push_back(nums[i]);
    }
    for()
    for()



}

https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/?envType=daily-question&envId=2026-08-22
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int num = n;
        while(n>0){
            sum = sum +n%10;
            product= product*(n%10);
            n =n/10;
             
        }
        int total = sum + product;
        if(num%total == 0){
        return true;}
        return false;
       
        
    }
};

int num = n;  // preserve original

while(n > 0) {
    // modify n
}

// use num for the original number

also use product*(n%10) not product*n%10

kth smallest coin value https://leetcode.com/problems/find-the-kth-smallest-value-of-a-matrix-with-sorted-rows-and-columns/?envType=daily-question&envId=2026-08-23
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        set<long long> ans;
        for(int i=0;i<coins.size();i++){
            for(int j =1;j<k;j++){
                ans.insert(1LL*coins[i]*j);
            }
        }
        int final_coin;
        for(auto it:ans){
            k--;
            if(k==0){
                final_coin=it;
                break;
            }
        }
        return final_coin;
        
    }
};

leetcode 448 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        // unordered_set<int> st;
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(int i = 1;i<=nums.size();i++){
            if(mpp[i] ==0){
                ans.push_back(i);
            }
        }

        // // Put all numbers into set
        // for(int num : nums) {
        //     st.insert(num);
        // }

        // // Check numbers from 1 to n
        // // if x is in set st.find(i) != st.end())
        // for(int i = 1; i <= nums.size(); i++) {
        //     if(st.find(i) == st.end()) { 
        //         ans.push_back(i);
        //     }
        // }

        return ans;
    }
};

optimal is marking -ve to visited number 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size();

        // Mark numbers that appear
        for(int i = 0; i < n; i++) {
            int x = abs(nums[i]);
            nums[x - 1] = -abs(nums[x - 1]);
        }

        // Positive positions are missing
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};

only 609 test cases passed https://leetcode.com/problems/find-the-largest-almost-missing-integer/?envType=daily-question&envId=2026-08-18

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int maxi = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]%k == 0)  maxi = max(maxi,nums[i]);
            
           
           
           
        }
        for(int i =0;i<nums.size();i++){
            if(k == nums[i]){
                return maxi +k;
            }
           
        }
        return k;

        
    }
};

optimal solution just traverse array and put all into map then check multiple present or not 

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]++;

        }
        int multi =k;
        while(mpp.find(multi) != mpp.end()){
            multi = multi+k;
        }
        return multi;
      
       

        
    }
};

it only passed 609 test cases  leetcode.com/problems/shortest-beautiful-substring/?envType=daily-question&envId=2026-08-25
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int mini = 0;
        string ans;

        unordered_map<int,int> mpp;
        for(int right = 0;right<s.size();right++){
            mpp[s[right]]++;
            while(mpp['1'] ==k){
                // int small= right - left +1;
                // mini = min(small,mini);
                // left++;
                ans = s.substr(left,right-left+1);
                mpp[s[left]]--;
                left++;
                


            }

        }
        return ans;
        
    }
};


leetcode 283
here void function so we can not return anything 
we copy the ans vector to nums vector at the end of function
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        vector<int>ans;
        for(int i =0;i<n;i++){
            if(nums[i]!=0){
                ans.push_back(nums[i]);
            }
            else{
                cnt++;
            }
        }
        for(int i=0;i<cnt;i++){
            ans.push_back(0);
        }
        // return ans;
        // kuch return nhi hoga 
        nums = ans;


        
    }
};
optimal solution me jab bhi non zero aye swap krdo left pointer ke sath and left++ krdo
zero ane pe nhi karna swap;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left =0;
        for(int right =0;right<n;right++){
            if(nums[right]!=0){
                swap(nums[right],nums[left]);
                left++;
            }
        }

        
    }
};


2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int first = -1;
        int last = -1;
        int pos = 1;
        int maxd = INT_MIN;
        int mind = INT_MAX;
        while(curr->next != NULL){
            ListNode* front = curr->next;
            if((curr->val > prev->val && curr->val > front->val) || (curr->val < prev->val && curr->val < front->val)){
                if (first == -1) first = pos;
                else{
                    mind = min(mind,pos - last);
                    maxd = max(maxd,pos-first);
                }

                last = pos;
                 
                // prev = curr;
                // curr = front;
                // front = front->next;
                
            }
            // else if(curr->val < prev->val && curr->val < front->val){
                
            //     prev = curr;
            //     curr = front;
            //     front = front->next;
            // }
            prev = curr;
            curr = front;
            pos++;
            

        }
        if (first == -1 || first == last) return {-1, -1};
        return {mind,maxd};
        
    }
};


//potd 3 sep 2026
//take many example then onserve pattern 
// if min element is odd = true always 
// if min element is even and there is one odd in array then false; if all even then true;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = *min_element(nums1.begin(), nums1.end());
        

        // Minimum is even
        if (mini % 2 == 0) {
            for (int num : nums1) {
                if (num % 2 != 0)
                    return false;
            }
            return true;
        }

        // Minimum is odd
        return true;
    }
};

brute force solution 
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = 0;
        for(int i =0;i<n;i++){
            maxi = max(nums[i],maxi);
            int mini = nums[i];
            for(int j =i;j<n;j++){
                
                if(nums[j]<mini){
                    mini = nums[j];
                }
                
            }
            if(maxi - mini <= k){
                return i;
            }
            

        }
        return -1;
        
    }
};